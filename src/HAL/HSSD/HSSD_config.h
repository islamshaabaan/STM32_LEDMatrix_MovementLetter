/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   HSSD                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/
#ifndef HAL_HSSD_HSSD_CONFIG_H_
#define HAL_HSSD_HSSD_CONFIG_H_

/**************************************************************************/
/*  define the 7Segment Type:                                             */
/*                           1- COM_CATHODE                               */
/*                           2- COM_ANODE                                 */
/**************************************************************************/
#define    	HSSD_TYPE      COM_CATHODE

/**************************************************************************/
/*    define the port connected to the 7-segment display                  */
/**************************************************************************/
#define 	HSSD_PORT 		GPIO_PORTA

/**************************************************************************/
/*    define the pins connected to the 7-segment display                  */
/**************************************************************************/
typedef enum
{
	HSSD_PIN_A = 0,
	HSSD_PIN_B ,
	HSSD_PIN_C ,
	HSSD_PIN_D ,
	HSSD_PIN_E ,
	HSSD_PIN_F ,
	HSSD_PIN_G
}HSSD_PIN_t;




#endif /* HAL_HSSD_HSSD_CONFIG_H_ */
