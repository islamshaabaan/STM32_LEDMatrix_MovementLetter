/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   NVIC                               */
/*      Date    :   5/9/2023                          */
/*      version :       1.00                          */
/******************************************************/







#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

/* Interrupt Position from vector table */
typedef enum {
    WWDG                = 0 ,
    EXTI16              = 1 ,
    EXTI21              = 2 ,
    EXTI22              = 3 ,
    FLASH               = 4 ,
    RCC                 = 5 ,
    EXTI0                = 6 ,
    EXTI1               = 7 ,
    EXTI2               = 8 ,
    EXTI3               = 9 ,
    EXTI4               = 10,
    DMA1_STREAM0        = 11,
    DMA1_STREAM1        = 12,
    DMA1_STREAM2        = 13,
    DMA1_STREAM3        = 14,
    DMA1_STREAM4        = 15,
    DMA1_STREAM5        = 16,
    DMA1_STREAM6        = 17,
    ADC                 = 18,
    EXTI9               = 23,
    TIM1_BRK_TIM9       = 24,
    TIM1_UP_TIM10       = 25,
    TIM1_TRG_COM_TIM11  = 26,
    TIM1_CC             = 27,
    TIM2                = 28,
    TIM3                = 29,
    TIM4                = 30,
    I2C1_EV             = 31,
    I2C1_ER             = 32,
    I2C2_EV             = 33,
    I2C2_ER             = 34,
    SPI1                = 35,
    SPI2                = 36,
    USART1              = 37,
    USART2              = 38,
    EXTI15_10           = 40,
    EXTI17              = 41,
    EXTI18              = 42,
    DMA1_STREAM7        = 47,
    SDIO                = 49,
    TIM5                = 50,
    SPI3                = 51,
    DMA2_STREAM0        = 56,
    DMA2_STREAM1        = 57,
    DMA2_STREAM2        = 58,
    DMA2_STREAM3        = 59,
    DMA2_STREAM4        = 60,
    OTG_FS              = 67,
    DMA2_STREAM5        = 68,
    DMA2_STREAM6        = 69,
    DMA2_STREAM7        = 70,
    USART6              = 71,
    I2C3_EV             = 72,
    I2C3_ER             = 73,
    FPU                 = 81,
    SPI4                = 84,
}Postion_E;


#define GROUP_4BITS		0b011
#define GROUP_3BITS		0b100
#define GROUP_2BITS		0b101
#define GRPUP_1BITS		0b110
#define GROUP_0BITS		0b111

/////////////
#define PEND_SV	-6
#define SYSTICK	-5
//////////
#define SV_CALL	-4
//////////////
#define MEMORY_MANAGE	-3
#define BUS_FAULT		-2
#define USAGE_FAULT		-1
////////////////
#define WWDG			0
#define EXTI16			1

void NVIC_voidEnablePeripheral	(u8 Copy_u8IntID);

void NVIC_voidDisablePeripheral	(u8 Copy_u8IntID);


void NVIC_voidSetPendingFlag	(u8 Copy_u8IntID);

void NVIC_voidClearPendingFlag	(u8 Copy_u8IntID);

u8 NVIC_u8GetActive	(u8 Copy_u8IntID);

void NVIC_voidSetPriorityConfig	(u8 Copy_u8PriorityOption);

void NVIC_voidSetPriority	(s8 Copy_s8IntId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority);


#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
