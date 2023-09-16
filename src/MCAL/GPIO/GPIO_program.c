/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   GPIO                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

/*                          Define Pin Mode
GPIO_MODE_INPUT      0
GPIO_MODE_OUTPUT     1
GPIO_MODE_ALTF       2
GPIO_MODE_ANALOG     3
 */

void GPIO_voidSetPinMode    ( u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Mode ){
	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
		{
	switch(Copy_u8PortId){
	case GPIO_PORTA:
		GPIOA->MODER  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_u8PinId )) ; // Clear the specific 2 bits to set mode
		GPIOA->MODER  |= (u32) ( Copy_u8Mode << ( 2* Copy_u8PinId )) ;
		break;
	case GPIO_PORTB:
		GPIOB->MODER  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_u8PinId )) ;
		GPIOB->MODER  |= (u32) ( Copy_u8Mode << ( 2* Copy_u8PinId )) ;
		break;
	case GPIO_PORTC:
		GPIOC->MODER  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_u8PinId )) ;
		GPIOC->MODER  |= (u32) ( Copy_u8Mode << ( 2* Copy_u8PinId )) ;
		break;
	}
		}
	else{
		//Do nothing
	}
}

/*                          Define GPIO OutputCircut
GPIO_OUTPUT_PUSHPULL       0
GPIO_OUTPUT_OPERDRAIN      1
 */

void GPIO_voidSetPinOutputType  ( u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputType){
	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		/* First Mode = PUSHPULL (Reset State) */
		if  ( Copy_u8OutputType  == GPIO_OUTPUT_PUSHPULL  ){
			GPIOx_REG( Copy_u8PortId )->OTYPER &= ~( 1U << Copy_u8PinId);
		}
		/* First Mode */
		else	if  ( Copy_u8OutputType  == GPIO_OUTPUT_OPERDRAIN   ){
			GPIOx_REG( Copy_u8PortId )->OTYPER |= ( 1U << Copy_u8PinId);
		}
	}
	else{
		// Do Nothing
	}
}
/*                        Define Pin OutSpeed type
GPIO_OUTPUT_LOW_SPEED        0
GPIO_OUTPUT_MEDIUM_SPEED     1
GPIO_OUTPUT_HIGH_SPEED       2
GPIO_OUTPUT_VHIGH_SPEED      3
 */
void GPIO_voidSetPinOutputSpeed ( u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputSpeed){

	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		switch(Copy_u8PortId){
		case GPIO_PORTA:
			GPIOA->OSPEEDR  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_u8PinId )) ; // Clear the specific 2 bits to set mode
			GPIOA->OSPEEDR  |= (u32) ( Copy_u8OutputSpeed << ( 2* Copy_u8PinId )) ;
			break;
		case GPIO_PORTB:
			GPIOB->OSPEEDR  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_u8PinId )) ;
			GPIOB->OSPEEDR  |= (u32) ( Copy_u8OutputSpeed << ( 2* Copy_u8PinId )) ;
			break;
		case GPIO_PORTC:
			GPIOC->OSPEEDR  &=  ~ (u32) ( BITS_MODE_MASK << ( 2* Copy_u8PinId )) ;
			GPIOC->OSPEEDR  |= (u32) ( Copy_u8OutputSpeed << ( 2* Copy_u8PinId )) ;
			break;
		}
	}
	else{
		//Do nothing
	}

	/*
	 // BITS_SPEED_MASK = 3U >>>> a clearing mask for 2 bits at OSPEEDR REG
		GPIOx_REG(Copy_u8PortId)->OSPEEDR &=  ~ (u32) ( BITS_SPEED_MASK << ( 2* Copy_uddtPinNum )) ;
		GPIOx_REG(Copy_u8PortId)->OSPEEDR |=    (u32) ( Copy_u8PinOutSpeed << ( 2* Copy_uddtPinNum )) ;
	 */
}

