
/*
	这个文件里只是存放一些测试代码，其他正式的代码并不要存放在这里
*/


#include <stm32f10x.h>
#include "enc28j60.h"
#include "spi.h"
#include "led.h"

void spi_read_from_enc28j60(void)
{
//TODO...
}

void spi_write_test(int spi_number, unsigned char data_buff)
{
	spi_readWriteByte(spi_number, data_buff);
}