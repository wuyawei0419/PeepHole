/**
  ******************************************************************************
  * @file    ov7670.c
  * @author  ZhuSL
  * @brief   OV7670摄像头驱动
  *
  ******************************************************************************
  */

#include "ov7670.h"
#include "sccb.h"


static void OV7670_DelayMs(uint16_t Ms);
static void OV7670_Delay(void);




void Set_Cmos7670RegVGA(void)
{
                OV7670_WR_Reg(0x11, 0x02);         // 30fps
                OV7670_WR_Reg(0x6b, 0x8a);        // pclk*6

                OV7670_WR_Reg(0x3A, 0x04);
                OV7670_WR_Reg(0x12, 0x00);
                OV7670_WR_Reg(0x17, 0x13);
                OV7670_WR_Reg(0x18, 0x01);
                OV7670_WR_Reg(0x32, 0xB6);
                OV7670_WR_Reg(0x19, 0x02);
                OV7670_WR_Reg(0x1A, 0x7A);
                OV7670_WR_Reg(0x03, 0x0F);
                OV7670_WR_Reg(0x0C, 0x00);
                OV7670_WR_Reg(0x3E, 0x00);
                OV7670_WR_Reg(0x70, 0x3A);
                OV7670_WR_Reg(0x71, 0x35);
                OV7670_WR_Reg(0x72, 0x11);
                OV7670_WR_Reg(0x73, 0xF0);
                OV7670_WR_Reg(0xA2, 0x3B);
                OV7670_WR_Reg(0x1E, 0x0F);
                OV7670_WR_Reg(0x7a, 0x20);
                OV7670_WR_Reg(0x7b, 0x03);
                OV7670_WR_Reg(0x7c, 0x0a);
                OV7670_WR_Reg(0x7d, 0x1a);
                OV7670_WR_Reg(0x7e, 0x3f);
                OV7670_WR_Reg(0x7f, 0x4e);
                OV7670_WR_Reg(0x80, 0x5b);
                OV7670_WR_Reg(0x81, 0x68);
                OV7670_WR_Reg(0x82, 0x75);
                OV7670_WR_Reg(0x83, 0x7f);
                OV7670_WR_Reg(0x84, 0x89);
                OV7670_WR_Reg(0x85, 0x9a);
                OV7670_WR_Reg(0x86, 0xa6);
                OV7670_WR_Reg(0x87, 0xbd);
                OV7670_WR_Reg(0x88, 0xd3);
                OV7670_WR_Reg(0x89, 0xe8);
                OV7670_WR_Reg(0x13, 0xE0);
                OV7670_WR_Reg(0x00, 0x00);
                OV7670_WR_Reg(0x10, 0x00);
                OV7670_WR_Reg(0x0D, 0x50);
                OV7670_WR_Reg(0x42, 0x40);
                OV7670_WR_Reg(0x14, 0x28);
                OV7670_WR_Reg(0xA5, 0x03);
                OV7670_WR_Reg(0xAB, 0x03);
                OV7670_WR_Reg(0x24, 0x50);
                OV7670_WR_Reg(0x25, 0x43);
                OV7670_WR_Reg(0x26, 0xa3);
                OV7670_WR_Reg(0x9F, 0x78);
                OV7670_WR_Reg(0xA0, 0x68);
                OV7670_WR_Reg(0xA1, 0x03);
                OV7670_WR_Reg(0xA6, 0xd2);
                OV7670_WR_Reg(0xA7, 0xd2);
                OV7670_WR_Reg(0xA8, 0xF0);
                OV7670_WR_Reg(0xA9, 0x80);
                OV7670_WR_Reg(0xAA, 0x14);
                OV7670_WR_Reg(0x13, 0xE5);
                OV7670_WR_Reg(0x0E, 0x61);
                OV7670_WR_Reg(0x0F, 0x4B);         // Flip (bit4) & Mirror (bit5)
                OV7670_WR_Reg(0x16, 0x02);
                OV7670_WR_Reg(0x21, 0x02);
                OV7670_WR_Reg(0x22, 0x91);
                OV7670_WR_Reg(0x29, 0x07);
                OV7670_WR_Reg(0x33, 0x0B);
                OV7670_WR_Reg(0x35, 0x0B);
                OV7670_WR_Reg(0x37, 0x1D);
                OV7670_WR_Reg(0x38, 0x71);
                OV7670_WR_Reg(0x39, 0x2A);
                OV7670_WR_Reg(0x3C, 0x78);
                OV7670_WR_Reg(0x4D, 0x40);
                OV7670_WR_Reg(0x4E, 0x20);
                OV7670_WR_Reg(0x69, 0x00);

                OV7670_WR_Reg(0x74, 0x10);
                OV7670_WR_Reg(0x8D, 0x4F);
                OV7670_WR_Reg(0x8E, 0x00);
                OV7670_WR_Reg(0x8F, 0x00);
                OV7670_WR_Reg(0x90, 0x00);
                OV7670_WR_Reg(0x91, 0x00);
                OV7670_WR_Reg(0x96, 0x00);
                OV7670_WR_Reg(0x9A, 0x80);
                OV7670_WR_Reg(0xB0, 0x84);
                OV7670_WR_Reg(0xB1, 0x0C);
                OV7670_WR_Reg(0xB2, 0x0E);
                OV7670_WR_Reg(0xB3, 0x82);
                OV7670_WR_Reg(0xB8, 0x0A);
                OV7670_WR_Reg(0x43, 0x02);
                OV7670_WR_Reg(0x44, 0xf2);
                OV7670_WR_Reg(0x45, 0x46);
                OV7670_WR_Reg(0x46, 0x63);
                OV7670_WR_Reg(0x47, 0x32);
                OV7670_WR_Reg(0x48, 0x3b);
                OV7670_WR_Reg(0x59, 0x92);
                OV7670_WR_Reg(0x5a, 0x9b);
                OV7670_WR_Reg(0x5b, 0xa5);
                OV7670_WR_Reg(0x5c, 0x7a);
                OV7670_WR_Reg(0x5d, 0x4a);
                OV7670_WR_Reg(0x5e, 0x0a);
                OV7670_WR_Reg(0x6c, 0x0a);
                OV7670_WR_Reg(0x6d, 0x55);
                OV7670_WR_Reg(0x6e, 0x11);
                OV7670_WR_Reg(0x6f, 0x9e);
                OV7670_WR_Reg(0x6A, 0x40);
                OV7670_WR_Reg(0x01, 0x40);
                OV7670_WR_Reg(0x02, 0x40);
                OV7670_WR_Reg(0x13, 0xf7);
                OV7670_WR_Reg(0x4f, 0x9c);
                OV7670_WR_Reg(0x50, 0x99);
                OV7670_WR_Reg(0x51, 0x02);
                OV7670_WR_Reg(0x52, 0x29);
                OV7670_WR_Reg(0x53, 0x8b);
                OV7670_WR_Reg(0x54, 0xb5);
                OV7670_WR_Reg(0x58, 0x1e);
                OV7670_WR_Reg(0x62, 0x08);
                OV7670_WR_Reg(0x63, 0x10);
                OV7670_WR_Reg(0x64, 0x04);
                OV7670_WR_Reg(0x65, 0x00);
                OV7670_WR_Reg(0x66, 0x05);
                OV7670_WR_Reg(0x94, 0x04);
                OV7670_WR_Reg(0x95, 0x06);
                OV7670_WR_Reg(0x41, 0x08);
                OV7670_WR_Reg(0x3F, 0x00);
                OV7670_WR_Reg(0x75, 0x44);
                OV7670_WR_Reg(0x76, 0xe1);
                OV7670_WR_Reg(0x4C, 0x00);
                OV7670_WR_Reg(0x77, 0x01);
                OV7670_WR_Reg(0x3D, 0xC0);
                OV7670_WR_Reg(0x4B, 0x09);
                OV7670_WR_Reg(0xC9, 0x60);
                OV7670_WR_Reg(0x41, 0x38);
                OV7670_WR_Reg(0x56, 0x40);
                OV7670_WR_Reg(0x34, 0x11);
                OV7670_WR_Reg(0x3b, 0x02);
                OV7670_WR_Reg(0xa4, 0x88);        //disable  night mode
                OV7670_WR_Reg(0x92, 0x00);
                OV7670_WR_Reg(0x96, 0x00);
                OV7670_WR_Reg(0x97, 0x30);
                OV7670_WR_Reg(0x98, 0x20);
                OV7670_WR_Reg(0x99, 0x20);
                OV7670_WR_Reg(0x9A, 0x84);
                OV7670_WR_Reg(0x9B, 0x29);
                OV7670_WR_Reg(0x9C, 0x03);
                OV7670_WR_Reg(0x9D, 0x99);
                OV7670_WR_Reg(0x9E, 0x7F);
                OV7670_WR_Reg(0x78, 0x00);
                OV7670_WR_Reg(0x79, 0x01);
                OV7670_WR_Reg(0xc8, 0xf0);
                OV7670_WR_Reg(0x79, 0x0f);
                OV7670_WR_Reg(0xc8, 0x00);
                OV7670_WR_Reg(0x79, 0x10);
                OV7670_WR_Reg(0xc8, 0x7e);
                OV7670_WR_Reg(0x79, 0x0a);
                OV7670_WR_Reg(0xc8, 0x80);
                OV7670_WR_Reg(0x79, 0x0b);
                OV7670_WR_Reg(0xc8, 0x01);
                OV7670_WR_Reg(0x79, 0x0c);
                OV7670_WR_Reg(0xc8, 0x0f);
                OV7670_WR_Reg(0x79, 0x0d);
                OV7670_WR_Reg(0xc8, 0x20);
                OV7670_WR_Reg(0x79, 0x09);
                OV7670_WR_Reg(0xc8, 0x80);
                OV7670_WR_Reg(0x79, 0x02);
                OV7670_WR_Reg(0xc8, 0xc0);
                OV7670_WR_Reg(0x79, 0x03);
                OV7670_WR_Reg(0xc8, 0x40);
                OV7670_WR_Reg(0x79, 0x05);
                OV7670_WR_Reg(0xc8, 0x30);
                OV7670_WR_Reg(0x79, 0x26);
                OV7670_WR_Reg(0x3b, 0x02);
                OV7670_WR_Reg(0x43, 0x02);
                OV7670_WR_Reg(0x44, 0xf2);
                OV7670_WR_Reg(0x30, 0x4F);
               
                OV7670_WR_Reg(0x09, 0x00);	
}