/*                          Define Pin PULL type
GPIO_PULL_OFF       0
GPIO_PULL_UP        1
GPIO_PULL_DOWN      2
 */
void GPIO_voidSetPinInputPull   ( u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Pull){

	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		GPIOx_REG(Copy_u8PortId)->PUPDR &=  ~ (u32) ( BITS_SPEED_MASK << ( 2* Copy_u8PinId )) ;
		GPIOx_REG(Copy_u8PortId)->PUPDR |=    (u32) ( Copy_u8Pull << ( 2* Copy_u8PinId )) ;
	}
	else{
		//Do nothing
	}
}

u8 GPIO_u8GetPinValue  ( u8 Copy_u8PortId, u8 Copy_u8PinId){
	u8 Local_RetValue = 255; // Indication for error
	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			Local_RetValue = GET_BIT(GPIOA->IDR , Copy_u8PinId);
			break;
		case GPIO_PORTB:
			Local_RetValue = GET_BIT(GPIOB->IDR , Copy_u8PinId);
			break;
		case GPIO_PORTC:
			Local_RetValue = GET_BIT(GPIOC->IDR , Copy_u8PinId);
			break;
		default:
			break;
		}
	}
	else{
		// Do nothing
	}
	return Local_RetValue;
}


void GPIO_voidSetPinValue   (  u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value){
	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA :
			switch (Copy_u8Value)
			{
			case GPIO_HIGH:
				SET_BIT(GPIOA->ODR , Copy_u8PinId);
				break;
			case GPIO_LOW:
				CLR_BIT(GPIOA->ODR , Copy_u8PinId);
				break;
			default:
				break;
			}
			break;

			case GPIO_PORTB :
				switch (Copy_u8Value)
				{
				case GPIO_HIGH:
					SET_BIT(GPIOB->ODR , Copy_u8PinId);
					break;
				case GPIO_LOW:
					CLR_BIT(GPIOB->ODR , Copy_u8PinId);
					break;
				default:
					break;
				}
				break;

				case GPIO_PORTC :
					switch (Copy_u8Value)
					{
					case GPIO_HIGH:
						SET_BIT(GPIOC->ODR , Copy_u8PinId);
						break;
					case GPIO_LOW:
						CLR_BIT(GPIOC->ODR , Copy_u8PinId);
						break;
					default:
						break;
					}
					break;

					default:
						break;
		}
	}
	else{
		// Do nothing
	}
}


void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value){
	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		switch(Copy_u8Value)
		{
		case  GPIO_HIGH :
			GPIOx_REG(Copy_u8PortId)->BSRR = (1<<Copy_u8PinId     )   ;
			break;
		case  GPIO_LOW :
			GPIOx_REG(Copy_u8PortId)->BSRR = (1<<(Copy_u8PinId+16))   ;
			break;
		default :
			break;
		}
	}
	else{
		//Do Nothing
	}
}
/*
 void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Value)
{
	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA :
			switch (Copy_u8Value)
			{
			case GPIO_HIGH:
				GPIOA->BSRR = (1 << (Copy_u8PinId));
				break;
			case GPIO_LOW:
				GPIOA->BSRR = (1 << (Copy_u8PinId + 16 ));
				break;
			default:
				break;
			}
			break;

			case GPIO_PORTB :
				switch (Copy_u8Value)
				{
				case GPIO_HIGH:
					GPIOB->BSRR = (1 << (Copy_u8PinId));
					break;
				case GPIO_LOW:
					GPIOB->BSRR = (1 << (Copy_u8PinId + 16 ));
					break;
				default:
					break;
				}
				break;

				case GPIO_PORTC :
					switch (Copy_u8Value)
					{
					case GPIO_HIGH:
						GPIOC->BSRR = (1 << (Copy_u8PinId));
						break;
					case GPIO_LOW:
						GPIOC->BSRR = (1 << (Copy_u8PinId + 16 ));
						break;
					default:
						break;
					}
					break;

					default:
						break;
		}
	}
	else
	{
		// Do nothing
	}
}
 */
