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
	HAL_Delay(100);//此处必须要延时80ms或者更多
	ILI9341_WR_REG(0x29); //display on	
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
	ILI9341_Address_Set(0, 0, ILI9341_WIDTH-1, ILI9341_HEIGHT-1);
	for(i = 0; i < ILI9341_WIDTH; i++)
	{
		for(j = 0; j < ILI9341_HEIGHT; j++)
		{
			ILI9341_WR_Data8(v_h, v_l);
		}
	}
}


/**
  * @brief  清屏
	*	@param	Color：填充的颜色
  * @retval None
  */
void ILI9341_test(uint16_t Color)
{
}























void Tft_Init(void)
{
	 	
	ILI9341_REST_WRITE(1);
	HAL_Delay(20); 
	ILI9341_REST_WRITE(0);
	HAL_Delay(20);
	ILI9341_REST_WRITE(1);
	HAL_Delay(1000);


		TftWrite(0x00e5, 0x8000);	
		TftWrite(0x0000, 0x0001);	
		TftWrite(0x0001, 0x0100);
		TftWrite(0x0002, 0x0700);
	#if AM==000       
		TftWrite(0x0003,0x1000);
	#elif AM==001        
		TftWrite(0x0003,0x1008);      
	#elif AM==010  
	    TftWrite(0x0003,0x1010);        
	#elif AM==011
		TftWrite(0x0003,0x1018);
	#elif AM==100  
		TftWrite(0x0003,0x1020);      
	#elif AM==101  
		TftWrite(0x0003,0x1028);      
	#elif AM==110  
		TftWrite(0x0003,0x1030);      
	#elif AM==111  
		TftWrite(0x0003,0x1038);
	#endif
		TftWrite(0x0004, 0x0000);
		TftWrite(0x0008, 0x0202);	
		TftWrite(0x0009, 0x0000);	
		TftWrite(0x000A, 0x0000);
		TftWrite(0x000C, 0x0000);	
		TftWrite(0x000D, 0x0000);	
		TftWrite(0x000F, 0x0000);	
		TftWrite(0x0010, 0x0000);	
		TftWrite(0x0011, 0x0007);	
		TftWrite(0x0012, 0x0000);	
		TftWrite(0x0013, 0x0000);	
		HAL_Delay(1000);
		TftWrite(0x0010, 0x17B0);	
		TftWrite(0x0011, 0x0007);	
		HAL_Delay(1000);
		TftWrite(0x0012, 0x013A);	
		HAL_Delay(1000);
		TftWrite(0x0013, 0x1A00);	
		TftWrite(0x0029, 0x000c);		
		HAL_Delay(1000);
		TftWrite(0x0030, 0x0000);	
		TftWrite(0x0031, 0x0505);	
		TftWrite(0x0032, 0x0004);	
		TftWrite(0x0035, 0x0006);	
		TftWrite(0x0036, 0x0707);	
		TftWrite(0x0037, 0x0105);	
		TftWrite(0x0038, 0x0002);	
		TftWrite(0x0039, 0x0707);	
		TftWrite(0x003C, 0x0704);	
		TftWrite(0x003D, 0x0807);	
		TftWrite(0x0050, 0x0000);
		TftWrite(0x0051, 0x00EF);
		TftWrite(0x0052, 0x0000);
		TftWrite(0x0053, 0x013F);
		TftWrite(0x0060, 0x2700);
		TftWrite(0x0061, 0x0001);
		TftWrite(0x006A, 0x0000);
	#if AM==000         
		TftWrite(0x0020,0x00ef);
		TftWrite(0x0021,0x013f);      
	#elif AM==001
		TftWrite(0x0020,0x00ef);
		TftWrite(0x0021,0x013f);      
	#elif AM==010
		TftWrite(0x0020,0x0000);
		TftWrite(0x0021,0x013f);      
	#elif AM==011
		TftWrite(0x0020,0x0000);
		TftWrite(0x0021,0x013f);       
	#elif AM==100
		TftWrite(0x0020,0x00ef);
		TftWrite(0x0021,0x0000);      
	#elif AM==101  
		TftWrite(0x0020,0x00ef);
		TftWrite(0x0021,0x0000);      
	#elif AM==110
		TftWrite(0x0020,0x0000);
		TftWrite(0x0021,0x0000);      
	#elif AM==111
		TftWrite(0x0020,0x0000);
		TftWrite(0x0021,0x0000);         
	#endif  	
		TftWrite(0x0080, 0x0000);	
		TftWrite(0x0081, 0x0000);
		TftWrite(0x0082, 0x0000);
		TftWrite(0x0083, 0x0000);
		TftWrite(0x0084, 0x0000);	
		TftWrite(0x0085, 0x0000);
		TftWrite(0x0090, 0x0010);	
		TftWrite(0x0092, 0x0000);
		TftWrite(0x0093, 0x0003);
		TftWrite(0x0095, 0x0110);
		TftWrite(0x0097, 0x0000);	
		TftWrite(0x0098, 0x0000);	
		TftWrite(0x0007, 0x0173);	
		HAL_Delay(1000);
}


