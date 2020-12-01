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












