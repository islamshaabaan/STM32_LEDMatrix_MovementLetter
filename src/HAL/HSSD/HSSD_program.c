/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   HSSD                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "HSSD_private.h"
#include "HSSD_config.h"
#include "HSSD_interface.h"

GPIO_PinConfig SSD_LEDS[7]={
		{
				.Port = HSSD_PORT,
				.Pin = HSSD_PIN_A,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		},
		{.Port = HSSD_PORT,
				.Pin = HSSD_PIN_B,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		},
		{
				.Port = HSSD_PORT,
				.Pin = HSSD_PIN_C,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		},
		{
				.Port = HSSD_PORT,
				.Pin = HSSD_PIN_D,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		},
		{
				.Port = HSSD_PORT,
				.Pin = HSSD_PIN_E,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		},
		{
				.Port = HSSD_PORT,
				.Pin = HSSD_PIN_F,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		},
		{
				.Port = HSSD_PORT,
				.Pin = HSSD_PIN_G,
				.Mode = GPIO_MODE_OUTPUT,
				.OutputType = GPIO_OUTPUT_PUSHPULL ,
				.OutputSpeed =GPIO_OUTPUT_LOW_SPEED
		}
};

/****************************************************************************************/
/* @brief : This Function Used To Initialize Seven Segment                              */
/* @param : this function takes void                                                    */
/* @return: This Function Return Error State                                            */
/****************************************************************************************/

void HSSD_voidInit (void)
{
	RCC_voidInit();
	RCC_u8EnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOA);
	for (u8 i= 0; i<7; i++){
		GPIO_voidPinInit(&SSD_LEDS[i]);
	}
}

/****************************************************************************************/
/* @brief : This Function Used To Display number on the seven segment                   */
/* @param : Copy_u8Number -> This Parameter Make the user enter a number to display     */
/* @return: This Function Return Error State                                            */
/****************************************************************************************/

void HSSD_voidDisplay_Number(u8 Copy_u8Number)
{
	switch (Copy_u8Number)
	{
	case ZERO:  	GPIO_voidSetPortData(HSSD_PORT, NUMBER_ZERO);  	break;
	case ONE:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_ONE);  	break;
	case TWO:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_TWO);  	break;
	case THREE:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_THREE);  break;
	case FOUR:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_FOUR);  	break;
	case FIVE:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_FIVE);  	break;
	case SIX:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_SIX);  	break;
	case SEVEN:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_SEVEN);  break;
	case EIGHT:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_EIGHT);  break;
	case NINE:   	GPIO_voidSetPortData(HSSD_PORT, NUMBER_NINE);  	break;
	}

}

