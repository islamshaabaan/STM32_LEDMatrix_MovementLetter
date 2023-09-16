/*
 * DOTMARIX_interface.h
 *
 *  Created on: Sep 14, 2023
 *      Author: one
 */

#ifndef HAL_HLEDMATRIX_HLEDMTARIX_INTERFACE_H_
#define HAL_HLEDMATRIX_HLEDMTARIX_INTERFACE_H_

void HDOTMATRIX_voidInit(GPIO_PinConfig*,GPIO_PinConfig*);

void HDOTMATRIX_voidDisplay(u8 *arr,GPIO_PinConfig*,GPIO_PinConfig*);

void HLEDMATRIX_voidInit();

void HLEDMATRIX_voidDisplay(u8 *arr);

void HLEDMATRIX_voidMovementDisplay(u8 *arr, u8 arr_size);


#endif /* HAL_HLEDMATRIX_HLEDMTARIX_INTERFACE_H_ */
