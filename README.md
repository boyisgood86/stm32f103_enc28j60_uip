stm32f103_enc28j60_uip
======================

No OS, stm32f103 - spi - enc28j60   tcp/ip statck is uip


芯片是stm32f103，通过spi外挂一个enc28j60的MAC处理器，enc28j60将接收到的TCP/ip 数据通过spi传输到103上面，103使用uip协议栈将其解析，然后再按照需要进行处理

这个代码是从网络上获取的，写了一部分应用，但是后来添加了操作系统--不再使用裸机uip，个人转向了contiki + uip 和 rt_thread + lwip / freeRTOS +lwip



Email: newleaves@126.com

2014/8/8  <整理>