void Tft_WR_DATA16(uint16_t inputdata)
{
	uint8_t inputdatah;
	uint8_t inputdatal;


	inputdatal=   (uint8_t)(inputdata&0x00ff);
	inputdatah=   (uint8_t)((inputdata&0xff00)>>8);

	ILI9341_RS_WRITE(1);

	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(inputdatah); 
	
	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);
	
	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(inputdatal); 	
	
	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);
}




void TftWrite16(uint16_t index)
{   
	uint8_t indexh;
	uint8_t indexl;
	
  indexh=  (uint8_t)((index&0xff00)>>8);
	indexl=  (uint8_t)(index&0x00ff);
	
	ILI9341_RS_WRITE(0);

	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(indexh);
	
	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);

	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(indexl);

	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);
}





void TftWrite(uint16_t index,uint16_t inputdata)
{
  uint8_t indexh;
	uint8_t indexl;
	uint8_t inputdatah;
	uint8_t inputdatal;

  indexh=  (uint8_t)((index&0xff00)>>8);
	indexl=  (uint8_t)(index&0x00ff);
	
	inputdatah =  (uint8_t)((inputdata&0xff00)>>8);
	inputdatal =  (uint8_t)(inputdata&0x00ff);
	
	ILI9341_RS_WRITE(0);

	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(indexh);
	
	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);
	
	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(indexl);
	
	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);

	ILI9341_RS_WRITE(1);
	
	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(inputdatah);	
	
	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);

	ILI9341_8_BIT_DATA_WRITE(0x00);
	ILI9341_8_BIT_DATA_WRITE(inputdatal);

	ILI9341_WR_WRITE(0);   
	ILI9341_WR_WRITE(1);

}




void TftClear(uint16_t Color)
{
  uint32_t index = 0;

	TftWrite(0x0050,0x00);
	TftWrite(0x0051,239);
	TftWrite(0x0052,0x00);
	TftWrite(0x0053,319);
	TftWrite(0x0020,0x0000);
	TftWrite(0x0021,0x0000);  
	TftWrite16(0x0022);    

  for(index = 0; index < 76800; index++)
  {
    Tft_WR_DATA16(Color);
   
  } 
 
}



	
void Tft_SetBackground(uint16_t StartX,uint16_t StartY,uint16_t LongX,uint16_t LongY)
{
  
#if AM==000    
	Tft_SetCursor(StartX+LongX-1,312-StartY+LongY-1);

#elif AM==001
	Tft_SetCursor(StartX+LongX-1,312-StartY+LongY-1);
     
#elif AM==010
	Tft_SetCursor(StartX,312-StartY+LongY-1);
     
#elif AM==011 
	Tft_SetCursor(StartX,312-StartY+LongY-1);
     
#elif AM==100
	Tft_SetCursor(StartX+LongX-1,312-StartY);     
     
#elif AM==101
	Tft_SetCursor(StartX+LongX-1,312-StartY);     
     
#elif AM==110
	Tft_SetCursor(StartX,312-StartY); 
     
#elif AM==111
	Tft_SetCursor(StartX,312-StartY);  
     
#endif
     
	TftWrite(0x0050,StartX);
	TftWrite(0x0051,StartX+LongX-1);
	TftWrite(0x0052,312-StartY);
	TftWrite(0x0053,312-StartY+LongY-1);
}






void Tft_SetCursor(uint16_t Xpos, uint16_t Ypos)
{
 
  TftWrite(0x20, Xpos);
  TftWrite(0x21, Ypos);
}




