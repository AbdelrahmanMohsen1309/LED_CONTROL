/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  General Purpose Input Output register
 *
 *  Description:  header file for General Purpose Input Output Module    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Register_Map.h"

/**********************************************************************************************************************
 *  Global Enumurations and Structures (Configuration Options)
 *********************************************************************************************************************/
/*--------------------Ports Values--------------------*/
enum{GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD, GPIO_PORTE, GPIO_PORTF};

/*--------------------Pins numbers Values--------------------*/
enum{PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7};

/*--------------------Pin Levels Values--------------------*/
enum{PORT_PIN_LOW, PORT_PIN_HIGH, PORT_PIN_LEVEL_INVALID};

/*--------------------Pin Directions Values--------------------*/
enum{PORT_PIN_INPUT, PORT_PIN_OUTPUT, PORT_PIN_DIR_INVALID};

/*--------------------Pin Internal Attach Values--------------------*/
enum{PORT_PIN_ODR, PORT_PIN_PUR, PORT_PIN_PDR, PORT_PIN_DEN, PORT_PIN_AEN, PORT_PIN_RES_INVALID};

/*--------------------Pin Output Current Values--------------------*/
enum{PORT_PIN_CUR_2MA , PORT_PIN_CUR_4MA , PORT_PIN_CUR_8MA, PORT_PIN_CUR_SLR, PORT_PIN_CUR_INVALID};

/*-----------------------Interrupt sense values------------------------------------------------------*/
enum{GPIO_FALLING_EDGE, GPIO_BOTH_EDGES, GPIO_LOW_LEVEL, GPIO_RISING_EDGE = 4, GPIO_HIGH_LEVEL = 7};

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void 	GPIODirModeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32PinIO)
* \Description     : Sets the direction and mode of the specified pin(s).                                    
*******************************************************************************/
 void 	GPIODirModeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32PinIO);


/******************************************************************************
* \Syntax          : uint32 	GPIODirModeGet (uint32 ui32Port, uint8 ui8Pin)
* \Description     : Gets the direction and mode of the specified pin(s).                                    
*******************************************************************************/
 uint32 	GPIODirModeGet (uint32 ui32Port, uint8 ui8Pin);


/******************************************************************************
* \Syntax          : void 	GPIOIntTypeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32IntType)
* \Description     : Sets the interrupt type for the specified pin(s).                                   
*******************************************************************************/
 void 	GPIOIntTypeSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32IntType);


/******************************************************************************
* \Syntax          : uint32 	GPIOIntTypeGet (uint32 ui32Port, uint8 ui8Pin)
* \Description     : Gets the interrupt type for the specified pin(s).                                   
*******************************************************************************/
 uint32 	GPIOIntTypeGet (uint32 ui32Port, uint8 ui8Pin);


/******************************************************************************
* \Syntax          : void 	GPIOPadConfigSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32Strength, uint32 ui32PinType)
* \Description     : Sets the pad configuration for the specified pin(s).
*******************************************************************************/ 
 void 	GPIOPadConfigSet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32Strength, uint32 ui32PinType);


/******************************************************************************
* \Syntax          : void 	GPIOPadConfigGet (uint32 ui32Port, uint8 ui8Pins, uint32 ui32Strength, uint32 ui32PinType)
* \Description     : Gets the pad configuration for the specified pin(s).
*******************************************************************************/
 void 	GPIOPadConfigGet (uint32 ui32Port, uint8 ui8Pin, uint32 *pui32Strength, uint32 *pui32PinType);


/******************************************************************************
* \Syntax          : void 	GPIOIntEnable (uint32 ui32Port, uint8 pin)
* \Description     : Enables the specified GPIO interrupts.
*******************************************************************************/
 void 	GPIOIntEnable (uint32 ui32Port, uint8 pin);


/******************************************************************************
* \Syntax          : void 	GPIOIntDisable (uint32 ui32Port, uint8 pin)
* \Description     : Disables the specified GPIO interrupts.
*******************************************************************************/
 void 	GPIOIntDisable (uint32 ui32Port, uint8 pin);


