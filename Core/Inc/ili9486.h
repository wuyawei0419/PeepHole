/**
  ******************************************************************************
  * @file    ili9486.h
  * @author  ZhuSL
  * @brief   ili9486 driver
  *
  ******************************************************************************
  * @attention
  *		None
  *
  ******************************************************************************
  */
	
#ifndef _ILI9486_H_
#define _ILI9486_H_

#include "stm32f0xx_hal.h"


#define ILI9486_USER_16_BIT_DATA_ (0)

//#define ILI9486_WIDTH		(320)
//#define ILI9486_HEIGHT	(480)

#define ILI9486_WIDTH		(240)
#define ILI9486_HEIGHT	(320)




typedef enum
{
	ILI9486_COLOR_WHITE		= 0xFFFF,
	ILI9486_COLOR_BLACK		= 0x0000,
	ILI9486_COLOR_BLUE		= 0x001F,  
	ILI9486_COLOR_BRED		= 0XF81F,
	ILI9486_COLOR_GRED		= 0XFFE0,
	ILI9486_COLOR_GBLUE		= 0X07FF,
	ILI9486_COLOR_RED			= 0xF800,
	ILI9486_COLOR_MAGENTA	= 0xF81F,
	ILI9486_COLOR_GREEN		= 0x07E0,
	ILI9486_COLOR_CYAN		= 0x7FFF,
	ILI9486_COLOR_YELLOW	= 0xFFE0,
	ILI9486_COLOR_BROWN		= 0XBC40,
	ILI9486_COLOR_BRRED		= 0XFC07,
	ILI9486_COLOR_GRAY		= 0X8430	
} ILI9486_COLOR_TypeDef;



#define ILI9486_RS_GPIO_PORT					GPIOB
#define ILI9486_RS_GPIO_PIN						GPIO_PIN_6
#define ILI9486_RS_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE()  
#define ILI9486_RS_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOB_CLK_DISABLE()

#define ILI9486_WR_GPIO_PORT					GPIOB
#define ILI9486_WR_GPIO_PIN						GPIO_PIN_0
#define ILI9486_WR_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE()  
#define ILI9486_WR_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOB_CLK_DISABLE()

#define ILI9486_RD_GPIO_PORT					GPIOF
#define ILI9486_RD_GPIO_PIN						GPIO_PIN_0
#define ILI9486_RD_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOF_CLK_ENABLE()  
#define ILI9486_RD_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOF_CLK_DISABLE()

#define ILI9486_CS_GPIO_PORT					GPIOF
#define ILI9486_CS_GPIO_PIN						GPIO_PIN_1
#define ILI9486_CS_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOF_CLK_ENABLE()  
#define ILI9486_CS_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOF_CLK_DISABLE()

#define ILI9486_REST_GPIO_PORT					GPIOA
#define ILI9486_REST_GPIO_PIN						GPIO_PIN_8
#define ILI9486_REST_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_REST_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()


#if (ILI9486_USER_16_BIT_DATA_ > 0)

#define ILI9486_DB0_GPIO_PORT					GPIOA
#define ILI9486_DB0_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB0_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB0_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB1_GPIO_PORT					GPIOA
#define ILI9486_DB1_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB1_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB1_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB2_GPIO_PORT					GPIOA
#define ILI9486_DB2_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB2_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB2_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB3_GPIO_PORT					GPIOA
#define ILI9486_DB3_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB3_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB3_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB4_GPIO_PORT					GPIOA
#define ILI9486_DB4_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB4_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB4_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB5_GPIO_PORT					GPIOA
#define ILI9486_DB5_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB5_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB5_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB6_GPIO_PORT					GPIOA
#define ILI9486_DB6_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB6_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB6_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB7_GPIO_PORT					GPIOA
#define ILI9486_DB7_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB7_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB7_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#endif

