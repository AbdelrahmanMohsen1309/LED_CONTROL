/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  System Timer Module
 *
 *      \details  The Driver Configure System Timer Module
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Register_Map.h"

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
CB_type SYSTICK_CALL_BACK_PTR = NULL_PTR;

/**********************************************************************************************************************
 *  Handler Function
 *********************************************************************************************************************/
void SysTick_Handler(void){
	if(SYSTICK_CALL_BACK_PTR != NULL_PTR){
		SYSTICK_CALL_BACK_PTR();
	}
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void SysTickEnable (void)                                      
* \Description     : This function starts the SysTick counter. 
*                    If an interrupt handler has been registered, 
*                    it is called when the SysTick counter rolls over.                                    
*******************************************************************************/
void 	SysTickEnable (void){
	SET_BIT(STCTRL, SYSTICK_PIN_CLK_SRC);
	STCURRENT = 0x00;
	SET_BIT(STCTRL, SYSTICK_PIN_ENABLE);
}




/******************************************************************************
* \Syntax          : void 	SysTickDisable (void)
* \Description     : This function stops the SysTick counter. 
*                    If an interrupt handler has been registered, 
*                    it is not called until SysTick is restarted.                                    
*******************************************************************************/
void 	SysTickDisable (void){
	CLEAR_BIT(STCTRL, SYSTICK_PIN_ENABLE);
}




/******************************************************************************
* \Syntax          : void 	SysTickIntRegister (CB_type pfnHandler)
* \Description     : This function registers the handler to be called 
*                    when a SysTick interrupt occurs.                                    
*******************************************************************************/
void 	SysTickIntRegister (CB_type pfnHandler){
	if (pfnHandler != NULL_PTR){
		SYSTICK_CALL_BACK_PTR = pfnHandler;
	}else{
		return;
	}
}

/******************************************************************************
* \Syntax          : void 	SysTickIntUnregister (void)
* \Description     : This function unregisters the handler to be called 
*                    when a SysTick interrupt occurs.                                    
*******************************************************************************/
void 	SysTickIntUnregister (void){
  SYSTICK_CALL_BACK_PTR = NULL_PTR;
}


/******************************************************************************
* \Syntax          : void 	SysTickIntEnable (void)
* \Description     : This function enables the SysTick interrupt, 
*                    allowing it to be reflected to the processor.                                    
*******************************************************************************/
void 	SysTickIntEnable (void){
	SET_BIT(STCTRL, SYSTICK_PIN_INTEN);
}




/******************************************************************************
* \Syntax          : void 	SysTickIntDisable (void)
* \Description     : This function disables the SysTick interrupt, 
*                    preventing it from being reflected to the processor.                                    
*******************************************************************************/
void 	SysTickIntDisable (void){
	CLEAR_BIT(STCTRL, SYSTICK_PIN_INTEN);
}




/******************************************************************************
* \Syntax          : void 	SysTickPeriodSet (uint32 ui32Period);
* \Description     : This function sets the rate at which the SysTick counter 
*                    wraps, which equates to the number of processor clocks 
*                    between interrupts.                                    
*******************************************************************************/
void 	SysTickPeriodSet (uint32 ui32Period){
	STRELOAD |= (0x00FFFFFF & ui32Period);
}






/******************************************************************************
* \Syntax          : uint32 	SysTickPeriodGet (void)
* \Description     : This function returns the rate at which the SysTick counter 
*                    wraps, which equates to the number of processor clocks 
*                    between interrupts.  
*******************************************************************************/
uint32 	SysTickPeriodGet (void){
	return STRELOAD;
}






/******************************************************************************
* \Syntax          : uint32 	SysTickValueGet (void)
* \Description     : This function returns the current value of the SysTick 
*                    counter, which is a value between the period - 1 and zero, 
*                    inclusive.                                    
*******************************************************************************/
uint32 	SysTickValueGet (void){
	return STCURRENT;
}




/**********************************************************************************************************************
 *  END OF FILE: SystickTimer.c
 *********************************************************************************************************************/
