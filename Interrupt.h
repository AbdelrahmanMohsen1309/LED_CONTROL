/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Interrupt.h
 *       Module:  Interrupt Module
 *
 *  Description:  Header file for Interrupt Module    
 *  
 *********************************************************************************************************************/
#ifndef INTERRUPT_H
#define INTERRUPT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Register_Map.h"
/**********************************************************************************************************************
 *  Local Functions
 *********************************************************************************************************************/
void SysTick_Handler(void);
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Local DATA TYPES
 *********************************************************************************************************************/
typedef void(*CB_type)(void);
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /******************************************************************************
* \Syntax          : void IntMasterEnable (void)
* \Description     : Enables the processor interrupt                                    
*******************************************************************************/
void IntMasterEnable (void);


/******************************************************************************
* \Syntax          : void IntMasterDisable (void)
* \Description     : Disables the processor interrupt                                    
*******************************************************************************/
void IntMasterDisable (void);

/******************************************************************************
* \Syntax          : void 	IntRegister (uint32_t ui32Interrupt, void(*pfnHandler)(void))
* \Description     : Registers a function to be called when an interrupt occurs.                                   
*******************************************************************************/
void 	IntRegister (uint32 ui32Interrupt, CB_type pfnHandler);
 
/******************************************************************************
* \Syntax          : void IntUnregister (uint32_t ui32Interrupt)
* \Description     : Unregisters the function to be called when an interrupt occurs.
*******************************************************************************/
void 	IntUnregister (uint32 ui32Interrupt);


/******************************************************************************
* \Syntax          : void IntPriorityGroupingSet (uint32 ui32Bits)
* \Description     : Sets the priority grouping of the interrupt controller                                    
*******************************************************************************/
void IntPriorityGroupingSet (uint32 ui32Bits);


/******************************************************************************
* \Syntax          : uint32 IntPriorityGroupingGet (void)
* \Description     : Gets the priority grouping of the interrupt controller                                   
*******************************************************************************/
uint32 IntPriorityGroupingGet (void);


/******************************************************************************
* \Syntax          : void IntPrioritySet (uint32 ui32Interrupt, uint8 ui8Priority)
* \Description     : Sets the priority of an interrupt.                                 
*******************************************************************************/
void IntPrioritySet (uint32 ui32Interrupt, uint8 ui8Priority);

/******************************************************************************
* \Syntax          : sint32 IntPriorityGet (uint32 ui32Interrupt)
* \Description     : Gets the priority of an interrupt.                                    
*******************************************************************************/
sint32 IntPriorityGet (uint32 ui32Interrupt);
/******************************************************************************
* \Syntax          : void 	IntEnable (uint32 ui32Interrupt)
* \Description     : Enables an interrupt                                    
*******************************************************************************/
void 	IntEnable (uint32 ui32Interrupt);
/******************************************************************************
* \Syntax          : void 	IntDisable (uint32 ui32Interrupt)
* \Description     : Disables an interrupt                                   
*******************************************************************************/
void 	IntDisable (uint32 ui32Interrupt);
/******************************************************************************
* \Syntax          : uint32 IntIsEnabled (uint32 ui32Interrupt)
* \Description     : This function checks if the specified interrupt is enabled 
*                    in the interrupt controller.                                  
*******************************************************************************/
uint32 IntIsEnabled (uint32 ui32Interrupt);


/******************************************************************************
* \Syntax          : void IntPendSet (uint32 ui32Interrupt)
* \Description     : Pends an interrupt.                                    
*******************************************************************************/
void 	IntPendSet (uint32 ui32Interrupt);


/******************************************************************************
* \Syntax          : void IntPendClear (uint32 ui32Interrupt)
* \Description     : UnPends an interrupt.
*******************************************************************************/
void IntPendClear (uint32 ui32Interrupt);


/******************************************************************************
* \Syntax          : uint32 IntPriorityMaskSet (void)
* \Description     : This function sets the interrupt priority masking level so 
*                    that all interrupts at the specified or lesser priority 
*                    level are masked. Masking interrupts can be used to globally 
*                    disable a set of interrupts with priority below a predetermined 
*                    threshold. A value of 0 disables priority masking.
*******************************************************************************/
void IntPriorityMaskSet (uint32 ui32PriorityMask);


/******************************************************************************
* \Syntax          : uint32 IntPriorityMaskGet (void)
* \Description     : This function gets the current setting of the interrupt 
*                    priority masking level. The value returned is the priority 
*                    level such that all interrupts of that and lesser priority 
*                    are masked. A value of 0 means that priority masking is 
*                    disabled.                                    
*******************************************************************************/
uint32 IntPriorityMaskGet (void);


/******************************************************************************
* \Syntax          : void IntTrigger (uint32 ui32Interrupt) 
* \Description     : This function performs a software trigger of an interrupt. 
*										 The ui32Interrupt parameter must valid INT_*. The interrupt 
*                    controller behaves as if the corresponding interrupt line 
*                    was asserted, and the interrupt is handled in the same manner 
*                    (meaning that it must be enabled in order to be processed, 
*                    and the processing is based on its priority with respect to 
*                    other unhandled interrupts).
*******************************************************************************/
void IntTrigger (uint32 ui32Interrupt);
#endif  /* Interrupt */

/**********************************************************************************************************************
 *  END OF FILE: Interrupt.h
 *********************************************************************************************************************/
