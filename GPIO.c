/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  General purpose Input Output Register Driver
 *
 *      \details  The Driver Configure All MCU Ports
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void 	GPIODirModeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32PinIO)
* \Description     : Sets the direction and mode of the specified pin(s).                                    
*******************************************************************************/
 void 	GPIODirModeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32PinIO){
	 ( ui32PinIO ? (SET_BIT(GPIO_DIR(ui32Port),ui8Pins)) : (CLEAR_BIT(GPIO_DIR(ui32Port),ui8Pins)));
 }
/******************************************************************************
* \Syntax          : uint32 	GPIODirModeGet (uint32 ui32Port, uint8 ui8Pin)
* \Description     : Gets the direction and mode of the specified pin(s).                                    
*******************************************************************************/
 uint32 	GPIODirModeGet (uint32 ui32Port, uint8 ui8Pin){
	 return BIT_IS_SET(GPIO_DIR(ui32Port),ui8Pin);
 }
/******************************************************************************
* \Syntax          : void 	GPIOIntTypeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32IntType)
* \Description     : Sets the interrupt type for the specified pin(s).                                   
*******************************************************************************/
 void 	GPIOIntTypeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32IntType){
    ((ui32IntType & GPIO_BOTH_EDGES)  ? (SET_BIT(GPIO_IBE(ui32Port),ui8Pins)) : (CLEAR_BIT(GPIO_IBE(ui32Port),ui8Pins)));
    ((ui32IntType & GPIO_LOW_LEVEL)   ? (SET_BIT(GPIO_IS(ui32Port),ui8Pins))  : (CLEAR_BIT(GPIO_IS(ui32Port),ui8Pins)));
	  ((ui32IntType & GPIO_RISING_EDGE) ? (SET_BIT(GPIO_IEV(ui32Port),ui8Pins)) : (CLEAR_BIT(GPIO_IEV(ui32Port),ui8Pins)));
 }
 /******************************************************************************
* \Syntax          : uint32 	GPIOIntTypeGet (uint32 ui32Port, uint8 ui8Pin)
* \Description     : Gets the interrupt type for the specified pin(s).                                   
*******************************************************************************/
 uint32 	GPIOIntTypeGet (uint32 ui32Port, uint8 ui8Pin){
	 return (((GPIO_IBE(ui32Port)&ui8Pin) ? GPIO_BOTH_EDGES : 0)
		      |((GPIO_IS(ui32Port)&ui8Pin)  ? GPIO_LOW_LEVEL : 0)
	        |((GPIO_IEV(ui32Port)&ui8Pin) ? GPIO_RISING_EDGE : GPIO_FALLING_EDGE));
 }
 /******************************************************************************
* \Syntax          : void 	GPIOPadConfigSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32Strength, uint32 ui32PinType)
* \Description     : Sets the pad configuration for the specified pin(s).
*******************************************************************************/ 
 void 	GPIOPadConfigSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32Strength, uint32 ui32PinType){
		
	 (ui32Strength&PORT_PIN_CUR_2MA)?(SET_BIT(GPIO_DR2R(ui32Port),ui8Pins)) :(CLEAR_BIT(GPIO_DR2R(ui32Port),ui8Pins));
	 (ui32Strength&PORT_PIN_CUR_4MA)?(SET_BIT(GPIO_DR4R(ui32Port),ui8Pins)) :(CLEAR_BIT(GPIO_DR4R(ui32Port),ui8Pins));
	 (ui32Strength&PORT_PIN_CUR_8MA)?(SET_BIT(GPIO_DR8R(ui32Port),ui8Pins)) :(CLEAR_BIT(GPIO_DR8R(ui32Port),ui8Pins));
	 (ui32Strength&PORT_PIN_CUR_SLR)?(SET_BIT(GPIO_SLR (ui32Port),ui8Pins)) :(CLEAR_BIT(GPIO_SLR (ui32Port),ui8Pins));
    
	 (ui32PinType&PORT_PIN_ODR)     ?(SET_BIT(GPIO_ODR(ui32Port),ui8Pins))  :(CLEAR_BIT(GPIO_ODR(ui32Port),ui8Pins));
	 (ui32PinType&PORT_PIN_PUR)     ?(SET_BIT(GPIO_PUR(ui32Port),ui8Pins))  :(CLEAR_BIT(GPIO_PUR(ui32Port),ui8Pins));
	 (ui32PinType&PORT_PIN_PDR)     ?(SET_BIT(GPIO_PDR(ui32Port),ui8Pins))  :(CLEAR_BIT(GPIO_PDR(ui32Port),ui8Pins));
	 (ui32PinType&PORT_PIN_DEN)     ?(SET_BIT(GPIO_DEN(ui32Port),ui8Pins))  :(CLEAR_BIT(GPIO_DEN(ui32Port),ui8Pins));
	 (ui32PinType&PORT_PIN_AEN)     ?(SET_BIT(GPIO_AMSEL(ui32Port),ui8Pins)):(CLEAR_BIT(GPIO_AMSEL(ui32Port),ui8Pins));
		
 }
 /******************************************************************************
* \Syntax          : void 	GPIOPadConfigGet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32Strength, uint32 ui32PinType)
* \Description     : Gets the pad configuration for the specified pin(s).
*******************************************************************************/
 void 	GPIOPadConfigGet (uint32 ui32Port, uint8 ui8Pin, uint32 *pui32Strength, uint32 *pui32PinType){
	/*TODO GPIOPadConfigGet*/
 }
