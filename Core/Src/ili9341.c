/**
  ******************************************************************************
  * @file    ili9341.h
  * @author  ZhuSL
  * @brief   ili9341 driver
  *
  ******************************************************************************
  * @attention
  *		None
  *
  ******************************************************************************
  */

#include "stm32f0xx_hal.h"
#include "ili9341.h"

void ILI9341_WR_REG(uint8_t Value);
void ILI9341_WR_ComData(uint8_t Value);

/**
  * @brief  ILI9341的板级初始化
  * @param  None
  * @retval None
  */
void ILI9341_Board_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	ILI9341_RS_GPIO_CLK_ENABLE();
	ILI9341_WR_GPIO_CLK_ENABLE();
	ILI9341_RD_GPIO_CLK_ENABLE();
	ILI9341_CS_GPIO_CLK_ENABLE();
	ILI9341_REST_GPIO_CLK_ENABLE();
	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	ILI9341_DB0_GPIO_CLK_ENABLE();
	ILI9341_DB1_GPIO_CLK_ENABLE();
	ILI9341_DB2_GPIO_CLK_ENABLE();
	ILI9341_DB3_GPIO_CLK_ENABLE();
	ILI9341_DB4_GPIO_CLK_ENABLE();
	ILI9341_DB5_GPIO_CLK_ENABLE();
	ILI9341_DB6_GPIO_CLK_ENABLE();
	ILI9341_DB7_GPIO_CLK_ENABLE();
	#endif
	ILI9341_DB8_GPIO_CLK_ENABLE();
	ILI9341_DB9_GPIO_CLK_ENABLE();
	ILI9341_DB10_GPIO_CLK_ENABLE();
	ILI9341_DB11_GPIO_CLK_ENABLE();
	ILI9341_DB12_GPIO_CLK_ENABLE();
	ILI9341_DB13_GPIO_CLK_ENABLE();
	ILI9341_DB14_GPIO_CLK_ENABLE();
	ILI9341_DB15_GPIO_CLK_ENABLE();
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_RS_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_RS_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_WR_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_WR_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_RD_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_RD_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_CS_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_CS_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_REST_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_REST_GPIO_PORT, &GPIO_InitStruct);
	
	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB0_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB0_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB1_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB1_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB2_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB2_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB3_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB3_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB4_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB4_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB5_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB5_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB6_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB6_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB7_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB7_GPIO_PORT, &GPIO_InitStruct);		
	#endif
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB8_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB8_GPIO_PORT, &GPIO_InitStruct);		
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB9_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB9_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB10_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB10_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB11_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB11_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB12_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB12_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB13_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB13_GPIO_PORT, &GPIO_InitStruct);	

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB14_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB14_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB15_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB15_GPIO_PORT, &GPIO_InitStruct);
	
	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	ILI9341_16_BIT_DATA_WRITE(0xFFFF);
	#else
	ILI9341_8_BIT_DATA_WRITE(0xFF);
	#endif
	
	ILI9341_CS_WRITE(GPIO_PIN_SET);
	ILI9341_RD_WRITE(GPIO_PIN_SET);
	ILI9341_WR_WRITE(GPIO_PIN_SET);
	ILI9341_REST_WRITE(GPIO_PIN_RESET);
	HAL_Delay(20);	/*确保5ms以上才能稳定复位，推荐20ms*/
	ILI9341_REST_WRITE(GPIO_PIN_SET);
	HAL_Delay(20);	/*确保5ms以上才能稳定复位，推荐20ms*/
	ILI9341_CS_WRITE(GPIO_PIN_RESET);	/*打开片选使能*/
}




void ILI9341_DataPort_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	ILI9341_DB8_GPIO_CLK_ENABLE();
	
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB8_GPIO_PIN|ILI9341_DB9_GPIO_PIN|ILI9341_DB10_GPIO_PIN|ILI9341_DB11_GPIO_PIN|ILI9341_DB12_GPIO_PIN|ILI9341_DB13_GPIO_PIN|ILI9341_DB14_GPIO_PIN|ILI9341_DB15_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB8_GPIO_PORT, &GPIO_InitStruct);			
}

void ILI9341_DataPort_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	#endif
	
	ILI9341_DB8_GPIO_CLK_ENABLE();

	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	#endif
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pin = ILI9341_DB8_GPIO_PIN|ILI9341_DB9_GPIO_PIN|ILI9341_DB10_GPIO_PIN|ILI9341_DB11_GPIO_PIN|ILI9341_DB12_GPIO_PIN|ILI9341_DB13_GPIO_PIN|ILI9341_DB14_GPIO_PIN|ILI9341_DB15_GPIO_PIN;
	HAL_GPIO_Init(ILI9341_DB8_GPIO_PORT, &GPIO_InitStruct);		
}


