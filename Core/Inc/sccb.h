/**
  ******************************************************************************
  * @file    sccb.h
  * @author  ZhuSL
  * @brief   sccb通讯头文件
  *
  ******************************************************************************
  */

#ifndef _SCCB_H_
#define _SCCB_H_

#include "stm32f0xx_hal.h"

#define SCCB_SCL_GPIO_PORT					GPIOA
#define SCCB_SCL_GPIO_PIN						GPIO_PIN_9
#define SCCB_SCL_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()
#define SCCB_SCL_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()
#define SCCB_SCL_GPIO_WRITE(state)	HAL_GPIO_WritePin(SCCB_SCL_GPIO_PORT, SCCB_SCL_GPIO_PIN, (state == GPIO_PIN_RESET)?(GPIO_PIN_RESET):(GPIO_PIN_SET));


#define SCCB_SDA_GPIO_PORT					GPIOA
#define SCCB_SDA_GPIO_PIN						GPIO_PIN_10
#define SCCB_SDA_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()
#define SCCB_SDA_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()
#define SCCB_SDA_GPIO_WRITE(state)	HAL_GPIO_WritePin(SCCB_SDA_GPIO_PORT, SCCB_SDA_GPIO_PIN, (state == GPIO_PIN_RESET)?(GPIO_PIN_RESET):(GPIO_PIN_SET));
#define SCCB_SDA_GPIO_READ					HAL_GPIO_ReadPin(SCCB_SDA_GPIO_PORT, SCCB_SDA_GPIO_PIN)


typedef enum
{
	SCCB_False = 0U,
	SCCB_True = !SCCB_False
} SCCB_BoolTypeDef;


void SCCB_Init(void);
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
SCCB_BoolTypeDef SCCB_WR_Byte(uint8_t Data);
uint8_t SCCB_RD_Byte(void);

#endif
