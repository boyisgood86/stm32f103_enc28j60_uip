#include <stm32f10x.h>
#include <stm32f10x_spi.h>
#include "spi.h"


/*初始化*/
/*
SPI1 在F107上的引脚对应为：
NSS ---PA4
SCK ---PA5
MISO---PA6
MOSI---PA7
*/
void SPI1_Init(void)
{

   SPI_InitTypeDef SPI_InitStructure;		/*创建spi数据结构体*/
   GPIO_InitTypeDef GPIO_InitStructure;		/*创建spi需要使用到的GPIO口之数据结构体*/

   /* Enable SPI1 and GPIOA clocks */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); /*使能SPI1时钟-->将外部APB2的时钟作为SPI的时钟使用，具体参考API*/
   /*使能SPI对应的GPIO口的时钟，情况同SPI的方法一样*/
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC\
   						|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE, ENABLE);
 
//   //PC12 ---CS
//   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_10;  /*选择引脚*/
//   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  /*选择速率*/
//   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			/*选择GPIO口模式*/
//   GPIO_Init(GPIOC, &GPIO_InitStructure);					/*将数据结构写入GPIO C口进行初始化*/
  
	//	SPI1-
	//	PA5--SCK----SCK
	//	PA6--MISO---SO
	//	PA7--MOSI---SI 	 
   /* Configure SPI1 pins: NSS, SCK, MISO and MOSI */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	 /*选择引脚*/
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					 /*选择速率*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;						 /*GPIO口的输入输出模式*/
   GPIO_Init(GPIOA, &GPIO_InitStructure);								 /*将数据结构体写入I/O口A*/

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;							 /*选择引脚*/
   GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU;   //上拉输入			 /*GPIO口模式*/
   GPIO_Init(GPIOA, &GPIO_InitStructure);								  /*写入数据结构体*/

   /* SPI1 configuration */ 
   SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;	 /*SPI工作模式：双工、单工*/
   SPI_InitStructure.SPI_Mode = SPI_Mode_Master;						 /*SPI 主从模式*/
   SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;					 /*SPI 数据传输大小*/
   SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;							 /*SPI 时钟*/
   SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;							 /*SPI 相位*/
   SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;							 /*SPI 片选引脚CS，或者类似CS*/
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;	 /*SPI 时钟源，从哪里分多少资源过来(时钟分频)*/
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;					 /*SPI 传输数据的方式，MSB or LSB*/
   SPI_InitStructure.SPI_CRCPolynomial = 7;								 /*SPI 数据的CRC*/
   SPI_Init(SPI1, &SPI_InitStructure);									 /*将数据结构写入SPI硬件，进行初始化*/
   
//   /***************************************
//   PE5  --------  LED1
//   PE6  --------  LED2 
//   ****************************************/
/*
	金牛板子LED 对应为：
	LED1 --- PD2
	LED2 --- PD3
	LED3 --- PD4
	LED5 --- PD7
*/
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_7;			   /*LED 使用管教初始化*/
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			   /**/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				   /**/
   GPIO_Init(GPIOD, &GPIO_InitStructure);						   /**/
   /* Enable SPI1  */											   /*使能SPI*/
   SPI_Cmd(SPI1, ENABLE);
}

 /*SPI2 init*/
 /*
SPI2 在F107上的引脚对应为：
NSS ---PB12
SCK ---PB13
MISO---PB14
MOSI---PB15
 */
 void SPI2_Init(void)
{
   SPI_InitTypeDef SPI_InitStructure;
   GPIO_InitTypeDef GPIO_InitStructure;

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
   /* SPI2 Periph clock enable */
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

   /* Configure SPI2 pins: NSS, SCK, MISO and MOSI */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_Init(GPIOB, &GPIO_InitStructure);

   /* SPI1 configuration */ 
   SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
   SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
   SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
   SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
   SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
   SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
   SPI_InitStructure.SPI_CRCPolynomial = 7;

   SPI_Init(SPI2, &SPI_InitStructure);
   /* Enable SPI2  */
   SPI_Cmd(SPI2, ENABLE);
}

void SPI3_Init(void)
{
//TODO...
}

/*
	spi init
	spi_numer = SPI1 or SPI2 or other ...
*/
int spi_init(int spi_number)
{
	int num = spi_number;
	
	switch(num) {
		case SPI_1:
			SPI1_Init();
		//TODO...
			break;
		case SPI_2:
		//TODO...
			SPI2_Init();
			break;
		case SPI_3:
		//TODO...
			SPI3_Init();
			break;
		default:
			return -1;
	}
	return 0;
}

/**************************************************************************************************/

/*SPI1读写一字节数据*/
unsigned char SPI1_ReadWriteByte(unsigned char data_buff)
{
	unsigned char retry = 0;				 
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
	{
		retry++;
		if(retry>200)
			return 0;
	}			 
	SPI_I2S_SendData(SPI1, data_buff); //通过外设SPIx发送一个数据
	retry = 0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET); //检查指定的SPI标志位设置与否:接受缓存非空标志位
	{
		retry++;
		if(retry>200)
			return 0;
	}	  						    
	return SPI_I2S_ReceiveData(SPI1); //返回通过SPIx最近接收的数据

}


/*SPI2读写一字节数据*/
unsigned char SPI2_ReadWriteByte(unsigned char data_buff)
{
	unsigned char retry = 0;				 
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
	{
		retry++;
		if(retry>200)
			return 0;
	}			 
	SPI_I2S_SendData(SPI2, data_buff); //通过外设SPIx发送一个数据

	retry = 0;
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET); //检查指定的SPI标志位设置与否:接受缓存非空标志位
	{
		retry++;
		if(retry>200)
			return 0;
	}
	 return  SPI_I2S_ReceiveData(SPI2);
}

/*SPI3 读写一字节数据*/
unsigned char SPI3_ReadWriteByte(unsigned char data_buff)
{
//TODO...
	return 0;
}

/*SPI4 读取一字节数据*/
unsigned char SPI4_ReadWriteByte(unsigned char data_buff)
{
//TODO...
	return 0;
}

/*
	SPI write and read a Byte data.
	spi_number = SPI1 or SPI2 or other ...
	data_buff = write buff or read buff 
*/
unsigned char spi_readWriteByte(int spi_number, unsigned char data_buff)
{
//TODO...
	int num = spi_number;
	switch (num) {
		case SPI_1:
			return 	SPI1_ReadWriteByte(data_buff);
//			break;
		case SPI_2:
			return 	SPI2_ReadWriteByte(data_buff);
//			break;
		case SPI_3:
			return 	SPI3_ReadWriteByte(data_buff);
//			break;
		default:
			return (char)(-1);	  
	}
}