/******************************************************************************
* \Syntax          : void 	GPIOIntEnable (uint32 ui32Port, uint8 pin)
* \Description     : Enables the specified GPIO interrupts.
*******************************************************************************/
 void 	GPIOIntEnable (uint32 ui32Port, uint8 pin){
		SET_BIT(GPIO_IM(ui32Port),pin);
 }
/******************************************************************************
* \Syntax          : void 	GPIOIntDisable (uint32 ui32Port, uint8 pin)
* \Description     : Disables the specified GPIO interrupts.
*******************************************************************************/
 void 	GPIOIntDisable (uint32 ui32Port, uint8 pin){
		CLEAR_BIT(GPIO_IM(ui32Port),pin);
 }
/******************************************************************************
* \Syntax          : uint32 	GPIOIntStatus (uint32 ui32Port, boolean bMasked)
* \Description     : Gets interrupt status for the specified GPIO port.
*******************************************************************************/
 uint32 	GPIOIntStatus (uint32 ui32Port, boolean bMasked){
   /*TODO GPIOIntStatus*/
	 return 0;
 }
/******************************************************************************
* \Syntax          : void 	GPIOIntClear (uint32 ui32Port, uint32 ui32IntFlags)
* \Description     : Clears the specified interrupt sources.
*******************************************************************************/ 
 void 	GPIOIntClear (uint32 ui32Port, uint32 ui32IntFlags){
	/*TODO GPIOIntClear*/
 }
 /******************************************************************************
* \Syntax          : void 	GPIOIntRegister (uint32 ui32Port, void(*pfnIntHandler)(void))
* \Description     : Registers an interrupt handler for a GPIO port.
*******************************************************************************/
 void 	GPIOIntRegister (uint32 ui32Port, void(*pfnIntHandler)(void)){
	/*TODO GPIOIntRegister*/
 }
 /******************************************************************************
* \Syntax          : void 	GPIOIntUnregister (uint32 ui32Port)
* \Description     : Removes an interrupt handler for a GPIO port.
*******************************************************************************/
 void 	GPIOIntUnregister (uint32 ui32Port){
	/*TODO GPIOIntUnregister*/
 }
 /******************************************************************************
* \Syntax          : void 	GPIOIntRegisterPin (uint32 ui32Port, uint32 ui32Pin, void(*pfnIntHandler)(void))
* \Description     : Registers an interrupt handler for an individual pin of a GPIO port.
*******************************************************************************/
 void 	GPIOIntRegisterPin (uint32 ui32Port, uint32 ui32Pin, void(*pfnIntHandler)(void)){
	/*TODO GPIOIntRegisterPin*/
 }
 /******************************************************************************
* \Syntax          : void 	GPIOIntUnRegisterPin (uint32 ui32Port, uint32 ui32Pin)
* \Description     : Removes an interrupt handler for an individual pin of a GPIO port.
*******************************************************************************/
 void 	GPIOIntUnregisterPin (uint32 ui32Port, uint32 ui32Pin){
	/*TODO GPIOIntUnregisterPin*/
 }
 /******************************************************************************
* \Syntax          :  uint32 	GPIOPinRead (uint32 ui32Port, uint8 ui8Pins)
* \Description     :  Reads the values present of the specified pin(s).
*******************************************************************************/
 uint32 	GPIOPinRead (uint32 ui32Port, uint8 ui8Pins){
	return BIT_IS_SET(GPIO_DATA(ui32Port),ui8Pins);
 }
 /******************************************************************************
* \Syntax          : void 	GPIOPinWrite (uint32 ui32Port, uint8 ui8Pins, uint8 ui8Val)
* \Description     : Writes a value to the specified pin(s).
*******************************************************************************/
 void 	GPIOPinWrite (uint32 ui32Port, uint8 ui8Pins, uint8 ui8Val){
	 (ui8Val) ? SET_BIT(GPIO_DATA(ui32Port),ui8Pins):(CLEAR_BIT(GPIO_DATA(ui32Port),ui8Pins));
 }
