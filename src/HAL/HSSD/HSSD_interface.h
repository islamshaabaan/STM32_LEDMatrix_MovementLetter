/******************************************************/
/*      Author  : Islam Shaaban Hussein               */
/*      SWC     :   HSSD                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/
#ifndef HAL_HSSD_HSSD_INTERFACE_H_
#define HAL_HSSD_HSSD_INTERFACE_H_


/**************************************************************************/
/*         Define H7SEG configuration for COMMON CATHODE                  */
/**************************************************************************/
#if     HSSD_TYPE  ==  COM_CATHODE

#define NUMBER_ZERO  	0x003F
#define NUMBER_ONE  	0x0006
#define NUMBER_TWO	    0x005B
#define NUMBER_THREE	0x004F
#define NUMBER_FOUR	    0x0066
#define NUMBER_FIVE 	0x006D
#define NUMBER_SIX  	0x007D
#define NUMBER_SEVEN	0x0007
#define NUMBER_EIGHT	0x007F
#define NUMBER_NINE  	0x006F

/**************************************************************************/
/*         Define H7SEG configuration for COMMON ANODE                    */
/**************************************************************************/
#elif   HSSD_TYPE  ==  COM_ANODE

#define NUMBER_ZERO  	0x00C0
#define NUMBER_ONE  	0x00F9
#define NUMBER_TWO	    0x00A4
#define NUMBER_THREE	0x00B0
#define NUMBER_FOUR	    0x0099
#define NUMBER_FIVE 	0x0092
#define NUMBER_SIX  	0x0082
#define NUMBER_SEVEN	0x00F8
#define NUMBER_EIGHT	0x0080
#define NUMBER_NINE  	0x0090

#endif

/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
void HSSD_voidInit (void);
void HSSD_voidDisplay_Number(u8 Copy_u8Number);



#endif /* HAL_HSSD_HSSD_INTERFACE_H_ */
