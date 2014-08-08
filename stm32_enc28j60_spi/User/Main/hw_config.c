/******************************************************************
**	  ����107�����壨V1.0��
**	  ���������ļ�
**
**	  ��    ̳��bbs.openmcu.com
**	  ��    ����www.openmcu.com
**	  ��    �䣺support@openmcu.com
**
**    ��    ����V1.1
**	  ��    �ߣ�openmcu
**	  �������:	2014.3.3
********************************************************************/
#include "hw_config.h" 

/********************************************************************************************
*�������ƣ�void LED_Configuration(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����LED��ʼ������
*******************************************************************************************/
void LED_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_LED, ENABLE);	  //ʹ��ǰ����Ӧ��ʱ��
	GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_Init(LED_PORT, &GPIO_InitStructure);

	/*---------��ʼ��״̬�ĸ�LEDȫOFF------------*/
	LED1(0);
	LED2(0);
	LED3(0);
	LED4(0);
}



