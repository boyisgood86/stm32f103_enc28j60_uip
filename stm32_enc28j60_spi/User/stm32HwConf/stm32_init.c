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
	SystemInit();     	   //系统初始化
	//初始化全局buff，如果需要的话

	//初始化SPI接口
	spi_init(SPI_1);	/*初始化SPI_1*/
	spi_init(SPI_2);	/*初始化SPI_2*/
	//初始化enc28j60网卡芯片
	enc28j60Init(mac_addr);
	//初始化uip协议栈
//	init_ip_arp_udp_tcp(mac_addr, ip_addr, listen_port);
	return ;
}



