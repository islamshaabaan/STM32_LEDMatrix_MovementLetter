/*
 * STK_int.h
 *
 *  Created on: Sep 1, 2022
 *      Author: mazen
 */

#ifndef MCAL_SYSTICK_SYSTICK_INT_H_
#define MCAL_SYSTICK_SYSTICK_INT_H_


void SYSTICK_voidInit(void);

void SYSTICK_voidStartTimer(u32 A_u32LoadValue);
void SYSTICK_voidStopTimer(void);

void SYSTICK_voidSetBusyWait(u32 A_u32Ticks);

void SYSTICK_voidSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void));
void SYSTICK_voidSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void));


u32 SYSTICK_u32GetElapsedTime(void);
u32 SYSTICK_u32GetRemainingTime(void);




#endif /* MCAL_SYSTICK_SYSTICK_INT_H_ */
