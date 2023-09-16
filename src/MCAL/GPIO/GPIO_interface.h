/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   GPIO                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/*								Ports  									  */
#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2

/*  Define Target PIN STATE FOR ACCESS IN ATOMIC MOOD SET OR RESET        */
#define GPIO_PIN_SET_ATOMIC 	 0
#define	GPIO_PIN_RESET_ATOMIC  	 1
#define	WRONG_PIN_STATE			 2

/*                          Define Target PIN                             */
#define GPIO_PIN0		0
#define GPIO_PIN1		1
#define GPIO_PIN2		2
#define GPIO_PIN3		3
#define GPIO_PIN4		4
#define GPIO_PIN5		5
#define GPIO_PIN6		6
#define GPIO_PIN7		7
#define GPIO_PIN8		8
#define GPIO_PIN9		9
#define GPIO_PIN10		10
#define GPIO_PIN11		11
#define GPIO_PIN12		12
#define GPIO_PIN13		13
#define GPIO_PIN14		14
#define GPIO_PIN15		15
#define INVALID_PIN		16

/*                          Define Pin Mode                               */
#define GPIO_MODE_INPUT      0
#define GPIO_MODE_OUTPUT     1
#define GPIO_MODE_ALTF       2
#define GPIO_MODE_ANALOG     3

/*                          Define GPIO OutputCircut                      */
#define GPIO_OUTPUT_PUSHPULL       0
#define GPIO_OUTPUT_OPERDRAIN      1

/*                        Define Pin OutSpeed type                        */
#define GPIO_OUTPUT_LOW_SPEED        0
#define GPIO_OUTPUT_MEDIUM_SPEED     1
#define GPIO_OUTPUT_HIGH_SPEED       2
#define GPIO_OUTPUT_VHIGH_SPEED      3

/*                          Define Pin PULL type                          */
#define GPIO_PULL_OFF       0
#define GPIO_PULL_UP        1
#define GPIO_PULL_DOWN      2

/*                          Define Pin Data type                          */
#define GPIO_LOW		0
#define GPIO_HIGH		1

/*                          Define PIN LOCK                               */
#define GPIO_PIN_UNLOCK            0
#define GPIO_PIN_LOCK              1

/*                          Define PIN Alternative Options                */
/*
 * Do it Later
 * */


typedef struct
{
	u8 Port 		;
	u8 Pin  		;
	u8 Mode			;
	u8 OutputType	;
	u8 OutputSpeed	;
	u8 PullState 	;
}GPIO_PinConfig;
void GPIO_voidSetPinMode    (   u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Mode
                                );

void GPIO_voidSetPinOutputType  (   u8 Copy_u8PortId,
                                    u8 Copy_u8PinId,
                                    u8 Copy_u8OutputType);

void GPIO_voidSetPinOutputSpeed (   u8 Copy_u8PortId,
                                    u8 Copy_u8PinId,
                                    u8 Copy_u8OutputSpeed);

void GPIO_voidSetPinInputPull   (   u8 Copy_u8PortId,
                                    u8 Copy_u8PinId,
                                    u8 Copy_u8Pull);

u8 GPIO_u8GetPinValue       (   u8 Copy_u8PortId,
                                u8 Copy_u8PinId);

void GPIO_voidSetPinValue   (   u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Value);


void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Value);

void GPIO_voidSetPinAlternative(u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_AlternativeId);

void GPIO_voidPinInit			(GPIO_PinConfig	*	PinConfig);
void GPIO_voidSetPortData(u8 Copy_u8PortId ,u32 Copy_u8PortValue);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
