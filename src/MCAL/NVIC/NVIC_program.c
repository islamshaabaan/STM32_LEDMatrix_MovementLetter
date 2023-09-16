/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   NVIC                               */
/*      Date    :   5/9/2023                          */
/*      version :       1.00                          */
/******************************************************/



#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "NVIC_interface.h"
#include  "NVIC_config.h"
#include  "NVIC_private.h"

static u32 NVIC_Glosu32GroupConf = 0 ;

/* Interrupt Set Enable === NVICx_Enable
 * NVIC_ISERx (x = 0 to 7)
 * Req = Privileged.
 * NVIC_ISER0 bits 0 to 31 are for interrupt 0 to 31, respectively
 * NVIC_ISER1 bits 0 to 31 are for interrupt 32 to 63, respectively
 *   ....
 * NVIC_ISER6 bits 0 to 31 are for interrupt 192 to 223, respectively
 * NVIC_ISER7 bits 0 to 15 are for interrupt 224 to 239, respectively
 * Write:
 * 	0: No effect
 * 	1: Enable interrupt
 * Read:
 * 	0: Interrupt disabled
 * 	1: Interrupt enabled.
 *
 * 	@Copy_u8IntID : It's the interrupt HW position in the vector table.
 * 					Ex:
 * 						EXTI0 >> it's position is 6
 * 								so Copy_u8IntID = 6.
 * */
void NVIC_voidEnablePeripheral	(u8 Copy_u8IntID)
{
	NVIC ->ISER[Copy_u8IntID / 32] = 1 << (Copy_u8IntID %32);
}

/* Interrupt Clear Enable ==== NVICx_Disable */
void NVIC_voidDisablePeripheral	(u8 Copy_u8IntID)
{
	NVIC ->ICER[Copy_u8IntID / 32] = 1 << (Copy_u8IntID %32);

}

/* Interrupt Set Pending === Pending_flag
 * Write:
 * 	0: No effect
 * 	1: Changes interrupt state to pending
 * Read:
 * 	0: Interrupt is not pending
 * 	1: Interrupt is pending
 *  */
void NVIC_voidSetPendingFlag	(u8 Copy_u8IntID)
{
	NVIC ->ISPR[Copy_u8IntID / 32] = 1 << (Copy_u8IntID %32);
}

/* Interrupt Clear Pending
 * Writing 1 to an ICPR bit does not affect the active state of the corresponding interrupt.
 * */
void NVIC_voidClearPendingFlag	(u8 Copy_u8IntID)
{
	NVIC ->ICPR[Copy_u8IntID / 32] = 1 << (Copy_u8IntID %32);

}

/* Interrupt Active Bit === Active_flag
 * Read only:
 * 	0: Interrupt not active
 * 	1: Interrupt active
 * */
u8 NVIC_u8GetActive	(u8 Copy_u8IntID)
{
	return GET_BIT((NVIC->IAPR[Copy_u8IntID/32]),(Copy_u8IntID % 32));
}

/* Application Interrupt and reset control
 * System Control Block
 * The AIRCR provides priority grouping control for the exception model,
 * To write to this register, you must write 0x05FA to the VECTKEY field,
 * otherwise the processor ignores the write.
 *
 * Bit 2 SYSRESETREQ: System reset request
 * 		This is intended to force a large system reset of all major components except for debug.
 * 		This bit reads as 0.
 * 			0: No system reset request
 * 			1: Asserts a signal to the outer system that requests a reset.
 * Bit 1 VECTCLRACTIVE Reserved for Debug use.
 * 		This bit reads as 0.
 * 		When writing to the register you must write 0 to this bit, otherwise behavior is unpredictable.
 * Bit 0 VECTRESET Reserved for Debug use.
 * 		This bit reads as 0.
 * 		When writing to the register you must write 0 to this bit, otherwise behavior is unpredictable.
 *
 * Bits 10:8 PRIGROUP: Interrupt priority grouping field.
 * 		We have 3 bits to set the environment mapping to the 4 bit in IPR:
 * 			Prigroup	>>	BinaryPoint 	>>	Group_Pr , 	Sub_Pr
 * 			0b0xx 		>> 	0bxxxx, 		>>	16		 ,		0   << Shift = 0
 * 			0b100 		>> 	0bxxx,y 		>>	8	 	 ,		2 	<< Shift = 1
 * 			0b101 		>> 	0bxx,yy 		>>	4	 	 ,		4	<< Shift = 2
 * 			0b110 		>> 	0bx,yyy			>>	2	 	 ,		8 	<< Shift = 3
 * 			0b111 		>> 	0b,yyyy 		>>	0	 	 ,		16	<< Shift = 4

 * */
void NVIC_voidSetPriorityConfig	(u8 Copy_u8PriorityOption)
{
	NVIC_Glosu32GroupConf = VECT_KEY | ( Copy_u8PriorityOption << 8);	// 0x05fA xxxx
	SCB->AIRCR = NVIC_Glosu32GroupConf ;
}


void NVIC_voidSetPriority	(s8 Copy_s8IntId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority)
{

	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((NVIC_Glosu32GroupConf - 0x05FA0300)/256));

	/*	System Handler Priority */
	if(Copy_s8IntId < 0)
	{
		if(Copy_s8IntId == MEMORY_MANAGE || Copy_s8IntId == BUS_FAULT || Copy_s8IntId == USAGE_FAULT)
		{
			Copy_s8IntId += 3 ;
			SCB->SHPR1 = (Local_u8Priority)<< ((8 * Copy_s8IntId) + 4);
		}
		else if(Copy_s8IntId == SV_CALL)
		{
			Copy_s8IntId +=7 ;
			SCB->SHPR2 = (Local_u8Priority) << ((8 * Copy_s8IntId) + 4 );
		}
		else if ( Copy_s8IntId == PEND_SV)
		{
			Copy_s8IntId += 8 ;
			SCB->SHPR3 = (Local_u8Priority) << ((8 * Copy_s8IntId) + 4 );
		}
	}

	/* Interrupt Priority Register
	 * For Grouping Priority
	 * Just IPR[7:4] only to use, the others is RESERVED.
	 *
	 * The NVIC_IPRx (x = 0 to 59) byte-accessible registers provide 8-bit priority fields
	 * IP[N] (N = 0 to 239) for each of the 240 interrupts.
	 * Every register holds four IP[N] fields of the CMSIS interrupt priority array,
	 *		We have 4 bits to set the environment priority level:
	 * 			4Bits for Group_Pr & 0Bit  for Sub_Pr : 16 Group		& 		0 Sub << Shift = 0
	 * 			3Bits for Group_Pr & 1Bit  for Sub_Pr : 8  Group		& 		2 Sub << Shift = 1
	 * 			2Bits for Group_Pr & 2Bits for Sub_Pr : 4  Group		&		4 Sub << Shift = 2
	 * 			1Bit  for Group_Pr & 3Bit  for Sub_Pr : 2  Group		& 		8 Sub << Shift = 3
	 * 			0Bit  for Group_Pr & 4Bits for Sub_Pr : 0  Group		&		16 Sub<< Shift = 4
	 * */
	else if ( Copy_s8IntId >= 0)
	{
		NVIC->IPR[Copy_s8IntId] = Local_u8Priority << 4 ;
	}
}
