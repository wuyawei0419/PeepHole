/**
  ******************************************************************************
  * @file    powermanager.c
  * @author  ZhuSL
  * @brief   电源管理
  *
  ******************************************************************************
  * @attention
  *		None
  *
  ******************************************************************************
  */

#include "powermanager.h"
#include "main.h"



struct {
	FlagStatus EnterFlag;	/*如果此位置位，则进入睡眠*/
	volatile uint32_t Counter;	/*计数器*/
} PowerManager = {.EnterFlag = RESET, .Counter = 0};





/**
  * @brief  电源管理主任务，循环调用
  * @param  None
  * @retval None
  */
void PowerManager_Task(void)
{
	if(PowerManager.Counter >= POWERMANAGER_ENTER_TIMEOUT)
	{
		PowerManager.EnterFlag = SET;
	}



	if(PowerManager.EnterFlag == SET)
	{
		
	}
}




/**
  * @brief  电源管理的心跳计数
  * @param  None
  * @retval None
  */
void PowerManager_Tick_CallBack(void)
{
	PowerManager.Counter++;
}







/**
  * @brief  system sleep
  * @param  None
  * @retval None
  */
void System_Sleep(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ~(GPIO_PIN_13 | GPIO_PIN_14);
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);		

	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	SystemClock_Config();
}




