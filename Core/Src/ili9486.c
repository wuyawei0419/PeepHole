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

#include "stm32f0xx_hal.h"
#include "ili9486.h"

void ILI9486_WR_REG(uint8_t Value);
void ILI9486_WR_ComData(uint8_t Value);

/**
  * @brief  ILI9486的板级初始化
  * @param  None
  * @retval None
  */
void ILI9486_Board_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	ILI9486_RS_GPIO_CLK_ENABLE();
	ILI9486_WR_GPIO_CLK_ENABLE();
	ILI9486_RD_GPIO_CLK_ENABLE();
	ILI9486_CS_GPIO_CLK_ENABLE();
	ILI9486_REST_GPIO_CLK_ENABLE();
	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	ILI9486_DB0_GPIO_CLK_ENABLE();
	ILI9486_DB1_GPIO_CLK_ENABLE();
	ILI9486_DB2_GPIO_CLK_ENABLE();
	ILI9486_DB3_GPIO_CLK_ENABLE();
	ILI9486_DB4_GPIO_CLK_ENABLE();
	ILI9486_DB5_GPIO_CLK_ENABLE();
	ILI9486_DB6_GPIO_CLK_ENABLE();
	ILI9486_DB7_GPIO_CLK_ENABLE();
	#endif
	ILI9486_DB8_GPIO_CLK_ENABLE();
	ILI9486_DB9_GPIO_CLK_ENABLE();
	ILI9486_DB10_GPIO_CLK_ENABLE();
	ILI9486_DB11_GPIO_CLK_ENABLE();
	ILI9486_DB12_GPIO_CLK_ENABLE();
	ILI9486_DB13_GPIO_CLK_ENABLE();
	ILI9486_DB14_GPIO_CLK_ENABLE();
	ILI9486_DB15_GPIO_CLK_ENABLE();
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_RS_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_RS_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_WR_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_WR_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_RD_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_RD_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_CS_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_CS_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_REST_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_REST_GPIO_PORT, &GPIO_InitStruct);
	
	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB0_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB0_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB1_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB1_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB2_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB2_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB3_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB3_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB4_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB4_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB5_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB5_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB6_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB6_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB7_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB7_GPIO_PORT, &GPIO_InitStruct);		
	#endif
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB8_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB8_GPIO_PORT, &GPIO_InitStruct);		
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB9_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB9_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB10_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB10_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB11_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB11_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB12_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB12_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB13_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB13_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB14_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB14_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB15_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB15_GPIO_PORT, &GPIO_InitStruct);
	
	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	ILI9486_16_BIT_DATA_WRITE(0xFFFF);
	#else
	ILI9486_8_BIT_DATA_WRITE(0xFF);
	#endif
	
	ILI9486_CS_WRITE(GPIO_PIN_SET);
	ILI9486_RD_WRITE(GPIO_PIN_SET);
	ILI9486_WR_WRITE(GPIO_PIN_SET);
	ILI9486_REST_WRITE(GPIO_PIN_RESET);
	HAL_Delay(100);	/*确保5ms以上才能稳定复位，推荐20ms*/
	ILI9486_REST_WRITE(GPIO_PIN_SET);
	HAL_Delay(100);	/*确保5ms以上才能稳定复位，推荐20ms*/
	ILI9486_CS_WRITE(GPIO_PIN_RESET);	/*打开片选使能*/
}




void ILI9486_DataPort_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	ILI9486_DB8_GPIO_CLK_ENABLE();
	
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB8_GPIO_PIN|ILI9486_DB9_GPIO_PIN|ILI9486_DB10_GPIO_PIN|ILI9486_DB11_GPIO_PIN|ILI9486_DB12_GPIO_PIN|ILI9486_DB13_GPIO_PIN|ILI9486_DB14_GPIO_PIN|ILI9486_DB15_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB8_GPIO_PORT, &GPIO_InitStruct);			
}

