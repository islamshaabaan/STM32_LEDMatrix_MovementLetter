/*
 * STK_prv.h
 *
 *  Created on: Sep 1, 2022
 *      Author: mazen
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRV_H_
#define MCAL_SYSTICK_SYSTICK_PRV_H_

#define SYSTICK_AHB				1
#define SYSTICK_AHB_DIV_8		2

#define SYSTICK_ENABLE  0
#define SYSTICK_CLKSOURCE	2
#define SYSTICK_TICKINT		1
#define SYSTICK_COUNTFLAG	16

#define ENABLE		1
#define DISABLE		0


#define SYSTICK_BASE_ADDR			0xE000E010


typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SYSTICK_MemMap_t;

#define SYSTICK			((volatile SYSTICK_MemMap_t*)(SYSTICK_BASE_ADDR))




#endif /* MCAL_SYSTICK_SYSTICK_PRV_H_ */