void GPIO_voidSetPinAlternative(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_AlternativeId){

	if( (Copy_u8PortId <= GPIO_PORTC)   &&  (Copy_u8PinId <= GPIO_PIN15)  )
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			/*AFRL controls form pin0 to pin7 (each pin has 4 bits)*/
			if(Copy_u8PinId <= 7 )
			{
				GPIOA->AFRL &= ~ ( ( 0b1111 )  << ( Copy_u8PinId * 4 ));  /*Reset or clear pin (4bits)*/
				GPIOA->AFRL |= ( Copy_AlternativeId ) << ( Copy_u8PinId * 4 );   /*apply mode on pin (interface file)*/
			}

			/*AFRH controls form pin8 to pin15 (each pin has 4 bits)*/
			else if(Copy_u8PinId <= 15 )
			{
				Copy_u8PinId = Copy_u8PinId - 8;
				GPIOA->AFRH &= ~ ( ( 0b1111 )  << ( Copy_u8PinId * 4 ) );
				GPIOA->AFRH |= ( Copy_AlternativeId ) << ( Copy_u8PinId * 4 );
			}

			break;

		case GPIO_PORTB:
			if(Copy_u8PinId <= 7 )
			{
				/*Reset pin then overwrite*/
				GPIOB->AFRL &= ~ ( ( 0b1111 )  << ( Copy_u8PinId * 4 ) );    /*Reset or clear pin*/
				GPIOB->AFRL |= ( Copy_AlternativeId ) << ( Copy_u8PinId * 4 )  ;    /*apply mode on pin*/
			}

			else if(Copy_u8PinId <= 15 )
			{
				Copy_u8PinId = Copy_u8PinId - 8;
				GPIOB->AFRH &= ~ ( ( 0b1111 )  << ( Copy_u8PinId * 4 ) );
				GPIOB->AFRH |= ( Copy_AlternativeId ) << ( Copy_u8PinId * 4 )  ;
			}

			break;

		case GPIO_PORTC:
			if(Copy_u8PinId <= 7 )
			{
				GPIOC->AFRL &= ~ ( ( 0b1111 )  << ( Copy_u8PinId * 4 ) );
				GPIOC->AFRL |= ( Copy_AlternativeId ) << ( Copy_u8PinId * 4 )  ;
			}

			else if(Copy_u8PinId <= 15 )
			{
				Copy_u8PinId = Copy_u8PinId - 8;
				GPIOC->AFRH &= ~ ( ( 0b1111 )  << ( Copy_u8PinId * 4 ) );
				GPIOC->AFRH |= ( Copy_AlternativeId ) << ( Copy_u8PinId * 4 )  ;
			}

			break;
		}
	}
	else{
		// Do nothing
	}
}

void GPIO_voidPinInit			(GPIO_PinConfig	*	PinConfig)
{
	GPIO_voidSetPinMode(PinConfig->Port , PinConfig->Pin , PinConfig->Mode);
	GPIO_voidSetPinOutputType(PinConfig->Port , PinConfig->Pin , PinConfig->OutputType);
	GPIO_voidSetPinOutputSpeed(PinConfig->Port , PinConfig->Pin , PinConfig->OutputSpeed);
	GPIO_voidSetPinInputPull(PinConfig->Port , PinConfig->Pin , PinConfig->PullState);
}
void GPIO_voidSetPortData(u8 Copy_u8PortId ,u32 Copy_u8PortValue)
{
	switch (Copy_u8PortId)
	{
	case GPIO_PORTA : GPIOA->ODR = Copy_u8PortValue ;    break;
	case GPIO_PORTB : GPIOB->ODR = Copy_u8PortValue ;    break;
	case GPIO_PORTC : GPIOC->ODR = Copy_u8PortValue ;    break;
	default : 											 break;
	}
}