void ILI9486_DataPort_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	#endif
	
	ILI9486_DB8_GPIO_CLK_ENABLE();

	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	#endif
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9486_DB8_GPIO_PIN|ILI9486_DB9_GPIO_PIN|ILI9486_DB10_GPIO_PIN|ILI9486_DB11_GPIO_PIN|ILI9486_DB12_GPIO_PIN|ILI9486_DB13_GPIO_PIN|ILI9486_DB14_GPIO_PIN|ILI9486_DB15_GPIO_PIN;
	HAL_GPIO_Init(ILI9486_DB8_GPIO_PORT, &GPIO_InitStruct);		
}


/**
  * @brief  ILI9486的应用初始化
  * @param  None
  * @retval None
  */
void ILI9486_APP_Init(void)
{
//3.5IPS ILI9481+CMI	
ILI9486_WR_REG(0XF2);
ILI9486_WR_ComData(0x18);
ILI9486_WR_ComData(0xA3);
ILI9486_WR_ComData(0x12);
ILI9486_WR_ComData(0x02);
ILI9486_WR_ComData(0XB2);
ILI9486_WR_ComData(0x12);
ILI9486_WR_ComData(0xFF);
ILI9486_WR_ComData(0x10);
ILI9486_WR_ComData(0x00);
ILI9486_WR_REG(0XF8);
ILI9486_WR_ComData(0x21);
ILI9486_WR_ComData(0x04);
ILI9486_WR_REG(0XF9);
ILI9486_WR_ComData(0x00);
ILI9486_WR_ComData(0x08);
ILI9486_WR_REG(0x36);
ILI9486_WR_ComData(0x08);
ILI9486_WR_REG(0x3A);
ILI9486_WR_ComData(0x05);
ILI9486_WR_REG(0xB4);
ILI9486_WR_ComData(0x01);//0x00
ILI9486_WR_REG(0xB6);
ILI9486_WR_ComData(0x02);
ILI9486_WR_ComData(0x22);
ILI9486_WR_REG(0xC1);
ILI9486_WR_ComData(0x41);
ILI9486_WR_REG(0xC5);
ILI9486_WR_ComData(0x00);
ILI9486_WR_ComData(0x07);//0X18
ILI9486_WR_REG(0xE0);
ILI9486_WR_ComData(0x0F);
ILI9486_WR_ComData(0x1F);
ILI9486_WR_ComData(0x1C);
ILI9486_WR_ComData(0x0C);
ILI9486_WR_ComData(0x0F);
ILI9486_WR_ComData(0x08);
ILI9486_WR_ComData(0x48);
ILI9486_WR_ComData(0x98);
ILI9486_WR_ComData(0x37);
ILI9486_WR_ComData(0x0A);
ILI9486_WR_ComData(0x13);
ILI9486_WR_ComData(0x04);
ILI9486_WR_ComData(0x11);
ILI9486_WR_ComData(0x0D);
ILI9486_WR_ComData(0x00);
ILI9486_WR_REG(0xE1);
ILI9486_WR_ComData(0x0F);
ILI9486_WR_ComData(0x32);
ILI9486_WR_ComData(0x2E);
ILI9486_WR_ComData(0x0B);
ILI9486_WR_ComData(0x0D);
ILI9486_WR_ComData(0x05);
ILI9486_WR_ComData(0x47);
ILI9486_WR_ComData(0x75);
ILI9486_WR_ComData(0x37);
ILI9486_WR_ComData(0x06);
ILI9486_WR_ComData(0x10);
ILI9486_WR_ComData(0x03);
ILI9486_WR_ComData(0x24);
ILI9486_WR_ComData(0x20);
ILI9486_WR_ComData(0x00);
ILI9486_WR_REG(0x11);
HAL_Delay(200);
ILI9486_WR_REG(0x29);

}


/**
  * @brief  颜色数据写入总线
  * @param  ValueH：高位
  * @param  ValueL：低位
  * @retval None
  */
