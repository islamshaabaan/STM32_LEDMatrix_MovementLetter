
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"

#include "HAL/HLEDMATRIX/HLEDMTARIX_interface.h"

#define DATA_SIZE 40
u8 Islam_ARR[DATA_SIZE] = {
		0x00,		0x42,		0x42,	0x7e,		0x7e,		0x42,		0x42,		0,		// I
		0x00,		0x00,		0x4c,	0x4a,		0x4a,		0x4a,		0x32,		0,		// S
		0x00,		0x00,		0x7e,	0x40,		0x40,		0x40,		0x00,		0,// L
		0,		124,	18,		18,		18,		124,	0,		0,			// A
		60,		2,		2,		60,		2,		2,		60,		0			// M
}; // FAtmA
void main()
{

	/*
			0,		124,	18,		18,		18,		124,	0,		0,								// A
			0x00,		0x42,		0x42,	0x7e,		0x7e,		0x42,		0x42,		0,		// I
			0x00,		0x00,		0x4c,	0x4a,		0x4a,		0x4a,		0x32,		0,		// S
			0x00,		0x00,		0x7e,	0x40,		0x40,		0x40,		0x00,		0,		// L
			0,		0,		126,	18,		18,		2,		0,		0,								// F
			0,		4,		126,	68,		0,		0,		0,		0,								// T
			60,		2,		2,		60,		2,		2,		60,		0,								// M
	 */
	RCC_voidInit();
	RCC_u8EnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOA);
	RCC_u8EnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOB);

	//HDOTMATRIX_voidInit(COLS,ROWS);
	HLEDMATRIX_voidInit();

	// Infinite loop
	while (1)
	{
		//HDOTMATRIX_voidDisplay(Display_ARR,COLS,ROWS);
		HLEDMATRIX_voidMovementDisplay(Islam_ARR,DATA_SIZE);
	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
