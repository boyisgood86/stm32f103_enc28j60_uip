#if !defined( _CONFIG_H )
#define _CONFIG_H

//-----------------------------------------------------------------------------------------------------
//别名区    ADDRESS=0x4200 0000 + (0x0001 100C*0x20) + (bitx*4)	;bitx:第x位
// 把“位带地址＋位序号”转换别名地址宏
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
//把该地址转换成一个指针
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))

#define BIT_ADDR(addr, bitnum)   MEM_ADDR( BITBAND(addr, bitnum)  )

#define GPIOA_ODR    (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR    (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR    (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR    (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR    (GPIOE_BASE+12) //0x4001180C

#define GPIOA_IDR    (GPIOA_BASE+8) //0x4001080C
#define GPIOB_IDR    (GPIOB_BASE+8) //0x40010C0C
#define GPIOC_IDR    (GPIOC_BASE+8) //0x4001100C
#define GPIOD_IDR    (GPIOD_BASE+8) //0x4001140C
#define GPIOE_IDR    (GPIOE_BASE+8) //0x4001180C

//#define PC13 *((volatile unsigned long  *)(0x422201B4))//((volatile unsigned long *) (0x422201B4))
#define PC13  BIT_ADDR(GPIOC_ODR, 13) //输出
#define PC12  BIT_ADDR(GPIOC_ODR, 12) //输出
#define PC11  BIT_ADDR(GPIOC_ODR, 11) //输出
#define PC10  BIT_ADDR(GPIOC_ODR, 10) //输出
#define PC9   BIT_ADDR(GPIOC_ODR, 9) //输出
#define PC8   BIT_ADDR(GPIOC_ODR, 8) //输出
/*************************************/
#define PE5   BIT_ADDR(GPIOE_ODR, 5) //输出
#define PE6   BIT_ADDR(GPIOE_ODR, 6) //输出
//*************************************
#define PB0   BIT_ADDR(GPIOB_ODR, 0) //输出
#define PB1   BIT_ADDR(GPIOB_ODR, 1) //输出

#define PB10in  BIT_ADDR(GPIOB_IDR, 10) //输入
#define PB11in  BIT_ADDR(GPIOB_IDR, 11) //输入

#define PD2in   BIT_ADDR(GPIOD_IDR, 2)  //输入

//-----------------------------------------------------------------------------------------------------

//#define  myGPIO_SetBits(PORT, Bit)     SetBit32(PORT->ODR, Bit)
//#define  myGPIO_ResetBits(PORT, Bit)   ClrBit32(PORT->ODR, Bit)

//#define  myGPIO_SetBits(PORT, Bit)     GPIO_SetBits(PORT, BIT16(Bit))
//#define  myGPIO_ResetBits(PORT, Bit)   GPIO_ResetBits(PORT, BIT16(Bit))

#define  myGPIO_SetBits(PORT, Bit)     ( PORT->BSRR=BIT16(Bit) )
#define  myGPIO_ResetBits(PORT, Bit)   ( PORT->BRR=BIT16(Bit) )

//485配置-------------------------------------------------------------
/******************* 定义与PC机的通讯为485 ****************/
#define PC_RS485
/******************* 定义与控制器的通讯为485 ****************/
#define RS485

//硬件函数
#define  RCC_APB2Periph_PC_RS485DIR  RCC_APB2Periph_GPIOB
#define  PC_RS485DIR_PORT    GPIOB
#define  PC_RS485DIR_PIN     0

#ifdef PC_RS485
  #define PC_RS485Send_Enable()     myGPIO_SetBits(PC_RS485DIR_PORT, PC_RS485DIR_PIN)
  #define PC_RS485Receive_Enable()  myGPIO_ResetBits(PC_RS485DIR_PORT, PC_RS485DIR_PIN)

#else
  #define PC_RS485Send_Enable()     
  #define PC_RS485Receive_Enable()  

#endif
//--------------------------------------------------------------------

//LED配置-------------------------------------------------------------
#define  RCC_APB2Periph_LED  RCC_APB2Periph_GPIOC
#define LED_PORT    GPIOC  //GPIOC
#define LED_PIN    13  
  
  #define LED_Green_ON()   myGPIO_ResetBits(LED_PORT, LED_PIN)//SetBit32(LEDPORT->ODR, 13)
  #define LED_Green_OFF()  myGPIO_SetBits(LED_PORT, LED_PIN)//ClrBit32(LEDPORT->ODR, 13)


#endif