void ILI9486_Write_ColorBus(uint8_t ValueH, uint8_t ValueL)
{
	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	
	#else
	ILI9486_8_BIT_DATA_WRITE(ValueH);
	ILI9486_WR_WRITE(GPIO_PIN_RESET);
	ILI9486_WR_WRITE(GPIO_PIN_SET);
	ILI9486_8_BIT_DATA_WRITE(ValueL);
	ILI9486_WR_WRITE(GPIO_PIN_RESET);
	ILI9486_WR_WRITE(GPIO_PIN_SET);
	#endif
}


/**
  * @brief  寄存器数据写入总线
  * @param  Value：寄存器数据
  * @retval None
  */
void ILI9486_Write_ComBus(uint8_t Value)
{
	#if (ILI9486_USER_16_BIT_DATA_ > 0)
	
	#else
	ILI9486_8_BIT_DATA_WRITE(Value);
	ILI9486_WR_WRITE(GPIO_PIN_RESET);
	ILI9486_WR_WRITE(GPIO_PIN_SET);
	#endif	
}


/**
  * @brief  写入颜色8bit数据
  * @param  ValueH：高位
  * @param  ValueL：低位
  * @retval None
  */
void ILI9486_WR_Data8(uint8_t ValueH, uint8_t ValueL)
{
	ILI9486_RS_WRITE(GPIO_PIN_SET);
	ILI9486_Write_ColorBus(ValueH, ValueL);
}


/**
  * @brief  写入颜色16bit数据
  * @param  Value：数据
  * @retval None
  */
void ILI9486_WR_Data(uint16_t Value)
{
	ILI9486_RS_WRITE(GPIO_PIN_SET);
	ILI9486_Write_ColorBus(Value >> 8, Value);
}


/**
  * @brief  写寄存器数据
  * @param  Value：数据
  * @retval None
  */
void ILI9486_WR_ComData(uint8_t Value)
{
	ILI9486_RS_WRITE(GPIO_PIN_SET);
	ILI9486_Write_ComBus(Value);
}


/**
  * @brief  写寄存器
  * @param  Value：寄存器
  * @retval None
  */
void ILI9486_WR_REG(uint8_t Value)
{
	ILI9486_RS_WRITE(GPIO_PIN_RESET);
	ILI9486_Write_ComBus(Value);
}


/**
  * @brief  写寄存器数据
	*	@param	Register：寄存器
  * @param  Value：数据
  * @retval None
  */
void ILI9486_WR_REG_DATA(uint8_t Register, uint8_t Value)
{
	ILI9486_WR_REG(Register);
	ILI9486_WR_ComData(Value);
}


/**
  * @brief  写坐标
	*	@param	X1
	*	@param	Y1
	*	@param	X2
	*	@param	Y2
  * @retval None
  */
void ILI9486_Address_Set(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2)
{
	ILI9486_WR_REG(0x2A);
	ILI9486_WR_ComData(X1 >> 8);
	ILI9486_WR_ComData(X1);
	ILI9486_WR_ComData(X2 >> 8);
	ILI9486_WR_ComData(X2);
	
	ILI9486_WR_REG(0x2B);
	ILI9486_WR_ComData(Y1 >> 8);
	ILI9486_WR_ComData(Y1);
	ILI9486_WR_ComData(Y2 >> 8);
	ILI9486_WR_ComData(Y2);
	ILI9486_WR_REG(0x2C);
}


/**
  * @brief  清屏
	*	@param	Color：填充的颜色
  * @retval None
  */
void ILI9486_ClearScreen(uint16_t Color)
{
	uint8_t v_h, v_l;
	uint16_t i, j;
	
	v_h = Color >> 8;
	v_l = Color;
	ILI9486_Address_Set(0, 0, ILI9486_WIDTH-1, ILI9486_HEIGHT-1);
	for(i = 0; i < ILI9486_WIDTH; i++)
	{
		for(j = 0; j < ILI9486_HEIGHT; j++)
		{
			ILI9486_WR_Data8(v_h, v_l);
		}
	}
}