void Set_Cmos7670Reg(void)
{


//	OV7670_WR_Reg(0x3a, 0x04);
//	OV7670_WR_Reg(0x40, 0xd0);
//	OV7670_WR_Reg(0x12, 0x14);
//	OV7670_WR_Reg(0x32, 0x80);
//	OV7670_WR_Reg(0x17, 0x16);
//	OV7670_WR_Reg(0x18, 0x04);
//	OV7670_WR_Reg(0x19, 0x02);
//	OV7670_WR_Reg(0x1a, 0x7b);
//	OV7670_WR_Reg(0x03, 0x06);
//	OV7670_WR_Reg(0x0c, 0x04);
//	OV7670_WR_Reg(0x3e, 0x00);
//	OV7670_WR_Reg(0x70, 0x3a);
//	OV7670_WR_Reg(0x71, 0x35);
//	OV7670_WR_Reg(0x72, 0x11);
//	OV7670_WR_Reg(0x73, 0x00);
//	OV7670_WR_Reg(0xa2, 0x02);
//	OV7670_WR_Reg(0x11, 0x81);
//	
//	OV7670_WR_Reg(0x7a, 0x20);
//	OV7670_WR_Reg(0x7b, 0x1c);
//	OV7670_WR_Reg(0x7c, 0x28);
//	OV7670_WR_Reg(0x7d, 0x3c);
//	OV7670_WR_Reg(0x7e, 0x55);
//	OV7670_WR_Reg(0x7f, 0x68);
//	OV7670_WR_Reg(0x80, 0x76);
//	OV7670_WR_Reg(0x81, 0x80);
//	OV7670_WR_Reg(0x82, 0x88);
//	OV7670_WR_Reg(0x83, 0x8f);
//	OV7670_WR_Reg(0x84, 0x96);
//	OV7670_WR_Reg(0x85, 0xa3);
//	OV7670_WR_Reg(0x86, 0xaf);
//	OV7670_WR_Reg(0x87, 0xc4);
//	OV7670_WR_Reg(0x88, 0xd7);
//	OV7670_WR_Reg(0x89, 0xe8);
//	
//	OV7670_WR_Reg(0x13, 0xe0);
//	OV7670_WR_Reg(0x00, 0x00);
//	
//	OV7670_WR_Reg(0x10, 0x00);
//	OV7670_WR_Reg(0x0d, 0x00);
//	OV7670_WR_Reg(0x14, 0x28);
//	OV7670_WR_Reg(0xa5, 0x05);
//	OV7670_WR_Reg(0xab, 0x07);
//	OV7670_WR_Reg(0x24, 0x75);
//	OV7670_WR_Reg(0x25, 0x63);
//	OV7670_WR_Reg(0x26, 0xA5);
//	OV7670_WR_Reg(0x9f, 0x78);
//	OV7670_WR_Reg(0xa0, 0x68);
//	OV7670_WR_Reg(0xa1, 0x03);
//	OV7670_WR_Reg(0xa6, 0xdf);
//	OV7670_WR_Reg(0xa7, 0xdf);
//	OV7670_WR_Reg(0xa8, 0xf0);
//	OV7670_WR_Reg(0xa9, 0x90);
//	OV7670_WR_Reg(0xaa, 0x94);
//	OV7670_WR_Reg(0x13, 0xe5);

//	OV7670_WR_Reg(0x0e, 0x61);
//	OV7670_WR_Reg(0x0f, 0x4b);
//	OV7670_WR_Reg(0x16, 0x02);
//	OV7670_WR_Reg(0x1e, 0x07);
//	OV7670_WR_Reg(0x21, 0x02);
//	OV7670_WR_Reg(0x22, 0x91);
//	OV7670_WR_Reg(0x29, 0x07);
//	OV7670_WR_Reg(0x33, 0x0b);
//	OV7670_WR_Reg(0x35, 0x0b);
//	OV7670_WR_Reg(0x37, 0x1d);
//	OV7670_WR_Reg(0x38, 0x71);
//	OV7670_WR_Reg(0x39, 0x2a);
//	OV7670_WR_Reg(0x3c, 0x78);
//	OV7670_WR_Reg(0x4d, 0x40);
//	OV7670_WR_Reg(0x4e, 0x20);
//	OV7670_WR_Reg(0x69, 0x00);
//	OV7670_WR_Reg(0x6b, 0x60);
//	OV7670_WR_Reg(0x74, 0x19);
//	OV7670_WR_Reg(0x8d, 0x4f);
//	OV7670_WR_Reg(0x8e, 0x00);
//	OV7670_WR_Reg(0x8f, 0x00);
//	OV7670_WR_Reg(0x90, 0x00);
//	OV7670_WR_Reg(0x91, 0x00);
//	OV7670_WR_Reg(0x92, 0x00);
//	OV7670_WR_Reg(0x96, 0x00);
//	OV7670_WR_Reg(0x9a, 0x80);
//	OV7670_WR_Reg(0xb0, 0x84);
//	OV7670_WR_Reg(0xb1, 0x0c);
//	OV7670_WR_Reg(0xb2, 0x0e);
//	OV7670_WR_Reg(0xb3, 0x82);
//	OV7670_WR_Reg(0xb8, 0x0a);



//	OV7670_WR_Reg(0x43, 0x14);
//	OV7670_WR_Reg(0x44, 0xf0);
//	OV7670_WR_Reg(0x45, 0x34);
//	OV7670_WR_Reg(0x46, 0x58);
//	OV7670_WR_Reg(0x47, 0x28);
//	OV7670_WR_Reg(0x48, 0x3a);
//	OV7670_WR_Reg(0x59, 0x88);
//	OV7670_WR_Reg(0x5a, 0x88);
//	OV7670_WR_Reg(0x5b, 0x44);
//	OV7670_WR_Reg(0x5c, 0x67);
//	OV7670_WR_Reg(0x5d, 0x49);
//	OV7670_WR_Reg(0x5e, 0x0e);
//	OV7670_WR_Reg(0x64, 0x04);
//	OV7670_WR_Reg(0x65, 0x20);
//	OV7670_WR_Reg(0x66, 0x05);
//	OV7670_WR_Reg(0x94, 0x04);
//	OV7670_WR_Reg(0x95, 0x08);
//	OV7670_WR_Reg(0x6c, 0x0a);
//	OV7670_WR_Reg(0x6d, 0x55);
//	OV7670_WR_Reg(0x6e, 0x11);
//	OV7670_WR_Reg(0x6f, 0x9f);
//	OV7670_WR_Reg(0x6a, 0x40);
//	OV7670_WR_Reg(0x01, 0x40);
//	OV7670_WR_Reg(0x02, 0x40);
//	OV7670_WR_Reg(0x13, 0xe7);
//	OV7670_WR_Reg(0x15, 0x00);  
//	
//	
//	OV7670_WR_Reg(0x4f, 0x80);
//	OV7670_WR_Reg(0x50, 0x80);
//	OV7670_WR_Reg(0x51, 0x00);
//	OV7670_WR_Reg(0x52, 0x22);
//	OV7670_WR_Reg(0x53, 0x5e);
//	OV7670_WR_Reg(0x54, 0x80);
//	OV7670_WR_Reg(0x58, 0x9e);
//	
//	OV7670_WR_Reg(0x41, 0x08);
//	OV7670_WR_Reg(0x3f, 0x00);
//	OV7670_WR_Reg(0x75, 0x05);
//	OV7670_WR_Reg(0x76, 0xe1);
//	OV7670_WR_Reg(0x4c, 0x00);
//	OV7670_WR_Reg(0x77, 0x01);
//	OV7670_WR_Reg(0x3d, 0xc2);	
//	OV7670_WR_Reg(0x4b, 0x09);
//	OV7670_WR_Reg(0xc9, 0x60);
//	OV7670_WR_Reg(0x41, 0x38);
//	OV7670_WR_Reg(0x56, 0x40);
//	
//	OV7670_WR_Reg(0x34, 0x11);
//	OV7670_WR_Reg(0x3b, 0x02); 
//								
//	OV7670_WR_Reg(0xa4, 0x89);
//	OV7670_WR_Reg(0x96, 0x00);
//	OV7670_WR_Reg(0x97, 0x30);
//	OV7670_WR_Reg(0x98, 0x20);
//	OV7670_WR_Reg(0x99, 0x30);
//	OV7670_WR_Reg(0x9a, 0x84);
//	OV7670_WR_Reg(0x9b, 0x29);
//	OV7670_WR_Reg(0x9c, 0x03);
//	OV7670_WR_Reg(0x9d, 0x4c);
//	OV7670_WR_Reg(0x9e, 0x3f);
//	OV7670_WR_Reg(0x78, 0x04);
//	
//	OV7670_WR_Reg(0x79, 0x01);
//	OV7670_WR_Reg(0xc8, 0xf0);
//	OV7670_WR_Reg(0x79, 0x0f);
//	OV7670_WR_Reg(0xc8, 0x00);
//	OV7670_WR_Reg(0x79, 0x10);
//	OV7670_WR_Reg(0xc8, 0x7e);
//	OV7670_WR_Reg(0x79, 0x0a);
//	OV7670_WR_Reg(0xc8, 0x80);
//	OV7670_WR_Reg(0x79, 0x0b);
//	OV7670_WR_Reg(0xc8, 0x01);
//	OV7670_WR_Reg(0x79, 0x0c);
//	OV7670_WR_Reg(0xc8, 0x0f);
//	OV7670_WR_Reg(0x79, 0x0d);
//	OV7670_WR_Reg(0xc8, 0x20);
//	OV7670_WR_Reg(0x79, 0x09);
//	OV7670_WR_Reg(0xc8, 0x80);
//	OV7670_WR_Reg(0x79, 0x02);
//	OV7670_WR_Reg(0xc8, 0xc0);
//	OV7670_WR_Reg(0x79, 0x03);
//	OV7670_WR_Reg(0xc8, 0x40);
//	OV7670_WR_Reg(0x79, 0x05);
//	OV7670_WR_Reg(0xc8, 0x30);
//	OV7670_WR_Reg(0x79, 0x26); 
//	OV7670_WR_Reg(0x09, 0x00);	
//	
	
	

//	flag=0;
	OV7670_WR_Reg(0x3a, 0x04);
	OV7670_WR_Reg(0x40, 0xd0);
	OV7670_WR_Reg(0x12, 0x14);
	OV7670_WR_Reg(0x32, 0x80);
	OV7670_WR_Reg(0x17, 0x16);
	OV7670_WR_Reg(0x18, 0x04);
	OV7670_WR_Reg(0x19, 0x02);
	OV7670_WR_Reg(0x1a, 0x7b);
	OV7670_WR_Reg(0x03, 0x06);
	OV7670_WR_Reg(0x0c, 0x04);
	OV7670_WR_Reg(0x3e, 0x00);
	OV7670_WR_Reg(0x70, 0x3a);
	OV7670_WR_Reg(0x71, 0x35);
	OV7670_WR_Reg(0x72, 0x11);
	OV7670_WR_Reg(0x73, 0x00);
	OV7670_WR_Reg(0xa2, 0x02);
	OV7670_WR_Reg(0x11, 0x81);
	
	OV7670_WR_Reg(0x7a, 0x20);
	OV7670_WR_Reg(0x7b, 0x1c);
	OV7670_WR_Reg(0x7c, 0x28);
	OV7670_WR_Reg(0x7d, 0x3c);
	OV7670_WR_Reg(0x7e, 0x55);
	OV7670_WR_Reg(0x7f, 0x68);
	OV7670_WR_Reg(0x80, 0x76);
	OV7670_WR_Reg(0x81, 0x80);
	OV7670_WR_Reg(0x82, 0x88);
	OV7670_WR_Reg(0x83, 0x8f);
	OV7670_WR_Reg(0x84, 0x96);
	OV7670_WR_Reg(0x85, 0xa3);
	OV7670_WR_Reg(0x86, 0xaf);
	OV7670_WR_Reg(0x87, 0xc4);
	OV7670_WR_Reg(0x88, 0xd7);
	OV7670_WR_Reg(0x89, 0xe8);
	
	OV7670_WR_Reg(0x13, 0xe0);
	OV7670_WR_Reg(0x00, 0x00);
	
	OV7670_WR_Reg(0x10, 0x00);
	OV7670_WR_Reg(0x0d, 0x00);
	OV7670_WR_Reg(0x14, 0x28);
	OV7670_WR_Reg(0xa5, 0x05);
	OV7670_WR_Reg(0xab, 0x07);
	OV7670_WR_Reg(0x24, 0x75);
	OV7670_WR_Reg(0x25, 0x63);
	OV7670_WR_Reg(0x26, 0xA5);
	OV7670_WR_Reg(0x9f, 0x78);
	OV7670_WR_Reg(0xa0, 0x68);
	OV7670_WR_Reg(0xa1, 0x03);
	OV7670_WR_Reg(0xa6, 0xdf);
	OV7670_WR_Reg(0xa7, 0xdf);
	OV7670_WR_Reg(0xa8, 0xf0);
	OV7670_WR_Reg(0xa9, 0x90);
	OV7670_WR_Reg(0xaa, 0x94);
	OV7670_WR_Reg(0x13, 0xe5);

	OV7670_WR_Reg(0x0e, 0x61);
	OV7670_WR_Reg(0x0f, 0x4b);
	OV7670_WR_Reg(0x16, 0x02);
	OV7670_WR_Reg(0x1e, 0x27);
	OV7670_WR_Reg(0x21, 0x02);
	OV7670_WR_Reg(0x22, 0x91);
	OV7670_WR_Reg(0x29, 0x07);
	OV7670_WR_Reg(0x33, 0x0b);
	OV7670_WR_Reg(0x35, 0x0b);
	OV7670_WR_Reg(0x37, 0x1d);
	OV7670_WR_Reg(0x38, 0x71);
	OV7670_WR_Reg(0x39, 0x2a);
	OV7670_WR_Reg(0x3c, 0x78);
	OV7670_WR_Reg(0x4d, 0x40);
	OV7670_WR_Reg(0x4e, 0x20);
	OV7670_WR_Reg(0x69, 0x00);
	OV7670_WR_Reg(0x6b, 0x60);
	OV7670_WR_Reg(0x74, 0x19);
	OV7670_WR_Reg(0x8d, 0x4f);
	OV7670_WR_Reg(0x8e, 0x00);
	OV7670_WR_Reg(0x8f, 0x00);
	OV7670_WR_Reg(0x90, 0x00);
	OV7670_WR_Reg(0x91, 0x00);
	OV7670_WR_Reg(0x92, 0x00);
	OV7670_WR_Reg(0x96, 0x00);
	OV7670_WR_Reg(0x9a, 0x80);
	OV7670_WR_Reg(0xb0, 0x84);
	OV7670_WR_Reg(0xb1, 0x0c);
	OV7670_WR_Reg(0xb2, 0x0e);
	OV7670_WR_Reg(0xb3, 0x82);
	OV7670_WR_Reg(0xb8, 0x0a);



	OV7670_WR_Reg(0x43, 0x14);
	OV7670_WR_Reg(0x44, 0xf0);
	OV7670_WR_Reg(0x45, 0x34);
	OV7670_WR_Reg(0x46, 0x58);
	OV7670_WR_Reg(0x47, 0x28);
	OV7670_WR_Reg(0x48, 0x3a);
	OV7670_WR_Reg(0x59, 0x88);
	OV7670_WR_Reg(0x5a, 0x88);
	OV7670_WR_Reg(0x5b, 0x44);
	OV7670_WR_Reg(0x5c, 0x67);
	OV7670_WR_Reg(0x5d, 0x49);
	OV7670_WR_Reg(0x5e, 0x0e);
	OV7670_WR_Reg(0x64, 0x04);
	OV7670_WR_Reg(0x65, 0x20);
	OV7670_WR_Reg(0x66, 0x05);
	OV7670_WR_Reg(0x94, 0x04);
	OV7670_WR_Reg(0x95, 0x08);
	OV7670_WR_Reg(0x6c, 0x0a);
	OV7670_WR_Reg(0x6d, 0x55);
	OV7670_WR_Reg(0x6e, 0x11);
	OV7670_WR_Reg(0x6f, 0x9f);
	OV7670_WR_Reg(0x6a, 0x40);
	OV7670_WR_Reg(0x01, 0x40);
	OV7670_WR_Reg(0x02, 0x40);
	OV7670_WR_Reg(0x13, 0xe7);
	OV7670_WR_Reg(0x15, 0x00);  
	
	
	OV7670_WR_Reg(0x4f, 0x80);
	OV7670_WR_Reg(0x50, 0x80);
	OV7670_WR_Reg(0x51, 0x00);
	OV7670_WR_Reg(0x52, 0x22);
	OV7670_WR_Reg(0x53, 0x5e);
	OV7670_WR_Reg(0x54, 0x80);
	OV7670_WR_Reg(0x58, 0x9e);
	
	OV7670_WR_Reg(0x41, 0x08);
	OV7670_WR_Reg(0x3f, 0x00);
	OV7670_WR_Reg(0x75, 0x05);
	OV7670_WR_Reg(0x76, 0xe1);
	OV7670_WR_Reg(0x4c, 0x00);
	OV7670_WR_Reg(0x77, 0x01);
	OV7670_WR_Reg(0x3d, 0xc2);	
	OV7670_WR_Reg(0x4b, 0x09);
	OV7670_WR_Reg(0xc9, 0x60);
	OV7670_WR_Reg(0x41, 0x38);
	OV7670_WR_Reg(0x56, 0x40);
	
	OV7670_WR_Reg(0x34, 0x11);
	OV7670_WR_Reg(0x3b, 0x02); 
								
	OV7670_WR_Reg(0xa4, 0x89);
	OV7670_WR_Reg(0x96, 0x00);
	OV7670_WR_Reg(0x97, 0x30);
	OV7670_WR_Reg(0x98, 0x20);
	OV7670_WR_Reg(0x99, 0x30);
	OV7670_WR_Reg(0x9a, 0x84);
	OV7670_WR_Reg(0x9b, 0x29);
	OV7670_WR_Reg(0x9c, 0x03);
	OV7670_WR_Reg(0x9d, 0x4c);
	OV7670_WR_Reg(0x9e, 0x3f);
	OV7670_WR_Reg(0x78, 0x04);
	
	
		
	
}

