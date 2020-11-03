/**
  ******************************************************************************
  * @file    sccb.c
  * @author  ZhuSL
  * @brief   sccb通讯头文件
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sccb.h"


static void SCCB_Delay(void);
static void SCCB_SDA_IN(void);
static void SCCB_SDA_OUT(void);


/**
  * @brief  初始化SCCB
  * @param  None
  * @retval None
  */
void SCCB_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	SCCB_SCL_GPIO_CLK_ENABLE();
	SCCB_SDA_GPIO_CLK_ENABLE();
	
	/*初始化SCCB_SCL引脚*/
	GPIO_Initure.Pin = SCCB_SCL_GPIO_PIN;				/*SCL pin号*/
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_OD;		/*开漏输出*/
	GPIO_Initure.Pull = GPIO_PULLUP;						/*上拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(SCCB_SCL_GPIO_PORT, &GPIO_Initure);
	
	/*初始化SCCB_SDA引脚*/
	GPIO_Initure.Pin = SCCB_SDA_GPIO_PIN;				/*SDA pin号*/
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_OD;		/*开漏输出*/
	GPIO_Initure.Pull = GPIO_PULLUP;						/*上拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(SCCB_SDA_GPIO_PORT, &GPIO_Initure);
}


/**
  * @brief  SCCB起始信号
	*	@note		在时钟为高的时候，数据线由高到低，为SCCB起始信号
	*					在激活状态下，SDA和SCL均为低电平
  * @param  None
  * @retval None
  */
void SCCB_Start(void)
{
	SCCB_SDA_GPIO_WRITE(1);	/*数据线高电平*/
	SCCB_SCL_GPIO_WRITE(1);	/*在时钟线高的时候数据线由高到低*/
	SCCB_Delay();
	SCCB_SDA_GPIO_WRITE(0);
	SCCB_Delay();
	SCCB_SCL_GPIO_WRITE(0);	/*数据线恢复至低电平，单操作函数必要*/
}


/**
  * @brief  SCCB停止信号
	*	@note		在时钟为高的时候，数据线由低到高，为SCCB停止信号
	*					空闲状态下，SDA、SCL均为高电平
  * @param  None
  * @retval None
  */
void SCCB_Stop(void)
{
	SCCB_SDA_GPIO_WRITE(0);
	SCCB_Delay();
	SCCB_SCL_GPIO_WRITE(1);
	SCCB_Delay();
	SCCB_SDA_GPIO_WRITE(1);
	SCCB_Delay();
}


/**
  * @brief  产生NA信号
  * @param  None
  * @retval None
  */
void SCCB_No_Ack(void)
{
	SCCB_Delay();
	SCCB_SDA_GPIO_WRITE(1);	
	SCCB_SCL_GPIO_WRITE(1);	
	SCCB_Delay();
	SCCB_SCL_GPIO_WRITE(0);	
	SCCB_Delay();
	SCCB_SDA_GPIO_WRITE(0);	
	SCCB_Delay();	
}


/**
  * @brief  SCCB,写入一个字节
  * @param  Data：写入八位的数据
  * @retval	成功或失败
	*		#SCCB_True：成功
	*		#SCCB_False：失败
  */
SCCB_BoolTypeDef SCCB_WR_Byte(uint8_t Data)
{
	uint8_t j;
	SCCB_BoolTypeDef res;
	
	for(j=0; j<8; j++)
	{
		if(Data&0x80)
		{
			SCCB_SDA_GPIO_WRITE(1);
		}
		else
		{
			SCCB_SDA_GPIO_WRITE(0);
		}
		Data<<=1;
		SCCB_Delay();
		SCCB_SCL_GPIO_WRITE(1);	
		SCCB_Delay();
		SCCB_SCL_GPIO_WRITE(0);		   
	}
	SCCB_SDA_IN();	/*设置SDA为输入 */
	SCCB_Delay();
	SCCB_SCL_GPIO_WRITE(1);	/*接收第九位,以判断是否发送成功*/
	SCCB_Delay();
	if(SCCB_SDA_GPIO_READ)
	{
		res = SCCB_False;
	}
	else
	{
		res = SCCB_True;
	}
	SCCB_SCL_GPIO_WRITE(0);		 
	SCCB_SDA_OUT();	/*设置SDA为输出*/
	return res;  
}


/**
  * @brief  SCCB 读取一个字节,在SCL的上升沿,数据锁存
  * @param  None
  * @retval	返回八位读取到的数据
  */
uint8_t SCCB_RD_Byte(void)
{
	uint8_t temp = 0, j;    
	SCCB_SDA_IN();	/*设置SDA为输入*/
	for(j=8; j>0; j--)	/*循环8次接收数据*/
	{		     	  
		SCCB_Delay();
		SCCB_SCL_GPIO_WRITE(1);
		temp=temp<<1;
		if(SCCB_SDA_GPIO_READ)temp++;   
		SCCB_Delay();
		SCCB_SCL_GPIO_WRITE(0);
	}
	
	SCCB_SDA_OUT();	/*设置SDA为输出*/
	
	return temp;
}


/**
  * @brief  延时
  * @param  None
  * @retval None
	*	@note		IIC延时函数，实际测试约为12us
  */
static void SCCB_Delay(void)
{
	volatile uint8_t i;
	
	for(i=0;i<50;i++);	
}


static void SCCB_SDA_IN(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	SCCB_SDA_GPIO_CLK_ENABLE();
	
	/*初始化SCCB_SDA引脚*/
	GPIO_Initure.Pin = SCCB_SDA_GPIO_PIN;				/*SDA pin号*/
	GPIO_Initure.Mode = GPIO_MODE_INPUT;				/*输入*/
	GPIO_Initure.Pull = GPIO_NOPULL;						/*上拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(SCCB_SDA_GPIO_PORT, &GPIO_Initure);		
}


static void SCCB_SDA_OUT(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	SCCB_SDA_GPIO_CLK_ENABLE();
	
	/*初始化SCCB_SDA引脚*/
	GPIO_Initure.Pin = SCCB_SDA_GPIO_PIN;				/*SDA pin号*/
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_OD;		/*开漏输出*/
	GPIO_Initure.Pull = GPIO_PULLUP;						/*上拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(SCCB_SDA_GPIO_PORT, &GPIO_Initure);	
}





