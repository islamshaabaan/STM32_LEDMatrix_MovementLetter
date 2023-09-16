/*
 * DOTMATRIX_program.c
 *
 *  Created on: Sep 14, 2023
 *      Author: one
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_interface.h"

#include "HLEDMTARIX_interface.h"
#include "HLEDMATRIX_private.h"
#include "HLEDMATRIX_config.h"

extern GPIO_PinConfig  COLS[NUM_OF_COL];
extern GPIO_PinConfig  ROWS[NUM_OF_ROW];
void HLEDMATRIX_voidInit(){
	for (u8 i=0; i<NUM_OF_COL; i++){
		GPIO_voidPinInit(&COLS[i]);
	}
	for (u8 i=0; i<NUM_OF_ROW; i++){
		GPIO_voidPinInit(&ROWS[i]);
	}
	SYSTICK_voidInit();
}
static void HLEDMATRIX_voidSetRowValue(u8 row_value){
	for(u8 j=0; j<NUM_OF_ROW; j++){
		GPIO_voidSetPinValue(ROWS[j].Port,ROWS[j].Pin,GET_BIT(row_value,j));
	}
}
static void HLEDMATRIX_voidDisableColumns(){
	for(u8 i=0; i<NUM_OF_COL; i++){
		GPIO_voidSetPinValue(COLS[i].Port,COLS[i].Pin,GPIO_HIGH);
	}
}
void HLEDMATRIX_voidDisplay(u8 *arr){
	for(u8 j=0;j<50;j++)
	{
		for(u8 R=0; R<NUM_OF_ROW; R++){
			/* Disable all columns */
			HLEDMATRIX_voidDisableColumns();
			/* Set Value on rows */
			HLEDMATRIX_voidSetRowValue(arr[R]);
			/* Enable the column */
			GPIO_voidSetPinValue(COLS[R].Port,COLS[R].Pin,GPIO_LOW);
			/* Delay */
			SYSTICK_voidSetBusyWait((20*1000)/NUM_OF_COL); // 2.5ms
		}
	}
}

void HLEDMATRIX_voidMovementDisplay(u8 *arr, u8 arr_size){
	for(u8 i= 0; i < arr_size-1; i++){
		for(u8 j=0;j<15;j++)
		{
			for(u8 R=0; R<NUM_OF_ROW; R++){
				/* Get Index of Row Data */
				u8 index = ( (i+R) % arr_size );
				/* Disable all columns */
				HLEDMATRIX_voidDisableColumns();
				/* Set Value on rows */
				HLEDMATRIX_voidSetRowValue(arr[index]);
				/* Enable the column */
				GPIO_voidSetPinValue(COLS[R].Port,COLS[R].Pin,GPIO_LOW);
				/* Delay */
				SYSTICK_voidSetBusyWait((20*1000)/NUM_OF_COL); // 2.5ms

			}
		}
	}
}







void HDOTMATRIX_voidInit(GPIO_PinConfig* cols, GPIO_PinConfig* rows){
	for (u8 i=0; i<NUM_OF_COL; i++){
		GPIO_voidPinInit(&cols[i]);
	}
	for (u8 i=0; i<NUM_OF_ROW; i++){
		GPIO_voidPinInit(&rows[i]);
	}
	SYSTICK_voidInit();
}
static void HDOTMATRIX_voidSetRowValue(u8 row_value, GPIO_PinConfig* rows){
	for(u8 j=0; j<NUM_OF_ROW; j++){
		GPIO_voidSetPinValue(rows[j].Port,rows[j].Pin,GET_BIT(row_value,j));
	}
}
void HDOTMATRIX_voidDisplay(u8 *arr,GPIO_PinConfig* cols,GPIO_PinConfig* rows){
	for(u8 j=0;j<50;j++)
	{
		for(u8 R=0; R<NUM_OF_ROW; R++){
			/* Disable all columns */
			for(u8 i=0; i<NUM_OF_COL; i++){
				GPIO_voidSetPinValue(cols[i].Port,cols[i].Pin,GPIO_HIGH);
			}
			/* Set Value on rows */
			HDOTMATRIX_voidSetRowValue(arr[R],rows);
			/* Enable the column */
			GPIO_voidSetPinValue(cols[R].Port,cols[R].Pin,GPIO_LOW);
			/* Delay */
			SYSTICK_voidSetBusyWait((20*1000)/NUM_OF_COL); // 2.5ms

		}
	}
}
