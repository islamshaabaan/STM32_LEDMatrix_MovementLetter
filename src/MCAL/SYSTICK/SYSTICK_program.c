/*
 * STK_prg.c
 *
 *  Created on: Sep 1, 2022
 *      Author: mazen
 */




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


static void (*GS_STK_Callback)(void) ;
static u8   G_u8SingleFlag ;



void SYSTICK_voidInit(void)
{
	/* 2- Interrupt enable or disable*/
#if SYSTICK_INTERRPUT_EN==ENABLE
	SET_BIT(SYSTICK->CTRL, SYSTICK_TICKINT) ;
#endif
	/* 1- clock source */
#if SYSTICK_CLK_SOURCE == SYSTICK_AHB
	SET_BIT(STK->CTRL, SYSTICK_CLKSOURCE) ;
#elif SYSTICK_CLK_SOURCE == SYSTICK_AHB_DIV_8
	CLR_BIT(SYSTICK->CTRL , SYSTICK_CLKSOURCE);
#endif
}

void SYSTICK_voidStartTimer(u32 A_u32LoadValue){
	/* 2- Load timer with Value */
	SYSTICK->LOAD = A_u32LoadValue ;
	/* 1- reset timer value */
	SYSTICK->VAL = 0 ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, SYSTICK_ENABLE);
}

void SYSTICK_voidStopTimer(void)
{
	CLR_BIT(SYSTICK->CTRL , SYSTICK_ENABLE );
}


void SYSTICK_voidSetBusyWait(u32 A_u32Ticks)
{
	/* 2- Load timer with Value */
	SYSTICK->LOAD = A_u32Ticks ;
	/* 1- reset timer value */
	SYSTICK->VAL = 0 ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, SYSTICK_ENABLE);
	/* 4-  wait for timer flag to be raised  */
	while(GET_BIT(SYSTICK->CTRL, SYSTICK_COUNTFLAG) != 1  ){}
	/* 5-  Stop the timer   */
	CLR_BIT(SYSTICK->CTRL, SYSTICK_ENABLE);
}

void SYSTICK_voidSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	/* 0- set Callback function */
	GS_STK_Callback = CallbackFunction ;
	G_u8SingleFlag = 1 ;
	/*	0-	Enable interrupt	*/
	SET_BIT(SYSTICK->CTRL , SYSTICK_TICKINT );
	/* 1- reset timer value */
	SYSTICK->VAL = 0 ;
	/* 2- Load timer with Value */
	SYSTICK->LOAD = A_u32Ticks ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, SYSTICK_ENABLE);
}

void SYSTICK_voidSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	/* 0- set Callback function */
	GS_STK_Callback = CallbackFunction ;
	G_u8SingleFlag = 0 ;
	SET_BIT(SYSTICK->CTRL , SYSTICK_TICKINT );
	/* 1- reset timer value */
	SYSTICK->VAL = 0 ;
	/* 2- Load timer with Value */
	SYSTICK->LOAD = A_u32Ticks ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, SYSTICK_ENABLE);
}


u32  SYSTICK_u32GetElapsedTime(void)
{
	return (SYSTICK->LOAD - SYSTICK->VAL) ;
}

u32  SYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL ;
}


void SysTick_Handler(void)
{
	if(GS_STK_Callback != NULL_PTR)
	{
		GS_STK_Callback();
	}
	if(G_u8SingleFlag)
	{
		G_u8SingleFlag = 0 ;
		/* 5-  Stop the timer   */
		CLR_BIT(SYSTICK->CTRL, SYSTICK_ENABLE);
	}
}
















