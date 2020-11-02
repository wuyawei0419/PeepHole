/**
  ******************************************************************************
  * @file    peephole.c
  * @author  ZhuSL
  * @brief   功能整合：LCD TFT+OV摄像头+N74LVC1G125+N74LVC1G08+N74LVC245
  *
  ******************************************************************************
  */
	
#include "peephole.h"


/**
  * @brief  初始化PeepHole GPIO
  * @param  None
  * @retval None
  */
void PeepHole_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	SN74LV125_OE_GPIO_CLK_ENABLE();
	SN74LV245_OE_GPIO_CLK_ENABLE();
	OV_VSYNC_GPIO_CLK_ENABLE();
	POWER_GPIO_CLK_ENABLE();
	
	GPIO_Initure.Pin = SN74LV125_OE_GPIO_PIN;				/*pin号*/
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;		/*推挽输出*/
	GPIO_Initure.Pull = GPIO_NOPULL;						/*无上下拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(SN74LV125_OE_GPIO_PORT, &GPIO_Initure);
	
	GPIO_Initure.Pin = SN74LV245_OE_GPIO_PIN;				/*pin号*/
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;		/*推挽输出*/
	GPIO_Initure.Pull = GPIO_NOPULL;						/*无上下拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(SN74LV245_OE_GPIO_PORT, &GPIO_Initure);

	GPIO_Initure.Pin = POWER_GPIO_PIN;				/*pin号*/
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;		/*推挽输出*/
	GPIO_Initure.Pull = GPIO_NOPULL;						/*无上下拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(POWER_GPIO_PORT, &GPIO_Initure);
	
	GPIO_Initure.Pin = OV_VSYNC_GPIO_PIN;				/*pin号*/
	GPIO_Initure.Mode = GPIO_MODE_IT_RISING;		/*外部中断*/
	GPIO_Initure.Pull = GPIO_NOPULL;						/*无上下拉*/
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;	/*高速*/
	HAL_GPIO_Init(OV_VSYNC_GPIO_PORT, &GPIO_Initure);
  HAL_NVIC_SetPriority(OV_VSYNC_GPIO_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(OV_VSYNC_GPIO_IRQn);
}


/**
  * @brief  运行PeepHole
  * @param  None
  * @retval None
  */
void PeepHole_Run(void)
{
	
}


/**
  * @brief  停止PeepHole
  * @param  None
  * @retval None
  */
void PeepHole_Stop(void)
{
	
}


/**
  * @brief  SN74LVC1G125DBVR 芯片上的OE引脚
  * @param  State:开启或关闭
	*		#ENABLE:使能
	*		#DISABLE:失能
	*	@note		该引脚低电平有效，当低电平时，125芯片的Y输出取决于A，当高电平时，Y为高阻抗断开
  * @retval None
  */
void PeepHole_LCD_WR_Control(FunctionalState State)
{	
	switch(State)
	{
		case ENABLE:
			SN74LV125_OE_GPIO_WRITE(GPIO_PIN_RESET);
			break;
		case DISABLE:
			SN74LV125_OE_GPIO_WRITE(GPIO_PIN_SET);
			break;
		default:
			break;
	}
}


/**
  * @brief  SN74LVC245APWR 芯片上的OE引脚
  * @param  State:开启或关闭
	*		#ENABLE:使能
	*		#DISABLE:失能
	*	@note		该引脚低电平有效，当低电平时，LCD的data数据来源于OV，当高电平时，LCD与OV断开，只与MCU连接
  * @retval None
  */
void PeepHole_OV_2_LCD_Control(FunctionalState State)
{	
	switch(State)
	{
		case ENABLE:
			SN74LV245_OE_GPIO_WRITE(GPIO_PIN_RESET);
			break;
		case DISABLE:
			SN74LV245_OE_GPIO_WRITE(GPIO_PIN_SET);
			break;
		default:
			break;
	}
}


/**
  * @brief  控制摄像头、LCD、三个74芯片的电源
  * @param  State:开启或关闭
	*		#ENABLE:使能
	*		#DISABLE:失能
  * @retval None
  */
void PeepHole_Power_Control(FunctionalState State)
{	
	switch(State)
	{
		case ENABLE:
			POWER_GPIO_WRITE(GPIO_PIN_RESET);
			break;
		case DISABLE:
			POWER_GPIO_WRITE(GPIO_PIN_SET);
			break;
		default:
			break;
	}
}


/**
  * @brief  OV摄像头帧同步信号中断回调
  * @param  None
  * @retval None
  */
void PeepHole_OV_VSYNC_EXTI_Callback(void)
{
	
}