/**
  * @brief  初始化OV7670
  * @param  None
  * @retval	返回成功或失败
	*		#OV7670_False：失败
	*		#OV7670_True：成功
  */
OV7670_BoolTypeDef OV7670_Init(void)
{
//	uint16_t i;
	
	SCCB_Init();
	
	HAL_Delay(1000);
	
	if(OV7670_WR_Reg(0x12, 0x80) == OV7670_False)
	{
		return OV7670_False;
	}
//	
	OV7670_DelayMs(10);
	
//	for(i = 0; i < sizeof(OV7670_REG_INIT_TABLE)/sizeof(OV7670_REG_INIT_TABLE[0]); i++)
//	{
//		if(OV7670_WR_Reg(OV7670_REG_INIT_TABLE[i][0], OV7670_REG_INIT_TABLE[i][1]) == OV7670_False)
//			return OV7670_False;
//	}
	
	Set_Cmos7670Reg();
	//Set_Cmos7670RegVGA();
	
	//OV7670_Window_Set(12,176,240,320);
	
	return OV7670_True;
}


/**
  * @brief  写OV7670寄存器
  * @param  RegAddr：寄存器地址
	*	@param	RegData：寄存器数据
  * @retval	返回成功或失败
	*		#OV7670_False：失败
	*		#OV7670_True：成功
  */
