#include <stm32f10x.h>
#include "led.h"

void led_delay(void)
{
	unsigned long int n = 1000000;
	for(n = 1000000; n >= 0; n--);
}


void led_init(void)
{
//TODO..
	GPIO_ResetBits(GPIOD, GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_7);
}

void led_loop(void)
{
        GPIO_ResetBits(GPIOD, GPIO_Pin_2);
        led_delay();
        GPIO_SetBits(GPIOD, GPIO_Pin_2);
		led_delay();
		GPIO_ResetBits(GPIOD, GPIO_Pin_3);
        led_delay();
        GPIO_SetBits(GPIOD, GPIO_Pin_3);
		led_delay();
        GPIO_ResetBits(GPIOD, GPIO_Pin_4);
        led_delay();
        GPIO_SetBits(GPIOD, GPIO_Pin_4);
		led_delay();
        GPIO_ResetBits(GPIOD, GPIO_Pin_7);
        led_delay();
        GPIO_SetBits(GPIOD, GPIO_Pin_7);
		led_delay();
		GPIO_SetBits(GPIOD, GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_7);					
}