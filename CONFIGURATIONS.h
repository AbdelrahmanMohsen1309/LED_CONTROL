#include "Register_Map.h"
/**********************************************************************************************************************
 *  GPIO CONFIGURATIONS
 *********************************************************************************************************************/

/****************************************************
 * Options: 1- GPIO_APB                             *
 *          2- GPIO_AHP                             *
 ****************************************************/
#define GPIO_APB


/****************************************************
 * LED_PORT                                         *
 * Options: 1- GPIO_PORTA  									        *
 *          2- GPIO_PORTB										        *
 *          3- GPIO_PORTC										        *
 *          4- GPIO_PORTD										        *
 *          5- GPIO_PORTE										        *  
 *          6- GPIO_PORTF										        *
 ****************************************************/
#define LED_PORT     GPIO_PORTF


/****************************************************
 * LED_Pin                                          *
 * Options: 1- PIN0  		      							        *
 *          2- PIN1     										        *
 *          3- PIN2			      							        *
 *          4- PIN3		      								        *
 *          5- PIN4		      								        *  
 *          6- PIN5     										        *
 *          7- PIN6     										        *
 *          8- PIN7     					        					*
 ****************************************************/
#define LED_Pin      PIN1


/****************************************************
 * LED_Strength                                     *
 * Options: 1- PORT_PIN_CUR_2MA  						        *
 *          2- PORT_PIN_CUR_4MA							        *
 *          3- PORT_PIN_CUR_8MA							        *
 *          4- PORT_PIN_CUR_SLR							        *
 ****************************************************/
#define LED_Strength PORT_PIN_CUR_8MA


/****************************************************
 * LED_Type                                         *
 * Options: 1- PORT_PIN_ODR  		|OpenDrain Register *
 *          2- PORT_PIN_PUR			|Pullup	Resistor    *
 *          3- PORT_PIN_PDR			|PullDown	Resistor  *
 *          4- PORT_PIN_DEN			|Degital Enable     *
 *          4- PORT_PIN_AEN			|Analog Enable      *
 ****************************************************/
#define LED_Type     PORT_PIN_DEN

/****************************************************
 * Freq_to_sec                                      *
 * = CLK Oscillator in Hexadecimal (12MHz)          *
 * to generate 1 second                             *
 ****************************************************/
#define Freq_to_sec  (0x00B71B00)


/****************************************************
 * Please Specify on time and off time              *
 * to generate the PWM Signal                       *
 ****************************************************/
 #define Ton  5
 #define Toff 3
 
 

 
 