OV7670_BoolTypeDef OV7670_WR_Reg(uint8_t RegAddr, uint8_t RegData)
{
	SCCB_Start();
	if(SCCB_WR_Byte(OV7670_SCCB_ADDRESS) == SCCB_False)
	{
		SCCB_Stop();
		return OV7670_False;
	}
	OV7670_Delay();
	if(SCCB_WR_Byte(RegAddr) == SCCB_False)
	{
		SCCB_Stop();
		return OV7670_False;
	}
	OV7670_Delay();
	if(SCCB_WR_Byte(RegData) == SCCB_False)
	{
		SCCB_Stop();
		return OV7670_False;
	}
	SCCB_Stop();
	return OV7670_True;
}



/**
  * @brief  读OV7670寄存器
  * @param  RegAddr：寄存器地址
  * @retval	读取的值
  */
uint8_t OV7670_RD_Reg(uint8_t RegAddr)
{
	uint8_t val=0;
	SCCB_Start(); 				//启动SCCB传输
	SCCB_WR_Byte(OV7670_SCCB_ADDRESS);		//写器件ID	  
	OV7670_Delay();	 
  	SCCB_WR_Byte(RegAddr);			//写寄存器地址	  
	OV7670_Delay();	  
	SCCB_Stop();   
	OV7670_Delay();	   
	//设置寄存器地址后，才是读
	SCCB_Start();
	SCCB_WR_Byte(OV7670_SCCB_ADDRESS|0X01);	//发送读命令	  
	OV7670_Delay();
  	val=SCCB_RD_Byte();		 	//读取数据
  	SCCB_No_Ack();
  	SCCB_Stop();
  	return val;
}