/**
  * @brief  ILI9341的应用初始化
  * @param  None
  * @retval None
  */
void ILI9341_APP_Init(void)
{
	//************* Start Initial Sequence **********//
	ILI9341_WR_REG(0xcf); 
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0xc1);
	ILI9341_WR_ComData(0x30);

	ILI9341_WR_REG(0xed); 
	ILI9341_WR_ComData(0x64);
	ILI9341_WR_ComData(0x03);
	ILI9341_WR_ComData(0x12);
	ILI9341_WR_ComData(0x81);

	ILI9341_WR_REG(0xcb); 
	ILI9341_WR_ComData(0x39);
	ILI9341_WR_ComData(0x2c);
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x34);
	ILI9341_WR_ComData(0x02);

	ILI9341_WR_REG(0xea); 
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x00);

	ILI9341_WR_REG(0xe8); 
	ILI9341_WR_ComData(0x85);
	ILI9341_WR_ComData(0x10);
	ILI9341_WR_ComData(0x79);

	ILI9341_WR_REG(0xC0); //Power control
	ILI9341_WR_ComData(0x23); //VRH[5:0]

	ILI9341_WR_REG(0xC1); //Power control
	ILI9341_WR_ComData(0x11); //SAP[2:0];BT[3:0]

	ILI9341_WR_REG(0xC2);
	ILI9341_WR_ComData(0x11);

	ILI9341_WR_REG(0xC5); //VCM control
	ILI9341_WR_ComData(0x3d);
	ILI9341_WR_ComData(0x30);

	ILI9341_WR_REG(0xc7); 
	ILI9341_WR_ComData(0xaa);

	ILI9341_WR_REG(0x3A); 
	ILI9341_WR_ComData(0x55);

	ILI9341_WR_REG(0x36); // Memory Access Control
	ILI9341_WR_ComData(0x08);
	//ILI9341_WR_ComData(0xa8);

	ILI9341_WR_REG(0xB1); // Frame Rate Control
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x11);

	ILI9341_WR_REG(0xB6); // Display Function Control
	ILI9341_WR_ComData(0x0a);
	ILI9341_WR_ComData(0xa2);

	ILI9341_WR_REG(0xF2); // 3Gamma Function Disable
	ILI9341_WR_ComData(0x00);

	ILI9341_WR_REG(0xF7);
	ILI9341_WR_ComData(0x20);

	ILI9341_WR_REG(0xF1);
	ILI9341_WR_ComData(0x01);
	ILI9341_WR_ComData(0x30);

	ILI9341_WR_REG(0x26); //Gamma curve selected
	ILI9341_WR_ComData(0x01);

	ILI9341_WR_REG(0xE0); //Set Gamma
	ILI9341_WR_ComData(0x0f);
	ILI9341_WR_ComData(0x3f);
	ILI9341_WR_ComData(0x2f);
	ILI9341_WR_ComData(0x0c);
	ILI9341_WR_ComData(0x10);
	ILI9341_WR_ComData(0x0a);
	ILI9341_WR_ComData(0x53);
	ILI9341_WR_ComData(0xd5);
	ILI9341_WR_ComData(0x40);
	ILI9341_WR_ComData(0x0a);
	ILI9341_WR_ComData(0x13);
	ILI9341_WR_ComData(0x03);
	ILI9341_WR_ComData(0x08);
	ILI9341_WR_ComData(0x03);
	ILI9341_WR_ComData(0x00);

	ILI9341_WR_REG(0xE1); //Set Gamma
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x10);
	ILI9341_WR_ComData(0x03);
	ILI9341_WR_ComData(0x0f);
	ILI9341_WR_ComData(0x05);
	ILI9341_WR_ComData(0x2c);
	ILI9341_WR_ComData(0xa2);
	ILI9341_WR_ComData(0x3f);
	ILI9341_WR_ComData(0x05);
	ILI9341_WR_ComData(0x0e);
	ILI9341_WR_ComData(0x0c);
	ILI9341_WR_ComData(0x37);
	ILI9341_WR_ComData(0x3c);
	ILI9341_WR_ComData(0x0F);
	ILI9341_WR_REG(0x11); //Exit Sleep
	HAL_Delay(500);//此处必须要延时80ms或者更多
	ILI9341_WR_REG(0x29); //display on	
	HAL_Delay(1000);
	
	//ILI9341_SetWindow(VScreen, 320, 240);
	ILI9341_SetWindow(CScreen, 240, 320);
	HAL_Delay(1000);
}


/**
  * @brief  颜色数据写入总线
  * @param  ValueH：高位
  * @param  ValueL：低位
  * @retval None
  */
