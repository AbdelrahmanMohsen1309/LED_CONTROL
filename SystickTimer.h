/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick.h
 *       Module:  System timer
 *
 *  Description:  Header file for System Timer Module    
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Register_Map.h"


/**********************************************************************************************************************
 *  Global Enumurations and Structures (Configuration Options)
 *********************************************************************************************************************/
/*Enum for Systick regiser pins*/
enum{SYSTICK_PIN_ENABLE       , SYSTICK_PIN_INTEN        , SYSTICK_PIN_CLK_SRC};

/*Enum for Disable and enable Systick*/
enum{SYSTICK_DISABLE          , SYSTICK_ENABLE};

/*Enum for Disable and enable Systick interrupt*/
enum{SYSTICK_INTERRUPT_DISABLE, SYSTICK_INTERRUPT_ENABLE};

/*Enum for Systick Clock*/
enum{SYSTIC_CLK_DIVIDED_BY_4  , SYSTIC_SYSTEM_CLK};


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SysTick_Handler(void);
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void SysTickEnable (void)                                      
* \Description     : This function starts the SysTick counter. 
*                    If an interrupt handler has been registered, 
*                    it is called when the SysTick counter rolls over.
*******************************************************************************/
void 	SysTickEnable (void);


/******************************************************************************
* \Syntax          : void 	SysTickDisable (void)
* \Description     : This function stops the SysTick counter. 
*                    If an interrupt handler has been registered, 
*                    it is not called until SysTick is restarted.
*******************************************************************************/
void 	SysTickDisable (void);


/******************************************************************************
* \Syntax          : void 	SysTickIntRegister (CB_type pfnHandler)
* \Description     : This function registers the handler to be called 
*                    when a SysTick interrupt occurs.
*******************************************************************************/
void 	SysTickIntRegister (CB_type pfnHandler);


/******************************************************************************
* \Syntax          : void 	SysTickIntUnregister (void)
* \Description     : This function unregisters the handler to be called 
*                    when a SysTick interrupt occurs.
*******************************************************************************/
void 	SysTickIntUnregister (void);


/******************************************************************************
* \Syntax          : void 	SysTickIntEnable (void)
* \Description     : This function enables the SysTick interrupt, 
*                    allowing it to be reflected to the processor.
*******************************************************************************/
void 	SysTickIntEnable (void);


/******************************************************************************
* \Syntax          : void 	SysTickIntDisable (void)
* \Description     : This function disables the SysTick interrupt, 
*                    preventing it from being reflected to the processor.
*******************************************************************************/
void 	SysTickIntDisable (void);


/******************************************************************************
* \Syntax          : void 	SysTickPeriodSet (uint32 ui32Period);
* \Description     : This function sets the rate at which the SysTick counter 
*                    wraps, which equates to the number of processor clocks 
*                    between interrupts.                                    
*******************************************************************************/
void 	SysTickPeriodSet (uint32 ui32Period);


/******************************************************************************
* \Syntax          : uint32 	SysTickPeriodGet (void)
* \Description     : This function returns the rate at which the SysTick counter 
*                    wraps, which equates to the number of processor clocks 
*                    between interrupts.  
*******************************************************************************/
uint32 	SysTickPeriodGet (void);


/******************************************************************************
* \Syntax          : uint32 	SysTickValueGet (void)
* \Description     : This function returns the current value of the SysTick 
*                    counter, which is a value between the period - 1 and zero, 
*                    inclusive.                                    
*******************************************************************************/
uint32 	SysTickValueGet (void);


#endif  /* SYSTICK */

/**********************************************************************************************************************
 *  END OF FILE: SysTick.h
 *********************************************************************************************************************/
