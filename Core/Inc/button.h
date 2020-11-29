/**
  ******************************************************************************
  * @file    button.h
  * @author  ZhuSL
  * @brief   按键应用
  *
  ******************************************************************************
  * @attention
  *		None
  *
  ******************************************************************************
  */

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "stm32f0xx_hal.h"


#define BUTTON_USER_GPIO_PORT						GPIOB
#define BUTTON_USER_GPIO_PIN						GPIO_PIN_4
#define BUTTON_USER_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()  
#define BUTTON_USER_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOB_CLK_DISABLE()
#define BUTTON_USER_GPIO_IRQn						EXTI4_15_IRQn

#define BUTTON_MCU_GPIO_PORT						GPIOB
#define BUTTON_MCU_GPIO_PIN							GPIO_PIN_5
#define BUTTON_MCU_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()  
#define BUTTON_MCU_GPIO_CLK_DISABLE()		__HAL_RCC_GPIOB_CLK_DISABLE()
#define BUTTON_MCU_GPIO_IRQn						EXTI4_15_IRQn

/*心跳周期，单位ms*/
#define BUTTON_TICK_PERIOD_VALUE	(20u)
/*结束扫描时，当计数值不超过这个时则为短按，单位为BUTTON_TICK_PERIOD_VALUE*/
#define BUTTON_PRESS_MAX_VALUE		(25u)
/*结束扫描时，当计数值超过这个时则为长按，单位为BUTTON_TICK_PERIOD_VALUE*/
#define BUTTON_PRESS_HOLD_MIN_VALUE		(50u)



/*按键动作定义*/
typedef enum
{
	Button_Null,					/*无*/
	Button_Press,					/*短按*/
	Button_Press_Hold			/*长按*/
} ButtonStatus_TypeDef;


/*按键句柄*/
typedef struct
{
	volatile ButtonStatus_TypeDef Status;	/*按键的状态*/
	volatile FlagStatus ScanFlag;					/*是否扫描标志位*/
	volatile uint16_t Counter;
} ButtonHandler_TypeDef;









void Button_Init(void);
void Button_Tick_CallBack(void);
void Button_EXTI_Callback(uint16_t GPIO_Pin);
void Button_Scan_CallBack(void);
ButtonStatus_TypeDef Button_GetStatus(void);
void Button_Task(void);




#endif

