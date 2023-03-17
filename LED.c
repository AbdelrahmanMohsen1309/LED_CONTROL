#include"LED.h"



LED_Config LED1 = {LED_PORT,LED_Pin,LED_Strength,LED_Type};

void LED_init(const LED_Config *ptr){
	GPIODirModeSet(ptr->ui32Port, ptr->ui8Pins, PORT_PIN_OUTPUT);
	GPIOPadConfigSet(ptr->ui32Port, ptr->ui8Pins, ptr->ui32Strength, ptr->ui32PinType);
}

void LED_turn_ON(const LED_Config *ptr){
	GPIOPinWrite(ptr->ui32Port, ptr->ui8Pins, PORT_PIN_HIGH);
}

void LED_turn_OFF(const LED_Config *ptr){
	GPIOPinWrite(ptr->ui32Port, ptr->ui8Pins,PORT_PIN_LOW);
}

void LED_toggle(const LED_Config *ptr){
	GPIOPinRead(ptr->ui32Port, ptr->ui8Pins)?
	GPIOPinWrite(ptr->ui32Port, ptr->ui8Pins,PORT_PIN_LOW):
	GPIOPinWrite(ptr->ui32Port, ptr->ui8Pins,PORT_PIN_HIGH);
}
