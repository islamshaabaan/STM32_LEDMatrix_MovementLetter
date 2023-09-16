/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   EXTI                               */
/*      Date    :   5/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*PF_Notification[16]) (void) ={NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR,NULL_PTR};


/*	Interrupt Mask === Enable/Disable
 * Bits 31:23 Reserved, must be kept at reset value.
 * Bits 22:0 	MRx: Interrupt mask on line x
 * 				0: Interrupt request from line x is masked 		=== EXTIx is disabled
 * 				1: Interrupt request from line x is not masked 	=== EXTIx is enabled
 * */
void EXTI_voidInit		(void)
{
	EXTI->IMR = 0 ;
	EXTI->IMR |= (EXTI_LINE_0_EN 	<<0)	|
			(EXTI_LINE_1_EN		<< 1)	|
			(EXTI_LINE_2_EN 	<< 2) 	|
			(EXTI_LINE_3_EN 	<< 3)	|
			(EXTI_LINE_4_EN		<< 4)	|
			(EXTI_LINE_5_EN 	<< 5) 	|
			(EXTI_LINE_6_EN 	<< 6)	|
			(EXTI_LINE_7_EN		<< 7)	|
			(EXTI_LINE_8_EN 	<< 8) 	|
			(EXTI_LINE_9_EN 	<< 9)	|
			(EXTI_LINE_10_EN	<< 10)	|
			(EXTI_LINE_11_EN 	<< 11) 	|
			(EXTI_LINE_12_EN 	<< 12)	|
			(EXTI_LINE_13_EN	<< 13)	|
			(EXTI_LINE_14_EN 	<< 14) 	|
			(EXTI_LINE_15_EN 	<< 15)	|
			(EXTI_LINE_16_EN	<< 16)	;

	/*Clear All	Pending Flags*/
	EXTI->PR = 0xffffffff ;

}
/*
void EXTI_voidInit2		(EXTI_Config_t * Copy_pstrConfig)
{
	asm("NOP");
}*/

/*
 * @Copy_u8Line : it's the bit which refer the EXTIx
 * 				 EXTI_LINE_0			0
 * 				 EXTI_LINE_1			1
 * 				 EXTI_LINE_2			2
 * 				 ....
 * 				 ....
 * 				 ...
 *
 * Bits 31:23 Reserved,
 * must be kept at reset value.
 * Bits 22:0 TRx: Rising trigger event configuration bit of line x
 * 				0: Rising trigger disabled (for Event and Interrupt) for input line
 * 				1: Rising trigger enabled (for Event and Interrupt) for input line
 *
 * */
void EXTI_voidEnableLine	(u8 Copy_u8Line , u8 Copy_u8TriggerEdge	)
{
	if(Copy_u8Line < 16 )
	{
		SET_BIT(EXTI->IMR , Copy_u8Line);
		switch(Copy_u8TriggerEdge)
		{
		case EXTI_RISING: 		/*	Rising trigger selection*/

			SET_BIT(EXTI->RTSR , Copy_u8Line);
			CLR_BIT(EXTI->FTSR , Copy_u8Line);
			break;
		case EXTI_FALLING:		/*	Falling trigger selection*/
			CLR_BIT(EXTI->RTSR , Copy_u8Line);
			SET_BIT(EXTI->FTSR , Copy_u8Line);
			break ;
		case EXTI_ON_CHANGE:	/*	OnChange trigger selection*/
			SET_BIT(EXTI->RTSR , Copy_u8Line);
			SET_BIT(EXTI->FTSR , Copy_u8Line);
			break;
		default :
			break;
		}
	}
}

void EXTI_voidEnableEventLine(u8 Copy_u8Line , u8 Copy_u8TriggerEdge	){
	if(Copy_u8Line < 16 )
	{
		SET_BIT(EXTI->EMR , Copy_u8Line);
		switch(Copy_u8TriggerEdge)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR , Copy_u8Line);
			CLR_BIT(EXTI->FTSR , Copy_u8Line);
			break;
		case EXTI_FALLING:
			CLR_BIT(EXTI->RTSR , Copy_u8Line);
			SET_BIT(EXTI->FTSR , Copy_u8Line);
			break ;
		case EXTI_ON_CHANGE:
			SET_BIT(EXTI->RTSR , Copy_u8Line);
			SET_BIT(EXTI->FTSR , Copy_u8Line);
			break;
		default :
			break;
		}
	}
}

void EXTI_voidDisableLine	(u8 Copy_u8Line )
{
	if(Copy_u8Line <16)
	{
		CLR_BIT(EXTI->IMR , Copy_u8Line);
	}
}

void EXTI_voidDisableEventLine	(u8 Copy_u8Line )
{
	if(Copy_u8Line <16)
	{
		CLR_BIT(EXTI->EMR , Copy_u8Line);
	}
}

/*
 *	Software interrupt event
 * 	If you working with EXTIx and enabled it from IMR, but
 * 	you want to fire the interrupt from the SW interrupts instead of HW.
 * 	Write '1' to SWIERx == EXTIx,
 * 	Once writing '1' in SWIERx, EXTI_PRx pending flag will set as '1'.
 * 	it's equavilent to HW action occured.
 * 	it's an interrupt request generation.
 * 	if you want to clear it, clear the corresponding bit in EXTI_PRx by Writing '1'.
 * 	PRx: Pending bit
 * 		0: No trigger request occurred
 * 		1: selected trigger request occurred
 * 		This bit is set when the selected edge event arrives on the external interrupt line.
 * 		This bit is cleared by programming it to ‘1’.
 *	""" MALHASH LAZMA === Zya Zy ==== SET Pending flag === ONLY for TEST.
 *	it's like a call function, but with priority to uninterrupted, and include PSW flags register included while context switching.
 * */
