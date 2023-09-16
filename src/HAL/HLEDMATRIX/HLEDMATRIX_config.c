/*
 * HLEDMATRIX_config.c
 *
 *  Created on: Sep 15, 2023
 *      Author: one
 */



#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "HLEDMATRIX_config.h"
GPIO_PinConfig  COLS[NUM_OF_COL] = {
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN0, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN1, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN2, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN3, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN4, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN5, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN6, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
			{ .Port = GPIO_PORTA, .Pin = GPIO_PIN7, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED}
	}	;
	GPIO_PinConfig  ROWS[NUM_OF_ROW] = {
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN0, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN5, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN6, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN7, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN8, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN9, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN10, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED},
				{ .Port = GPIO_PORTB, .Pin = GPIO_PIN12, .Mode = GPIO_MODE_OUTPUT, .OutputType = GPIO_OUTPUT_PUSHPULL , .OutputSpeed = GPIO_OUTPUT_LOW_SPEED}
		}	;
