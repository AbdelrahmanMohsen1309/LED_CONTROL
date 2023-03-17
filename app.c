/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "CONFIGURATIONS.h"
#include "Std_Types.h"
#include "Register_Map.h"
#include "LED.h"
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void handle_systick_driver_ISR(void);
void setON_OFF_Time(uint8 onTime, uint8 offTime);
extern const LED_Config LED1;
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
uint32 ONTIME  = 0;
uint32 OFFTIME = 0;
uint32 TICKS   = 0;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void handle_systick_driver_ISR(void)
* \Description     : This Function Counts Ticks to compare with ON Time and OFF
*                    Time and call LED_toggle function to swap the output
*******************************************************************************/
void handle_systick_driver_ISR(void){
	TICKS++;
	if(TICKS == ONTIME){
		LED_toggle(&LED1);
	}else if(TICKS == (ONTIME+OFFTIME)){
		TICKS = 0;
		LED_toggle(&LED1);
	}
}
/******************************************************************************
* \Syntax          : void setON_OFF_Time(uint8 onTime, uint8 offTime)
* \Description     : This Function sets the Value of ON Time and OFF Time
*******************************************************************************/
void setON_OFF_Time(uint8 onTime, uint8 offTime){
	ONTIME  = onTime;
	OFFTIME = offTime;
}

/* Used for Simulator -> Map ranges to be added 0x40000000, 0x400FFFFF*/
int main(void){
	
	LED_init(&LED1);                                             /*Initialize LED*/
	
	LED_turn_ON(&LED1);                                          /*Turn the LED ON*/
	
	setON_OFF_Time(Ton,Toff);																		 /*Set the ON Time & OFF Time*/
	
	SysTickIntRegister(handle_systick_driver_ISR);               /*Register function to the handler*/
	
	IntMasterEnable();																					 /*Enable the Global interrupt*/
	
	SysTickPeriodSet(Freq_to_sec);                               /*Set the Timer Load Register*/
	
	SysTickIntEnable();																					 /*ENABLE the Systick interrupt*/
	
	SysTickEnable();																					   /*Enable Systick Timer*/
	while(1){
	
	}
}
