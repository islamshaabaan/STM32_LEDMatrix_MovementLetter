/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   RCC                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB1            1
#define RCC_APB1            2
#define RCC_APB2            3 

/*  AHB1 Peripherals ID  */
#define RCC_AHB1_GPIOA          0
#define RCC_AHB1_GPIOB          1
#define RCC_AHB1_GPIOC          2
#define RCC_AHB1_CRC			12
#define RCC_AHB1_DMA1           21
#define RCC_AHB1_DMA2           22

/*  AHB2 Peripherals ID  */
#define RCC_AHB2_OTGFS			7

/*	APB1 Peripherals ID	  */
#define RCC_APB1_TIM2          	0
#define RCC_APB1_TIM3          	1
#define RCC_APB1_TIM4			2
#define RCC_APB1_TIM5           3
#define RCC_APB1_WWDG			11
#define RCC_APB1_SPI2           14
#define RCC_APB1_SPI3           15
#define RCC_APB1_USART2         17
#define RCC_APB1_I2C1           21
#define RCC_APB1_I2C2           22
#define RCC_APB1_I2C3           23
#define RCC_APB1_PWR            28 // Power Interface Clock

/*	APB2 Peripherals ID	  */
#define RCC_APB2_TIM1          	0
#define RCC_APB2_USART1         4
#define RCC_APB2_USART2			5
#define RCC_APB2_ADC1           8
#define RCC_APB2_SDIO			11
#define RCC_APB2_SPI1           12
#define RCC_APB2_SPI4           13
#define RCC_APB2_SYSCFG         14
#define RCC_APB2_TIM9           16
#define RCC_APB2_TIM10          17
#define RCC_APB2_TIM11          18



void RCC_voidInit   (void);

u8 RCC_u8EnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );

u8 RCC_u8DisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );



#endif

