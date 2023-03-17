/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Interrupt.c
 *        \brief  Interrupt Module
 *
 *      \details  The Driver Configure Interrupt Module
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Register_Map.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern CB_type SYSTICK_CALL_BACK_PTR;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntMasterEnable (void)
* \Description     : Enables the processor interrupt                                    
*******************************************************************************/
void IntMasterEnable (void){
  /*Enable processor interrupts.*/
  __asm volatile ("cpsie i" : : : "memory");
}

/******************************************************************************
* \Syntax          : void IntMasterDisable (void)
* \Description     : Disables the processor interrupt                                    
*******************************************************************************/
void IntMasterDisable (void){
	/*Disable processor interrupts.*/	
	__asm volatile ("cpsid i" : : : "memory");
}

/******************************************************************************
* \Syntax          : void 	IntRegister (uint32_t ui32Interrupt, void(*pfnHandler)(void))
* \Description     : Registers a function to be called when an interrupt occurs.                                   
*******************************************************************************/
void 	IntRegister (uint32 ui32Interrupt, CB_type pfnHandler){
	if (pfnHandler != NULL_PTR){
		switch(ui32Interrupt){
			case SYSTICK_EXCEPTION: SYSTICK_CALL_BACK_PTR = pfnHandler; break; 
			/*TODO REMAINING INTERRUPTS*/
		}
	}else{
		return;
	}
}
 
/******************************************************************************
* \Syntax          : void IntUnregister (uint32_t ui32Interrupt)
* \Description     : Unregisters the function to be called when an interrupt occurs.
*******************************************************************************/
void 	IntUnregister (uint32 ui32Interrupt){
		switch(ui32Interrupt){
			case SYSTICK_EXCEPTION: SYSTICK_CALL_BACK_PTR = NULL_PTR; break; 
			/*TODO REMAINING INTERRUPTS*/
		}
}

/******************************************************************************
* \Syntax          : void IntPriorityGroupingSet (uint32 ui32Bits)
* \Description     : Sets the priority grouping of the interrupt controller                                    
*******************************************************************************/
void IntPriorityGroupingSet (uint32 ui32Bits){
    /*TODO IntPriorityGroupingSet*/
}


/******************************************************************************
* \Syntax          : uint32 IntPriorityGroupingGet (void)
* \Description     : Gets the priority grouping of the interrupt controller                                   
*******************************************************************************/
uint32 IntPriorityGroupingGet (void){
	/*TODO IntPriorityGroupingGet*/
}


/******************************************************************************
* \Syntax          : void IntPrioritySet (uint32 ui32Interrupt, uint8 ui8Priority)
* \Description     : Sets the priority of an interrupt.                                 
*******************************************************************************/
void IntPrioritySet (uint32 ui32Interrupt, uint8 ui8Priority){
  /*TODO IntPriorityGet*/
}


/******************************************************************************
* \Syntax          : sint32 IntPriorityGet (uint32 ui32Interrupt)
* \Description     : Gets the priority of an interrupt.                                    
*******************************************************************************/
sint32 IntPriorityGet (uint32 ui32Interrupt){
  /*TODO IntPriorityGet*/
	return 0;
}