#ifdef FUNCTIONS_TODO_ADDED_IN_GPIO_DRIVER
 void 	GPIOPinTypeADC (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeADC*/
 }
 void 	GPIOPinTypeCAN (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeCAN*/
 }
 void 	GPIOPinTypeComparator (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeComparator*/
 }
 void 	GPIOPinTypeComparatorOutput (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeComparatorOutput*/
 }
 void 	GPIOPinTypeDIVSCLK (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeDIVSCLK*/
 }
 void 	GPIOPinTypeEPI (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeEPI*/
 }
 void 	GPIOPinTypeEthernetLED (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeEthernetLED*/
 }
 void 	GPIOPinTypeEthernetMII (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeEthernetMII*/
 }
 void 	GPIOPinTypeGPIOInput (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeGPIOInput*/
 }
 void 	GPIOPinTypeGPIOOutput (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeGPIOOutput*/
 }
 void 	GPIOPinTypeGPIOOutputOD (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeGPIOOutputOD*/
 }
 void 	GPIOPinTypeHibernateRTCCLK (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeHibernateRTCCLK*/
 }
 void 	GPIOPinTypeI2C (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeI2C*/
 }
 void 	GPIOPinTypeI2CSCL (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeI2CSCL*/
 }
 void 	GPIOPinTypeLCD (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeLCD*/
 }
 void 	GPIOPinTypeOneWire (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeOneWire*/
 }
 void 	GPIOPinTypePWM (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypePWM*/
 }
 void 	GPIOPinTypeQEI (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeQEI*/
 }
 void 	GPIOPinTypeSSI (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeSSI*/
 }
 void 	GPIOPinTypeTimer (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeTimer*/
 }
 void 	GPIOPinTypeTrace (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeTrace*/
 }
 void 	GPIOPinTypeUART (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeUART*/
 }
 void 	GPIOPinTypeUSBAnalog (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeUSBAnalog*/
 }
 void 	GPIOPinTypeUSBDigital (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeUSBDigital*/
 }
 void 	GPIOPinTypeWakeHigh (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeWakeHigh*/
 }
 void 	GPIOPinTypeWakeLow (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOPinTypeWakeLow*/
 }
 uint32 	GPIOPinWakeStatus (uint32 ui32Port){
	/*TODO GPIOPinWakeStatus*/
	 return 0;
 }
 void 	GPIOPinConfigure (uint32 ui32PinConfig){
	/*TODO GPIOPinConfigure*/
 }
 void 	GPIODMATriggerEnable (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIODMATriggerEnable*/
 }
 void 	GPIODMATriggerDisable (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIODMATriggerDisable*/
 }
 void 	GPIOADCTriggerEnable (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOADCTriggerEnable*/
 }
 void 	GPIOADCTriggerDisable (uint32 ui32Port, uint8 ui8Pins){
	/*TODO GPIOADCTriggerDisable*/
 }

#endif
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