void ILI9341_Write_ColorBus(uint8_t ValueH, uint8_t ValueL)
{
	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	
	#else
	ILI9341_8_BIT_DATA_WRITE(ValueH);
	ILI9341_WR_WRITE(GPIO_PIN_RESET);
	ILI9341_WR_WRITE(GPIO_PIN_SET);
	ILI9341_8_BIT_DATA_WRITE(ValueL);
	ILI9341_WR_WRITE(GPIO_PIN_RESET);
	ILI9341_WR_WRITE(GPIO_PIN_SET);
	#endif
}


/**
  * @brief  寄存器数据写入总线
  * @param  Value：寄存器数据
  * @retval None
  */
void ILI9341_Write_ComBus(uint8_t Value)
{
	#if (ILI9341_USER_16_BIT_DATA_ > 0)
	
	#else
	ILI9341_8_BIT_DATA_WRITE(Value);
	ILI9341_WR_WRITE(GPIO_PIN_RESET);
	ILI9341_WR_WRITE(GPIO_PIN_SET);
	#endif	
}


/**
  * @brief  写入颜色8bit数据
  * @param  ValueH：高位
  * @param  ValueL：低位
  * @retval None
  */
void ILI9341_WR_Data8(uint8_t ValueH, uint8_t ValueL)
{
	ILI9341_RS_WRITE(GPIO_PIN_SET);
	ILI9341_Write_ColorBus(ValueH, ValueL);
}


/**
  * @brief  写入颜色16bit数据
  * @param  Value：数据
  * @retval None
  */
void ILI9341_WR_Data(uint16_t Value)
{
	ILI9341_RS_WRITE(GPIO_PIN_SET);
	ILI9341_Write_ColorBus(Value >> 8, Value);
}


/**
  * @brief  写寄存器数据
  * @param  Value：数据
  * @retval None
  */
void ILI9341_WR_ComData(uint8_t Value)
{
	ILI9341_RS_WRITE(GPIO_PIN_SET);
	ILI9341_Write_ComBus(Value);
}


/**
  * @brief  写寄存器
  * @param  Value：寄存器
  * @retval None
  */
void ILI9341_WR_REG(uint8_t Value)
{
	ILI9341_RS_WRITE(GPIO_PIN_RESET);
	ILI9341_Write_ComBus(Value);
}


/**
  * @brief  写寄存器数据
	*	@param	Register：寄存器
  * @param  Value：数据
  * @retval None
  */
void ILI9341_WR_REG_DATA(uint8_t Register, uint8_t Value)
{
	ILI9341_WR_REG(Register);
	ILI9341_WR_ComData(Value);
}


/**
  * @brief  写坐标
	*	@param	X1
	*	@param	Y1
	*	@param	X2
	*	@param	Y2
  * @retval None
  */
void ILI9341_Address_Set(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2)
{
	ILI9341_WR_REG(0x2A);
	ILI9341_WR_ComData(X1 >> 8);
	ILI9341_WR_ComData(X1);
	ILI9341_WR_ComData(X2 >> 8);
	ILI9341_WR_ComData(X2);
	
	ILI9341_WR_REG(0x2B);
	ILI9341_WR_ComData(Y1 >> 8);
	ILI9341_WR_ComData(Y1);
	ILI9341_WR_ComData(Y2 >> 8);
	ILI9341_WR_ComData(Y2);
	ILI9341_WR_REG(0x2C);
}


/**
  * @brief  清屏
	*	@param	Color：填充的颜色
  * @retval None
  */
void ILI9341_ClearScreen(uint16_t Color)
{
	uint8_t v_h, v_l;
	uint16_t i, j;
	
	v_h = Color >> 8;
	v_l = Color;

	ILI9341_Address_Set(0, 0, ILI9341_HEIGHT-1, ILI9341_WIDTH-1);
	for(i = 0; i < ILI9341_WIDTH; i++)
	{
		for(j = 0; j < ILI9341_HEIGHT; j++)
		{
			ILI9341_WR_Data8(v_h, v_l);
		}
	}
}








/**
  * @brief  设置窗口
	*	@param	Color：填充的颜色
  * @retval None
  */
void ILI9341_SetWindow(uint8_t Screen, uint16_t EW, uint16_t EH)
{
	ILI9341_WR_REG(0x36);
	ILI9341_WR_ComData(Screen);
	ILI9341_WR_REG(0x2A);
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData((EW-1)>>8);
	ILI9341_WR_ComData(EW-1);
	ILI9341_WR_REG(0x2B);
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData(0x00);
	ILI9341_WR_ComData((EH-1)>>8);
	ILI9341_WR_ComData(EH-1);
}