#define ILI9486_DB8_GPIO_PORT					GPIOA
#define ILI9486_DB8_GPIO_PIN						GPIO_PIN_0
#define ILI9486_DB8_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB8_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB9_GPIO_PORT					GPIOA
#define ILI9486_DB9_GPIO_PIN						GPIO_PIN_1
#define ILI9486_DB9_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB9_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB10_GPIO_PORT					GPIOA
#define ILI9486_DB10_GPIO_PIN						GPIO_PIN_2
#define ILI9486_DB10_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB10_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB11_GPIO_PORT					GPIOA
#define ILI9486_DB11_GPIO_PIN						GPIO_PIN_3
#define ILI9486_DB11_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB11_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB12_GPIO_PORT					GPIOA
#define ILI9486_DB12_GPIO_PIN						GPIO_PIN_4
#define ILI9486_DB12_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB12_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB13_GPIO_PORT					GPIOA
#define ILI9486_DB13_GPIO_PIN						GPIO_PIN_5
#define ILI9486_DB13_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB13_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB14_GPIO_PORT					GPIOA
#define ILI9486_DB14_GPIO_PIN						GPIO_PIN_6
#define ILI9486_DB14_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB14_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()

#define ILI9486_DB15_GPIO_PORT					GPIOA
#define ILI9486_DB15_GPIO_PIN						GPIO_PIN_7
#define ILI9486_DB15_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()  
#define ILI9486_DB15_GPIO_CLK_DISABLE()	__HAL_RCC_GPIOA_CLK_DISABLE()


#if (ILI9486_USER_16_BIT_DATA_ > 0)

#define ILI9486_16_BIT_DATA_WRITE(data)	do{ } while(0)

#else

//#define ILI9486_8_BIT_DATA_WRITE(data)	do{ GPIOA->ODR &= 0xFF00; GPIOA->ODR |= (((uint16_t)data) << 0);} while(0)

#define ILI9486_8_BIT_DATA_WRITE(data)	do{ \
HAL_GPIO_WritePin(ILI9486_DB8_GPIO_PORT, ILI9486_DB8_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 0)));\
HAL_GPIO_WritePin(ILI9486_DB9_GPIO_PORT, ILI9486_DB9_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 1)));\
HAL_GPIO_WritePin(ILI9486_DB10_GPIO_PORT, ILI9486_DB10_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 2)));\
HAL_GPIO_WritePin(ILI9486_DB11_GPIO_PORT, ILI9486_DB11_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 3)));\
HAL_GPIO_WritePin(ILI9486_DB12_GPIO_PORT, ILI9486_DB12_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 4)));\
HAL_GPIO_WritePin(ILI9486_DB13_GPIO_PORT, ILI9486_DB13_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 5)));\
HAL_GPIO_WritePin(ILI9486_DB14_GPIO_PORT, ILI9486_DB14_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 6)));\
HAL_GPIO_WritePin(ILI9486_DB15_GPIO_PORT, ILI9486_DB15_GPIO_PIN, (GPIO_PinState)(data&(0x01 << 7)));\
} while(0)


#endif

#define ILI9486_RS_WRITE(PinState)					HAL_GPIO_WritePin(ILI9486_RS_GPIO_PORT, ILI9486_RS_GPIO_PIN, (PinState == 0)?(GPIO_PIN_RESET):(GPIO_PIN_SET))
#define ILI9486_WR_WRITE(PinState)					HAL_GPIO_WritePin(ILI9486_WR_GPIO_PORT, ILI9486_WR_GPIO_PIN, (PinState == 0)?(GPIO_PIN_RESET):(GPIO_PIN_SET))
#define ILI9486_RD_WRITE(PinState)					HAL_GPIO_WritePin(ILI9486_RD_GPIO_PORT, ILI9486_RD_GPIO_PIN, (PinState == 0)?(GPIO_PIN_RESET):(GPIO_PIN_SET))
#define ILI9486_CS_WRITE(PinState)					HAL_GPIO_WritePin(ILI9486_CS_GPIO_PORT, ILI9486_CS_GPIO_PIN, (PinState == 0)?(GPIO_PIN_RESET):(GPIO_PIN_SET))
#define ILI9486_REST_WRITE(PinState)				HAL_GPIO_WritePin(ILI9486_REST_GPIO_PORT, ILI9486_REST_GPIO_PIN, (PinState == 0)?(GPIO_PIN_RESET):(GPIO_PIN_SET))


void ILI9486_Board_Init(void);
void ILI9486_APP_Init(void);
void ILI9486_Address_Set(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2);
void ILI9486_ClearScreen(uint16_t Color);
void ILI9486_DataPort_IN(void);
void ILI9486_DataPort_OUT(void);
#define VScreen_ 0x48 //����
#define CScreen_ 0x68 //����
void ILI9486_SetWindow(uint8_t Screen, uint16_t EW, uint16_t EH);

#endif
