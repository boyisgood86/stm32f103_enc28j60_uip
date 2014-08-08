#ifndef __SPI_H_
#define __SPI_H_

#define ERR		0
#define SPI_1	1
#define SPI_2	2
#define SPI_3	3

/*
	spi init
	spi_numer = SPI1 or SPI2 or other ...
*/
int spi_init(int spi_number);

/*
	SPI write and read a Byte data.
	spi_number = SPI1 or SPI2 or other ...
	data_buff = write buff or read buff 
*/
unsigned char spi_readWriteByte(int spi_number, unsigned char data_buff);

#endif /*__SPI_H_*/