/******************************************************************************
* \Syntax          : void 	IntEnable (uint32 ui32Interrupt)
* \Description     : Enables an interrupt                                    
*******************************************************************************/
void 	IntEnable (uint32 ui32Interrupt){
   
    /*Determine the interrupt to enable.*/
    if(ui32Interrupt == MPU_EXCEPTION){
        
			  /*Enable the MemManage interrupt.*/
        SYSHNDCTRL |= NVIC_SYS_HND_CTRL_MEM;
    
		}else if(ui32Interrupt == BUS_FAULT_EXCEPTION){
    
  			/*Enable the bus fault interrupt.*/
        SYSHNDCTRL |= NVIC_SYS_HND_CTRL_BUS;
  
		}else if(ui32Interrupt == USAGE_FAULT_EXCEPTION){
			
        /*Enable the usage fault interrupt.*/
        SYSHNDCTRL |= NVIC_SYS_HND_CTRL_USAGE;

    }else if(ui32Interrupt == SYSTICK_EXCEPTION){
			
        /*Enable the System Tick interrupt.*/
        STCTRL |= NVIC_ST_CTRL_INTEN;

    }else if(ui32Interrupt <= 31){
			
        /*Enable the general interrupt 0.*/
			  SET_BIT(EN0 , ui32Interrupt );

    }else if(ui32Interrupt <= 63){
			
        /*Enable the general interrupt 1.*/
			  SET_BIT(EN1 , (ui32Interrupt - 32) );

    }else if(ui32Interrupt <= 95){
			
        /*Enable the general interrupt 2.*/
			  SET_BIT(EN2 , (ui32Interrupt - 64) );

    }else if(ui32Interrupt <= 127){
			
        /*Enable the general interrupt 3.*/
			  SET_BIT(EN3 , (ui32Interrupt - 96) );

    }else if(ui32Interrupt <= 138){
			
        /*Enable the general interrupt 4.*/
			  SET_BIT(EN4 , (ui32Interrupt - 128) );
    }
}
/******************************************************************************
* \Syntax          : void 	IntDisable (uint32 ui32Interrupt)
* \Description     : Disables an interrupt                                   
*******************************************************************************/
void 	IntDisable (uint32 ui32Interrupt){

    /*Determine the interrupt to enable.*/
    if(ui32Interrupt == MPU_EXCEPTION){
        
			  /*Enable the MemManage interrupt.*/
        SYSHNDCTRL &= ~((uint32)(NVIC_SYS_HND_CTRL_MEM));
    
		}else if(ui32Interrupt == BUS_FAULT_EXCEPTION){
    
  			/*Enable the bus fault interrupt.*/
        SYSHNDCTRL &= ~((uint32)( NVIC_SYS_HND_CTRL_BUS));
  
		}else if(ui32Interrupt == USAGE_FAULT_EXCEPTION){
			
        /*Enable the usage fault interrupt.*/
        SYSHNDCTRL &= ~((uint32)(NVIC_SYS_HND_CTRL_USAGE));

    }else if(ui32Interrupt == SYSTICK_EXCEPTION){
			
        /*Enable the System Tick interrupt.*/
        STCTRL &= ~((uint32)(NVIC_ST_CTRL_INTEN));

    }else if(ui32Interrupt <= 31){
			
        /*Enable the general interrupt 0.*/
			  CLEAR_BIT(EN0 , ui32Interrupt );

    }else if(ui32Interrupt <= 63){
			
        /*Enable the general interrupt 1.*/
			  CLEAR_BIT(EN1 , (ui32Interrupt - 32) );

    }else if(ui32Interrupt <= 95){
			
        /*Enable the general interrupt 2.*/
			  CLEAR_BIT(EN2 , (ui32Interrupt - 64) );

    }else if(ui32Interrupt <= 127){
			
        /*Enable the general interrupt 3.*/
			  CLEAR_BIT(EN3 , (ui32Interrupt - 96) );

    }else if(ui32Interrupt <= 138){
			
        /*Enable the general interrupt 4.*/
			  CLEAR_BIT(EN4 , (ui32Interrupt - 128) );
    }
}




/******************************************************************************
* \Syntax          : uint32 IntIsEnabled (uint32 ui32Interrupt)
* \Description     : This function checks if the specified interrupt is enabled 
*                    in the interrupt controller.                                  
*******************************************************************************/
uint32 IntIsEnabled (uint32 ui32Interrupt){
	/*TODO IntIsEnabled*/
	return 0;
}


/******************************************************************************
* \Syntax          : void IntPendSet (uint32 ui32Interrupt)
* \Description     : Pends an interrupt.                                    
*******************************************************************************/
void 	IntPendSet (uint32 ui32Interrupt){
	/*TODO IntPendSet function*/
}


/******************************************************************************
* \Syntax          : void IntPendClear (uint32 ui32Interrupt)
* \Description     : UnPends an interrupt.
*******************************************************************************/
void IntPendClear (uint32 ui32Interrupt){
  /*TODO IntPendClear */
}


/******************************************************************************
* \Syntax          : uint32 IntPriorityMaskSet (void)
* \Description     : This function sets the interrupt priority masking level so 
*                    that all interrupts at the specified or lesser priority 
*                    level are masked. Masking interrupts can be used to globally 
*                    disable a set of interrupts with priority below a predetermined 
*                    threshold. A value of 0 disables priority masking.
*******************************************************************************/
void IntPriorityMaskSet (uint32 ui32PriorityMask){
	/*TODO IntPriorityMaskSet*/
}


/******************************************************************************
* \Syntax          : uint32 IntPriorityMaskGet (void)
* \Description     : This function gets the current setting of the interrupt 
*                    priority masking level. The value returned is the priority 
*                    level such that all interrupts of that and lesser priority 
*                    are masked. A value of 0 means that priority masking is 
*                    disabled.                                    
*******************************************************************************/
uint32 IntPriorityMaskGet (void){
	/*TODO IntPriorityMaskGet*/
	return 0;
}


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
void IntTrigger (uint32 ui32Interrupt){
	/*TODO IntTrigger Function*/
}


/**********************************************************************************************************************
 *  END OF FILE: Intterrupt.c
 *********************************************************************************************************************/