/**
  * @brief  OV7670的毫秒延时
  * @param  Ms：延时参数
  * @retval None
  */
static void OV7670_DelayMs(uint16_t Ms)
{
	HAL_Delay(Ms);
}


/**
  * @brief  延时
  * @param  None
  * @retval None
	*	@note		IIC延时函数，实际测试约为12us
  */
static void OV7670_Delay(void)
{
	volatile uint16_t i;
	
	for(i=0;i<1000;i++);
//	for(i=0;i<100;i++);	
}

///**
//  * @brief  延时
//  * @param  None
//  * @retval None
//	*	@note		IIC延时函数，实际测试约为6us
//  */
//static void OV7670_Delay(void)
//{
//	volatile uint16_t i;
//	
//	for(i=0;i<500;i++);	
//}




//设置图像输出窗口
//对QVGA设置。
void OV7670_Window_Set(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height)
{
	uint16_t endx;
	uint16_t endy;
	uint8_t temp; 
	endx=sx+width*2;	//V*2
 	endy=sy+height*2;
	if(endy>784)endy-=784;
	temp=OV7670_RD_Reg(0X03);				//读取Vref之前的值
	temp&=0XF0;
	temp|=((endx&0X03)<<2)|(sx&0X03);
	OV7670_WR_Reg(0X03,temp);				//设置Vref的start和end的最低2位
	OV7670_WR_Reg(0X19,sx>>2);			//设置Vref的start高8位
	OV7670_WR_Reg(0X1A,endx>>2);			//设置Vref的end的高8位

	temp=OV7670_RD_Reg(0X32);				//读取Href之前的值
	temp&=0XC0;
	temp|=((endy&0X07)<<3)|(sy&0X07);
	OV7670_WR_Reg(0X17,sy>>3);			//设置Href的start高8位
	OV7670_WR_Reg(0X18,endy>>3);			//设置Href的end的高8位
}

