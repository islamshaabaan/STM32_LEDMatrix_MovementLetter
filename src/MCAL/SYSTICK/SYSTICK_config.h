/*
 * STK_cfg.h
 *
 *  Created on: Sep 1, 2022
 *      Author: mazen
 */

#ifndef MCAL_SYSTICK_SYSTICK_CFG_H_
#define MCAL_SYSTICK_SYSTICK_CFG_H_


/*Options
 * 1-SYSTICK_AHB			=== AHB Full Clock
 * 2-SYSTICK_AHB_DIV_8		=== AHB Divided on 8 (Prescaler)
 */
#define SYSTICK_CLK_SOURCE     SYSTICK_AHB_DIV_8

/* Options :
    Enable
    Disable
*/
#define SYSTICK_INTERRPUT_EN   ENABLE

#endif /* MCAL_SYSTICK_SYSTICK_CFG_H_ */
