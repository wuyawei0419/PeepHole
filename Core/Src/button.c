/**
  ******************************************************************************
  * @file    button.c
  * @author  ZhuSL
  * @brief   按键应用
  *
  ******************************************************************************
  * @attention
  *		None
  *
  ******************************************************************************
  */

#include "stm32f0xx_hal.h"
#include "button.h"



#include "peephole.h"
//#include "ili9486.h"
#include "ili9341.h"
#include "ov7670.h"
#include "button.h"




/*心跳计数*/
volatile uint8_t BUTTON_COUNTER = 0;

ButtonHandler_TypeDef Button_User;
ButtonHandler_TypeDef Button_MCU;




/**
  * @brief  初始化按键驱动
  * @param  None
  * @retval None
  */
void Button_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	BUTTON_USER_GPIO_CLK_ENABLE();
	BUTTON_MCU_GPIO_CLK_ENABLE();

	GPIO_Initure.Pin = BUTTON_USER_GPIO_PIN;
	GPIO_Initure.Pull=GPIO_PULLUP;											//上拉
	GPIO_Initure.Mode=GPIO_MODE_IT_FALLING;     				//下降沿触发
	GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    				//高速
	HAL_GPIO_Init(BUTTON_USER_GPIO_PORT,&GPIO_Initure);



	GPIO_Initure.Pin = BUTTON_MCU_GPIO_PIN;
	GPIO_Initure.Pull=GPIO_PULLUP;											//上拉
	GPIO_Initure.Mode=GPIO_MODE_IT_FALLING;     				//下降沿触发
	GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    				//高速
	HAL_GPIO_Init(BUTTON_MCU_GPIO_PORT,&GPIO_Initure);

  HAL_NVIC_SetPriority(BUTTON_USER_GPIO_IRQn, 3, 0);
  HAL_NVIC_SetPriority(BUTTON_MCU_GPIO_IRQn, 3, 0);

  HAL_NVIC_EnableIRQ(BUTTON_USER_GPIO_IRQn);
  HAL_NVIC_EnableIRQ(BUTTON_MCU_GPIO_IRQn);

  Button_User.Counter = 0;
  Button_User.ScanFlag = RESET;
  Button_User.Status = Button_Null;

  Button_MCU.Counter = 0;
  Button_MCU.ScanFlag = RESET;
  Button_MCU.Status = Button_Null;  
}




/**
  * @brief  按键心跳计数
  * @param  None
  * @retval None
  */
void Button_Tick_CallBack(void)
{
	BUTTON_COUNTER++;
	if(BUTTON_COUNTER >= BUTTON_TICK_PERIOD_VALUE)
	{
		Button_Scan_CallBack();
		BUTTON_COUNTER = 0;
	}
}


/**
  * @brief  按键线中断回调函数
  * @param  GPIO_Pin
  *		#BUTTON_USER_GPIO_PIN
  *		#BUTTON_MCU_GPIO_PIN
  * @retval None
  */
void Button_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == BUTTON_USER_GPIO_PIN)
	{
		Button_User.ScanFlag = SET;
		Button_User.Counter = 0;
		Button_User.Status = Button_Null;
	}
	else if(GPIO_Pin == BUTTON_MCU_GPIO_PIN)
	{
		Button_MCU.ScanFlag = SET;
		Button_MCU.Counter = 0;
		Button_MCU.Status = Button_Null;
	}
}



/**
  * @brief  按键扫描回调函数，当发生线中断时调用此函数
  * @param  None
  * @retval None
  */
void Button_Scan_CallBack(void)
{
	if(Button_User.ScanFlag == SET)
	{
		if(HAL_GPIO_ReadPin(BUTTON_USER_GPIO_PORT, BUTTON_USER_GPIO_PIN) == RESET)
		{
			Button_User.Counter++;
			if(Button_User.Counter >= BUTTON_PRESS_HOLD_MIN_VALUE)
			{
				Button_User.Status = Button_Press_Hold;
				Button_User.ScanFlag = RESET;
				Button_User.Counter = 0;
			}			
		}
		else
		{
			if(Button_User.Counter <= BUTTON_PRESS_MAX_VALUE)
			{
				Button_User.Status = Button_Press;
			}
			else if(Button_User.Counter >= BUTTON_PRESS_HOLD_MIN_VALUE)
			{
				Button_User.Status = Button_Press_Hold;
			}
			else
			{
				Button_User.Status = Button_Null;
			}
			Button_User.ScanFlag = RESET;
			Button_User.Counter = 0;
		}
	}

	if(Button_MCU.ScanFlag == SET)
	{
		if(HAL_GPIO_ReadPin(BUTTON_USER_GPIO_PORT, BUTTON_USER_GPIO_PIN) == RESET)
		{
			Button_MCU.Counter++;
			if(Button_MCU.Counter >= BUTTON_PRESS_HOLD_MIN_VALUE)
			{
				Button_MCU.Status = Button_Press_Hold;
				Button_MCU.ScanFlag = RESET;
				Button_MCU.Counter = 0;
			}						
		}
		else
		{
			if(Button_MCU.Counter <= BUTTON_PRESS_MAX_VALUE)
			{
				Button_MCU.Status = Button_Press;
			}
			else if(Button_MCU.Counter >= BUTTON_PRESS_HOLD_MIN_VALUE)
			{
				Button_MCU.Status = Button_Press_Hold;
			}
			else
			{
				Button_MCU.Status = Button_Null;
			}
			Button_MCU.ScanFlag = RESET;
			Button_MCU.Counter = 0;
		}
	}	
}



/**
  * @brief  获取任何按键的有效键值
  * @param  None
  * @retval 键值类型
  *		#Button_Null:无键值
  *		#Button_Press_Hold:长按
  *		#Button_Press:短按
  */
ButtonStatus_TypeDef Button_GetStatus(void)
{
	ButtonStatus_TypeDef temp = Button_Null;
	
	if(Button_User.Status != Button_Null)
	{
		temp = Button_User.Status;
		Button_User.Status = Button_Null;
	}
	else if(Button_MCU.Status != Button_Null)
	{
		temp = Button_MCU.Status;
		Button_MCU.Status = Button_Null;
	}

	return temp;	
}


/**
  * @brief  应用层主函数，循环调用
  * @param  None
  * @retval None
  */
void Button_Task(void)
{
	ButtonStatus_TypeDef button_status = Button_Null;

	button_status = Button_GetStatus();
	if(button_status == Button_Press)
	{
		PeepHole_Init();
		PeepHole_Power_Control(ENABLE);

		ILI9341_Board_Init();
		ILI9341_APP_Init();
		ILI9341_ClearScreen(ILI9341_COLOR_WHITE);		
		ILI9341_DataPort_IN();
		
		OV7670_Init();

		PeepHole_OV_2_LCD_Control(ENABLE);
		PeepHole_LCD_WR_Control(ENABLE);	
		PeepHole_EXTI_Control(ENABLE);		
	}
	else if(button_status == Button_Press_Hold)
	{
		PeepHole_Power_Control(DISABLE);

		PeepHole_OV_2_LCD_Control(DISABLE);
		PeepHole_LCD_WR_Control(DISABLE);	
		PeepHole_EXTI_Control(DISABLE);		
	}
}


