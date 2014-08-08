
/************************************************************************************
**	  金龙107开发板（V1.0）
**	  LED 实验
**
**	  论    坛：bbs.openmcu.com
**	  旺    宝：www.openmcu.com
**	  邮    箱：support@openmcu.com
**
**    版    本：V1.1
**	  作    者：openmcu
**	  完成日期:	2014.3.3
------------------------------------------------------------------------------------
**	程序测试说明: 
**				  
**
**				 JLINK下载运行后， 按下S3，四个LED流水闪烁
**			  		   
**                                
************************************************************************************/
#include <stm32f10x.h>
#include "stm32_init.h"
#include "enc28j60.h"
#include "config.h"
#include "simple_server.h"
#include "ip_arp_udp_tcp.h"
#include "net.h"
#include "spi.h"
#include "led.h"
#include "test.h"

/**************************************************
*函数名称：void Delay(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：简单延时
***************************************************/
#if 1
void Delay(void)
{
	int x,y;
	for(x=1000;x>0;x--)
		for(y=1000;y>0;y--);

}

#endif /*delay*/


int main(void)
{
unsigned n = 100;
//stm32 系统初始化
	stm32_Init();
	led_init(); 	/*led作为测试用	*/
	led_loop();		/*led测试用*/

   while(n > 0) {
    GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	spi_write_test(SPI_1, 0x55); /*spi 读测试*/
    GPIO_SetBits(GPIOD, GPIO_Pin_2);
	Delay();
	n--;
}
//tcp/udp server使用
//	simple_server();
	while(1);
}





#if 0
int fputc(int ch, FILE *f)
{
  USART_SendData(USART1, (uint8_t) ch);   					   //发送一个字符
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)   //等待传输结束
  {}

  return ch;
}

 #endif
