/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   EXTI                               */
/*      Date    :   5/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define ENABLE		1
#define DISABLE		0

#define EXTI_RISING		1
#define EXTI_FALLING	2
#define EXTI_ON_CHANGE	3

#define EXTI_LINE_0			0
#define EXTI_LINE_1			1
#define EXTI_LINE_2			2
#define EXTI_LINE_3			3
#define EXTI_LINE_4			4
#define EXTI_LINE_5			5
#define EXTI_LINE_6			6
#define EXTI_LINE_7			7
#define EXTI_LINE_8			8
#define EXTI_LINE_9			9
#define EXTI_LINE_10		10
#define EXTI_LINE_11		11
#define EXTI_LINE_12		12
#define EXTI_LINE_13		13
#define EXTI_LINE_14		14
#define EXTI_LINE_15		15

#define	EXTI_PORTA			0000
#define	EXTI_PORTB			0001
#define	EXTI_PORTC			0010

typedef struct
{
	u8 LineNo	;
	u8 Trigger	;

}EXTI_Config_t;

void EXTI_voidInit		(void);

void EXTI_voidInit2		(EXTI_Config_t * Copy_pstrConfig);
/*******************************/
/*	Function Name : EXTI_voidEnableLine*/
/*	I/p Argument : Copy_u8Line --> EXTI_LINE_0 , , */
/*	return type : void 					*/
/* Description : */
/*******************************/
void EXTI_voidEnableLine	(u8 Copy_u8Line , u8 Copy_u8TriggerEdge	);

void EXTI_voidEnableEventLine(u8 Copy_u8Line , u8 Copy_u8TriggerEdge	);

void EXTI_voidDisableLine	(u8 Copy_u8Line );

void EXTI_voidDisableEventLine	(u8 Copy_u8Line );

void EXTI_voidSoftwareTrigger	(u8 Copy_u8Line );

void EXTI_voidSetTrigger	(u8 Copy_u8Line , u8 Copy_u8TriggerEdge	) ;

void SYSCFG_voidEXTIPort	(	u8 Copy_u8Line	, u8 Copy_u8PortNo	);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
