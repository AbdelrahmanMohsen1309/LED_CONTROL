/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LED.h
 *       Module:  Header File of LED
 *
 *  Description:  header file for General Purpose Input Output Module    
 *  
 *********************************************************************************************************************/
#ifndef LED_H
#define LED_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Register_Map.h"


/**********************************************************************************************************************
 *  Global Structures
 *********************************************************************************************************************/
typedef struct{
	uint32 ui32Port; 
	uint8  ui8Pins;
	uint32 ui32Strength; 
	uint32 ui32PinType;
}LED_Config;


/******************************************************************************
* \Syntax          : void LED_init(void)
* \Description     : initialize LED Hardware by parsing the Configuration 
*                    into GPIO registers                                    
*******************************************************************************/
void LED_init(const LED_Config *ptr);


/******************************************************************************
* \Syntax          : void LED_turn_ON(const LED_Config *ptr)
* \Description     : Turn On LED Hardware by parsing the Configuration 
*                    into GPIO registers                                    
*******************************************************************************/
void LED_turn_ON(const LED_Config *ptr);


/******************************************************************************
* \Syntax          : void LED_turn_OFF(const LED_Config *ptr)
* \Description     : Turn Off LED Hardware by parsing the Configuration 
*                    into GPIO registers                                    
*******************************************************************************/
void LED_turn_OFF(const LED_Config *ptr);


/******************************************************************************
* \Syntax          : void LED_toggle(const LED_Config *ptr)
* \Description     : Toggle LED Hardware by parsing the Configuration 
*                    into GPIO registers                                    
*******************************************************************************/
void LED_toggle(const LED_Config *ptr);


#endif  /* LED */
/**********************************************************************************************************************
 *  END OF FILE: LED.h
 *********************************************************************************************************************/
