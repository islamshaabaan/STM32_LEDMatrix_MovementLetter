/******************************************************/
/*      Author  : Mohamed k Elfawakhry                */
/*      SWC     :   RCC                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

/* LIB  */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*  RCC */
#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

/*
 * Address Offset is 0x00
 * HSI_(ON/OFF) bit, must be 1, Initial = 1.
 * HSI_RDY bit: is a [R] flag to be = 1, if i got 16 MHz, Initial = 0.
 * HSI_TRIM[4:0] bits: to adjust the tolerance of 16 MHz to be 16 MHz +x [R/W].
 * 						default = 10000 = 16.
 * HSI_CAL[7:0] bits: to calibration the clock by HW [only R].
 * 		Ex1:
 * 			RC = 16 MHz +- 120KHz
 * 				1 - HSI_CAL = + 80KHz
 * 				2 - HSI_TRIM = 10000 = 16 by default.
 * 					As each step = 40 KHZ
 * 					so i need decrease 2 step.
 * 					so HSI_TRIM = 01110 = 14.
 * 		Ex2
 * 			RC = 16 MHz - 40KHz
 * 				HSI_TRIM = increase the step by 1
 * 				HSI_TRIM = 10001 = 17
 * 		Ex3
 * 			RC = 16 MHz + 70KHz
 * 				HSI_TRIM = decrease the step by 1
 * 				HSI_TRIM = 01111 = 15
 * 				so RC = 16 MHz + 30 KHz
 * 				BUT, I can't deal with the 30 KHz.
 *
 *
 *
 *  */
void RCC_voidInit   (void)
{

	/*  CSS ON
	 * Related to External Clock Failure
	 * to switch to internal alternatively.
	 * */
	SET_BIT(RCC->CR , CSSON);

	/* BYPASS Select    */

	/*Not Bypass*/
	CLR_BIT(RCC->CR , HSEBYP);

	/*  Enable Clock Source */
#if     RCC_HSI_ENABLE  ==  ENABLE
	SET_BIT(RCC->CR , 0);
#elif   RCC_HSI_ENABLE  == DISABLE
	CLR_BIT(RCC->CR , 0 );
#endif
#if     RCC_HSE_ENABLE  ==  ENABLE
	SET_BIT(RCC->CR , HSEON);
#elif   RCC_HSE_ENABLE  == DISABLE
	CLR_BIT(RCC->CR , HSEON);
#endif
#if     RCC_PLL_ENABLE  ==  ENABLE
	SET_BIT(RCC->CR , PLLON);
#elif   RCC_PLL_ENABLE  == DISABLE
	CLR_BIT(RCC->CR , PLLON);
#endif

	/*AHB Prescaler / 2 */
	SET_BIT(RCC->CFGR , 7 );

	/*  Select Clock Source
	 * 	Also we can Read SW0, SW1
	 * 	to check which clock is System clock
	 * 	*/
#if RCC_CLOCK_SOURCE == RCC_HSI_SELECT
	CLR_BIT( RCC->CFGR , SW0 );
	CLR_BIT( RCC->CFGR , SW1 );
#elif RCC_CLOCK_SOURCE == RCC_HSE_SELECT
	SET_BIT( RCC->CFGR , SW0 );
	CLR_BIT( RCC->CFGR , SW1 );
#elif RCC_CLOCK_SOURCE == RCC_PLL_SELECT
	CLR_BIT( RCC->CFGR , SW0 );
	SET_BIT( RCC->CFGR , SW1 );
#endif

}

/* AHB1                 ,    GPIOA  */
u8 RCC_u8EnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	if ( (Copy_u8BusId <= RCC_APB2) && (Copy_u8PerId < 32))
	{

		switch(Copy_u8BusId)
		{
		case RCC_AHB1 :
			SET_BIT(RCC->AHB1ENR , Copy_u8PerId );
			break ;
		case RCC_APB1 :
			SET_BIT(RCC->APB1ENR , Copy_u8PerId);
			break ;
		case RCC_APB2 :
			SET_BIT(RCC->APB2ENR , Copy_u8PerId);
			break ;

		default :
			Local_u8ErrorState = STD_TYPES_NOK ;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 RCC_u8DisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	if ( (Copy_u8BusId <= RCC_APB2) && (Copy_u8PerId < 32))
	{

		switch(Copy_u8BusId)
		{
		case RCC_AHB1 :
			CLR_BIT(RCC->AHB1ENR , Copy_u8PerId );
			break ;
		case RCC_APB1 :
			CLR_BIT(RCC->APB1ENR , Copy_u8PerId);
			break ;
		case RCC_APB2 :
			CLR_BIT(RCC->APB2ENR , Copy_u8PerId);
			break ;

		default :
			Local_u8ErrorState = STD_TYPES_NOK ;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

