
/************************************************************************************
**	  ����107�����壨V1.0��
**	  LED ʵ��
**
**	  ��    ̳��bbs.openmcu.com
**	  ��    ����www.openmcu.com
**	  ��    �䣺support@openmcu.com
**
**    ��    ����V1.1
**	  ��    �ߣ�openmcu
**	  �������:	2014.3.3
------------------------------------------------------------------------------------
**	�������˵��: 
**				  
**
**				 JLINK�������к� ����S3���ĸ�LED��ˮ��˸
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
*�������ƣ�void Delay(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵��������ʱ
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
//stm32 ϵͳ��ʼ��
	stm32_Init();
	led_init(); 	/*led��Ϊ������	*/
	led_loop();		/*led������*/

   while(n > 0) {
    GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	spi_write_test(SPI_1, 0x55); /*spi ������*/
    GPIO_SetBits(GPIOD, GPIO_Pin_2);
	Delay();
	n--;
}
//tcp/udp serverʹ��
//	simple_server();
	while(1);
}





#if 0
int fputc(int ch, FILE *f)
{
  USART_SendData(USART1, (uint8_t) ch);   					   //����һ���ַ�
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)   //�ȴ��������
  {}

  return ch;
}

 #endif
