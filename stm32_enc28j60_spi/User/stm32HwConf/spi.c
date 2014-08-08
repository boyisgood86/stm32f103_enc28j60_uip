#include <stm32f10x.h>
#include <stm32f10x_spi.h>
#include "spi.h"


/*��ʼ��*/
/*
SPI1 ��F107�ϵ����Ŷ�ӦΪ��
NSS ---PA4
SCK ---PA5
MISO---PA6
MOSI---PA7
*/
void SPI1_Init(void)
{

   SPI_InitTypeDef SPI_InitStructure;		/*����spi���ݽṹ��*/
   GPIO_InitTypeDef GPIO_InitStructure;		/*����spi��Ҫʹ�õ���GPIO��֮���ݽṹ��*/

   /* Enable SPI1 and GPIOA clocks */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); /*ʹ��SPI1ʱ��-->���ⲿAPB2��ʱ����ΪSPI��ʱ��ʹ�ã�����ο�API*/
   /*ʹ��SPI��Ӧ��GPIO�ڵ�ʱ�ӣ����ͬSPI�ķ���һ��*/
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC\
   						|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE, ENABLE);
 
//   //PC12 ---CS
//   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_10;  /*ѡ������*/
//   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  /*ѡ������*/
//   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			/*ѡ��GPIO��ģʽ*/
//   GPIO_Init(GPIOC, &GPIO_InitStructure);					/*�����ݽṹд��GPIO C�ڽ��г�ʼ��*/
  
	//	SPI1-
	//	PA5--SCK----SCK
	//	PA6--MISO---SO
	//	PA7--MOSI---SI 	 
   /* Configure SPI1 pins: NSS, SCK, MISO and MOSI */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	 /*ѡ������*/
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					 /*ѡ������*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;						 /*GPIO�ڵ��������ģʽ*/
   GPIO_Init(GPIOA, &GPIO_InitStructure);								 /*�����ݽṹ��д��I/O��A*/

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;							 /*ѡ������*/
   GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU;   //��������			 /*GPIO��ģʽ*/
   GPIO_Init(GPIOA, &GPIO_InitStructure);								  /*д�����ݽṹ��*/

   /* SPI1 configuration */ 
   SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;	 /*SPI����ģʽ��˫��������*/
   SPI_InitStructure.SPI_Mode = SPI_Mode_Master;						 /*SPI ����ģʽ*/
   SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;					 /*SPI ���ݴ����С*/
   SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;							 /*SPI ʱ��*/
   SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;							 /*SPI ��λ*/
   SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;							 /*SPI Ƭѡ����CS����������CS*/
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;	 /*SPI ʱ��Դ��������ֶ�����Դ����(ʱ�ӷ�Ƶ)*/
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;					 /*SPI �������ݵķ�ʽ��MSB or LSB*/
   SPI_InitStructure.SPI_CRCPolynomial = 7;								 /*SPI ���ݵ�CRC*/
   SPI_Init(SPI1, &SPI_InitStructure);									 /*�����ݽṹд��SPIӲ�������г�ʼ��*/
   
//   /***************************************
//   PE5  --------  LED1
//   PE6  --------  LED2 
//   ****************************************/
/*
	��ţ����LED ��ӦΪ��
	LED1 --- PD2
	LED2 --- PD3
	LED3 --- PD4
	LED5 --- PD7
*/
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_7;			   /*LED ʹ�ù̳ܽ�ʼ��*/
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			   /**/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				   /**/
   GPIO_Init(GPIOD, &GPIO_InitStructure);						   /**/
   /* Enable SPI1  */											   /*ʹ��SPI*/
   SPI_Cmd(SPI1, ENABLE);
}

 /*SPI2 init*/
 /*
SPI2 ��F107�ϵ����Ŷ�ӦΪ��
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

/*SPI1��дһ�ֽ�����*/
unsigned char SPI1_ReadWriteByte(unsigned char data_buff)
{
	unsigned char retry = 0;				 
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //���ָ����SPI��־λ�������:���ͻ���ձ�־λ
	{
		retry++;
		if(retry>200)
			return 0;
	}			 
	SPI_I2S_SendData(SPI1, data_buff); //ͨ������SPIx����һ������
	retry = 0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET); //���ָ����SPI��־λ�������:���ܻ���ǿձ�־λ
	{
		retry++;
		if(retry>200)
			return 0;
	}	  						    
	return SPI_I2S_ReceiveData(SPI1); //����ͨ��SPIx������յ�����

}


/*SPI2��дһ�ֽ�����*/
unsigned char SPI2_ReadWriteByte(unsigned char data_buff)
{
	unsigned char retry = 0;				 
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) //���ָ����SPI��־λ�������:���ͻ���ձ�־λ
	{
		retry++;
		if(retry>200)
			return 0;
	}			 
	SPI_I2S_SendData(SPI2, data_buff); //ͨ������SPIx����һ������

	retry = 0;
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET); //���ָ����SPI��־λ�������:���ܻ���ǿձ�־λ
	{
		retry++;
		if(retry>200)
			return 0;
	}
	 return  SPI_I2S_ReceiveData(SPI2);
}

/*SPI3 ��дһ�ֽ�����*/
unsigned char SPI3_ReadWriteByte(unsigned char data_buff)
{
//TODO...
	return 0;
}

/*SPI4 ��ȡһ�ֽ�����*/
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