void EXTI_voidSoftwareTrigger	(u8 Copy_u8Line )
{
	if(Copy_u8Line <16)
	{
		SET_BIT(EXTI->SWIER , Copy_u8Line);
	}
}
void EXTI_voidSetTrigger	(u8 Copy_u8Line , u8 Copy_u8TriggerEdge	)
{
	if(Copy_u8Line < 16)
	{

		switch(Copy_u8TriggerEdge)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR , Copy_u8Line);
			CLR_BIT(EXTI->FTSR , Copy_u8Line);
			break;
		case EXTI_FALLING:
			CLR_BIT(EXTI->RTSR , Copy_u8Line);
			SET_BIT(EXTI->FTSR , Copy_u8Line);
			break ;
		case EXTI_ON_CHANGE:
			SET_BIT(EXTI->RTSR , Copy_u8Line);
			SET_BIT(EXTI->FTSR , Copy_u8Line);
			break;
		default :
			break;
		}
	}
}

/*
 * External Interrupt configuration
 * we have 16 EXTIx , repersented in 4 Registers
 * SYSCFG_EXTICR1 - SYSCFG_EXTICR2 - SYSCFG_EXTICR3 - SYSCFG_EXTICR4
 * each one got 4 EXTIx [EXTI0, EXTI1, EXTI2, EXTI3]
 * each EXTIx got 4 bit to select the pin source.
 * Options: @Copy_u8PortNo
 * 			0000: PA[x] pin
 * 			0001: PB[x] pin
 * 			0010: PC[x] pin
 * 			0011: PD[x] pin
 * 			0100: PE[x] pin
 * 			0101: Reserved
 * 			0110: Reserved
 * 			0111: PH[x] pin
 * */
void SYSCFG_voidEXTIPort	(	u8 Copy_u8Line	, u8 Copy_u8PortNo	)
{
	if ( Copy_u8Line < 16)
	{
		SYSCFG->EXTICR[Copy_u8Line/4] &= ~((0b1111) << (4 * (Copy_u8Line % 4 )));
		SYSCFG->EXTICR[Copy_u8Line/4] |= (Copy_u8PortNo << (4 * (Copy_u8Line % 4 )));
	}
}

void  EXTI_voidSetCallBack(u8 Copy_InterruptId,void (*PF)(void))
{

	switch(Copy_InterruptId)
	{

	case EXTI_LINE_0:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_0]=PF;
		}
		break;
	case EXTI_LINE_1:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_1]=PF;
		}
		break;
	case EXTI_LINE_2:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_2]=PF;
		}
		break;
	case EXTI_LINE_3:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_3]=PF;
		}
		break;
	case EXTI_LINE_4:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_4]=PF;
		}
		break;
	case EXTI_LINE_5:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_5]=PF;
		}
		break;
	case EXTI_LINE_6:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_6]=PF;
		}
		break;
	case EXTI_LINE_7:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_7]=PF;
		}
		break;
	case EXTI_LINE_8:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_8]=PF;
		}
		break;
	case EXTI_LINE_9:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_9]=PF;
		}
		break;
	case EXTI_LINE_10:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_10]=PF;
		}
		break;
	case EXTI_LINE_11:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_11]=PF;
		}
		break;
	case EXTI_LINE_12:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_12]=PF;
		}
		break;
	case EXTI_LINE_13:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_13]=PF;
		}
		break;
	case EXTI_LINE_14:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_14]=PF;
		}
		break;
	case EXTI_LINE_15:
		if(PF!=NULL_PTR)
		{
			PF_Notification[EXTI_LINE_15]=PF;
		}
		break;
	}
}

/*
void EXTI0_IRQHandler(void)
{
	if(PF_Notification[0]!=NULL)
	{
		PF_Notification[0]();
		SET_BIT(EXTI->PR,0);
	}
}*/

void EXTI1_IRQHandler(void)
{
	if(PF_Notification[1]!=NULL_PTR)
	{
		PF_Notification[1]();
		SET_BIT(EXTI->PR,1);
	}
}


void EXTI2_IRQHandler(void)
{
	if(PF_Notification[2]!=NULL_PTR)
	{

		PF_Notification[2]();
		SET_BIT(EXTI->PR,2);
	}
}


void EXTI3_IRQHandler(void)
{
	if(PF_Notification[3]!=NULL_PTR)
	{
		PF_Notification[3]();
		SET_BIT(EXTI->PR,3);
	}
}


void EXTI4_IRQHandler(void)
{

	if(PF_Notification[4]!=NULL_PTR)
	{
		PF_Notification[4]();
		SET_BIT(EXTI->PR,4);
	}
}


void EXTI9_5_IRQHandler(void)
{

	for(u8 i=5 ;i<=9 ;i++)
	{
		if(PF_Notification[i]!=NULL_PTR && GET_BIT(EXTI->PR,i))
		{
			PF_Notification[i]();
			SET_BIT(EXTI->PR,i);
		}
	}

}


void EXTI15_10_IRQHandler(void)
{

	for(u8 i=10 ;i<=15 ;i++)
	{
		if(PF_Notification[i]!=NULL_PTR && GET_BIT(EXTI->PR,i))
		{
			PF_Notification[i]();
			SET_BIT(EXTI->PR,i);
		}
	}
}
