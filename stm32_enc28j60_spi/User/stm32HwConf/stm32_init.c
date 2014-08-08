#include <stm32f10x.h>
#include "stm32_init.h"
#include "net.h"
#include "ip_arp_udp_tcp.h"
#include "simple_server.h"
#include "enc28j60.h"
#include "spi.h"

static unsigned char mac_addr[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};
//static unsigned char ip_addr[4] = {192, 168, 1, 100};
//static int listen_port = 80;

void stm32_Init(void)
{
	SystemInit();     	   //ϵͳ��ʼ��
	//��ʼ��ȫ��buff�������Ҫ�Ļ�

	//��ʼ��SPI�ӿ�
	spi_init(SPI_1);	/*��ʼ��SPI_1*/
	spi_init(SPI_2);	/*��ʼ��SPI_2*/
	//��ʼ��enc28j60����оƬ
	enc28j60Init(mac_addr);
	//��ʼ��uipЭ��ջ
//	init_ip_arp_udp_tcp(mac_addr, ip_addr, listen_port);
	return ;
}



