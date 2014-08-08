/******************************************************************
**	  金龙107开发板（V1.0）
**	  外设配置文件
**
**	  论    坛：bbs.openmcu.com
**	  旺    宝：www.openmcu.com
**	  邮    箱：support@openmcu.com
**
**    版    本：V1.1
**	  作    者：openmcu
**	  完成日期:	2014.3.3
********************************************************************/
#include "hw_config.h" 

/********************************************************************************************
*函数名称：void LED_Configuration(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：LED初始化配置
*******************************************************************************************/
void LED_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_LED, ENABLE);	  //使用前打开相应的时钟
	GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_Init(LED_PORT, &GPIO_InitStructure);

	/*---------初始化状态四个LED全OFF------------*/
	LED1(0);
	LED2(0);
	LED3(0);
	LED4(0);
}