/******************************************************************************
* \Syntax          : uint32 	GPIOIntStatus (uint32 ui32Port, boolean bMasked)
* \Description     : Gets interrupt status for the specified GPIO port.
*******************************************************************************/
 uint32 	GPIOIntStatus (uint32 ui32Port, boolean bMasked);


/******************************************************************************
* \Syntax          : void 	GPIOIntClear (uint32 ui32Port, uint32 ui32IntFlags)
* \Description     : Clears the specified interrupt sources.
*******************************************************************************/ 
 void 	GPIOIntClear (uint32 ui32Port, uint32 ui32IntFlags);


/******************************************************************************
* \Syntax          : void 	GPIOIntRegister (uint32 ui32Port, void(*pfnIntHandler)(void))
* \Description     : Registers an interrupt handler for a GPIO port.
*******************************************************************************/
 void 	GPIOIntRegister (uint32 ui32Port, void(*pfnIntHandler)(void));


/******************************************************************************
* \Syntax          : void 	GPIOIntUnregister (uint32 ui32Port)
* \Description     : Removes an interrupt handler for a GPIO port.
*******************************************************************************/
 void 	GPIOIntUnregister (uint32 ui32Port);


/******************************************************************************
* \Syntax          : void 	GPIOIntRegisterPin (uint32 ui32Port, uint32 ui32Pin, void(*pfnIntHandler)(void))
* \Description     : Registers an interrupt handler for an individual pin of a GPIO port.
*******************************************************************************/
 void 	GPIOIntRegisterPin (uint32 ui32Port, uint32 ui32Pin, void(*pfnIntHandler)(void));


/******************************************************************************
* \Syntax          : void 	GPIOIntUnRegisterPin (uint32 ui32Port, uint32 ui32Pin)
* \Description     : Removes an interrupt handler for an individual pin of a GPIO port.
*******************************************************************************/
 void 	GPIOIntUnregisterPin (uint32 ui32Port, uint32 ui32Pin);


/******************************************************************************
* \Syntax          :  uint32 	GPIOPinRead (uint32 ui32Port, uint8 ui8Pins)
* \Description     :  Reads the values present of the specified pin(s).
*******************************************************************************/
 uint32 	GPIOPinRead (uint32 ui32Port, uint8 ui8Pins);


/******************************************************************************
* \Syntax          : void 	GPIOPinWrite (uint32 ui32Port, uint8 ui8Pins, uint8 ui8Val)
* \Description     : Writes a value to the specified pin(s).
*******************************************************************************/
 void 	GPIOPinWrite (uint32 ui32Port, uint8 ui8Pins, uint8 ui8Val);
 
#ifdef FUNCTIONS_TODO_ADDED_IN_GPIO_DRIVER
void 	 GPIOPinTypeADC             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeCAN             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeComparator      (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeComparatorOutput(uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeDIVSCLK         (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeEPI             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeEthernetLED     (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeEthernetMII     (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeGPIOInput       (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeGPIOOutput      (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeGPIOOutputOD    (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeHibernateRTCCLK (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeI2C             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeI2CSCL          (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeLCD             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeOneWire         (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypePWM             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeQEI             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeSSI             (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeTimer           (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeTrace           (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeUART            (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeUSBAnalog       (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeUSBDigital      (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeWakeHigh        (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOPinTypeWakeLow         (uint32 ui32Port, uint8 ui8Pins);
uint32 GPIOPinWakeStatus          (uint32 ui32Port);
void 	 GPIOPinConfigure           (uint32 ui32PinConfig);
void 	 GPIODMATriggerEnable       (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIODMATriggerDisable      (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOADCTriggerEnable       (uint32 ui32Port, uint8 ui8Pins);
void 	 GPIOADCTriggerDisable      (uint32 ui32Port, uint8 ui8Pins);
#endif  /*FUNCTIONS_TODO_ADDED_IN_GPIO_DRIVER*/
#endif  /* GPIO */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
