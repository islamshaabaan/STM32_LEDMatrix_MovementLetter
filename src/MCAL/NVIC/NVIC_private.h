/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   NVIC                               */
/*      Date    :   5/9/2023                          */
/*      version :       1.00                          */
/******************************************************/







#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_



/*	Make the Register by Base and Offset Addresses
//ISER(Interrupt set-enable register) registers
#define NVIC_ISER0                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x00 ))
#define NVIC_ISER1                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x04 ))

//ICER(Interrupt clear-enable register) registers
#define NVIC_ICER0                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x80 ))
#define NVIC_ICER1                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x84 ))

//ISPR(Interrupt set-pending register) registers
#define NVIC_ISPR0                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x100 ))
#define NVIC_ISPR1                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x104 ))

//ICPR(Interrupt clear-pending register) registers
#define NVIC_ICPR0                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x180 ))
#define NVIC_ICPR1                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x184 ))

//IABR(Interrupt active bit register) registers
#define NVIC_IABR0                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x200 ))
#define NVIC_IABR1                 *((volatile u32*)(NVIC_ISER_BASE_ADDRESS + 0x204 ))

#define SCB_AIRCR                  *((volatile u32*)(0xE000ED0C ))

//SCB-> AIRC  Group Options
#define GROUP16_SUB0      0x05FA0000
#define GROUP8_SUB2		  0x05FA0400
#define GROUP4_SUB4       0x05FA0500
#define GROUP2_SUB8       0x05FA0600
#define GROUP0_SUB16	  0x05FA0700


u8 IPR[60];
*/


#define NVIC_BASE_ADDRESS	0xE000E100

#define VECT_KEY	0x05FA0000

typedef struct
{

	volatile u32 ISER[32] 	;
	volatile u32 ICER[32]	;
	volatile u32 ISPR[32]	;
	volatile u32 ICPR[32]	;
	volatile u32 IAPR[32]	;
	volatile u32 RESERVED[32];
	volatile u8 IPR[240]		;

}NVIC_MemMap_t;

#define NVIC	((volatile NVIC_MemMap_t *)NVIC_BASE_ADDRESS)


/*========================================================*/

#define SCB_BASE_ADDRESS	0xE000ED00

typedef struct
{
	volatile u32 CPUID	;
	volatile u32 ICSR	;
	volatile u32 VTOR	;
	volatile u32 AIRCR  ;
	volatile u32 SCR	;
	volatile u32 CCR	;
	volatile u32 SHPR1	;
	volatile u32 SHPR2	;
	volatile u32 SHPR3	;
	volatile u32 SHCSR	;
	volatile u32 CFSR	;
	volatile u32 HFSR	;
	volatile u32 MMAR	;
	volatile u32 BFAR	;
	volatile u32 AFSR	;
}SCB_MemMap_t;

#define SCB		((volatile SCB_MemMap_t *)SCB_BASE_ADDRESS)





#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
