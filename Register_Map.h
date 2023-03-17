/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Register_Map.h
 *       Module:  Memory Mapping
 *
 *  Description:  Header file for Hardware memory mapping registers    
 *  
 *********************************************************************************************************************/
#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Common_Macros.h"
#include "CONFIGURATIONS.h"
#include "Interrupt.h"
#include "GPIO.h"
#include "SystickTimer.h"

/**********************************************************************************************************************
 *  Memory Mapping
 *********************************************************************************************************************/
#define CORE_BASE_ADD                                (0xE000E000)
	
/*-----------------------------------System Timer (SysTick) Registers------------------------------------------------*/
#define STCTRL                                       *((volatile uint32*)(CORE_BASE_ADD+0x0010))  
#define STRELOAD                                     *((volatile uint32*)(CORE_BASE_ADD+0x0014))  
#define STCURRENT                                    *((volatile uint32*)(CORE_BASE_ADD+0x0018))
/*-------------------------Nested Vectored Interrupt Controller (NVIC) Registers-------------------------------------*/
#define EN0                                          *((volatile uint32*)(CORE_BASE_ADD+0x100))
#define EN1                                          *((volatile uint32*)(CORE_BASE_ADD+0x104))
#define EN2                                          *((volatile uint32*)(CORE_BASE_ADD+0x108))
#define EN3                                          *((volatile uint32*)(CORE_BASE_ADD+0x10C))
#define EN4                                          *((volatile uint32*)(CORE_BASE_ADD+0x110))
	
#define DIS0                                         *((volatile uint32*)(CORE_BASE_ADD+0x180))
#define DIS1                                         *((volatile uint32*)(CORE_BASE_ADD+0x184))
#define DIS2                                         *((volatile uint32*)(CORE_BASE_ADD+0x188))
#define DIS3                                         *((volatile uint32*)(CORE_BASE_ADD+0x18C))
#define DIS4                                         *((volatile uint32*)(CORE_BASE_ADD+0x190))

#define PEND0                                        *((volatile uint32*)(CORE_BASE_ADD+0x200))
#define PEND1                                        *((volatile uint32*)(CORE_BASE_ADD+0x204))
#define PEND2                                        *((volatile uint32*)(CORE_BASE_ADD+0x208))
#define PEND3                                        *((volatile uint32*)(CORE_BASE_ADD+0x20C))
#define PEND4                                        *((volatile uint32*)(CORE_BASE_ADD+0x210))
	
#define UNPEND0                                      *((volatile uint32*)(CORE_BASE_ADD+0x280))
#define UNPEND1                                      *((volatile uint32*)(CORE_BASE_ADD+0x284))
#define UNPEND2                                      *((volatile uint32*)(CORE_BASE_ADD+0x288))
#define UNPEND3                                      *((volatile uint32*)(CORE_BASE_ADD+0x28C))
#define UNPEND4                                      *((volatile uint32*)(CORE_BASE_ADD+0x290))
	
#define ACTIVE0                                      *((volatile uint32*)(CORE_BASE_ADD+0x300))
#define ACTIVE1                                      *((volatile uint32*)(CORE_BASE_ADD+0x304))
#define ACTIVE2                                      *((volatile uint32*)(CORE_BASE_ADD+0x308))
#define ACTIVE3                                      *((volatile uint32*)(CORE_BASE_ADD+0x30C))
#define ACTIVE4                                      *((volatile uint32*)(CORE_BASE_ADD+0x310))
	
#define PRI0                                         *((volatile uint32*)(CORE_BASE_ADD+0x400))
#define PRI1                                         *((volatile uint32*)(CORE_BASE_ADD+0x404))
#define PRI2                                         *((volatile uint32*)(CORE_BASE_ADD+0x408))
#define PRI3                                         *((volatile uint32*)(CORE_BASE_ADD+0x40C))
#define PRI4                                         *((volatile uint32*)(CORE_BASE_ADD+0x410))
#define PRI5                                         *((volatile uint32*)(CORE_BASE_ADD+0x414))
#define PRI6                                         *((volatile uint32*)(CORE_BASE_ADD+0x418))
#define PRI7                                         *((volatile uint32*)(CORE_BASE_ADD+0x41C))
#define PRI8                                         *((volatile uint32*)(CORE_BASE_ADD+0x420))
#define PRI9                                         *((volatile uint32*)(CORE_BASE_ADD+0x424))
#define PRI10                                        *((volatile uint32*)(CORE_BASE_ADD+0x428))
#define PRI11                                        *((volatile uint32*)(CORE_BASE_ADD+0x42C))
#define PRI12                                        *((volatile uint32*)(CORE_BASE_ADD+0x430))
#define PRI13                                        *((volatile uint32*)(CORE_BASE_ADD+0x434))
#define PRI14                                        *((volatile uint32*)(CORE_BASE_ADD+0x438))
#define PRI15                                        *((volatile uint32*)(CORE_BASE_ADD+0x43C))
#define PRI16                                        *((volatile uint32*)(CORE_BASE_ADD+0x440))
#define PRI17                                        *((volatile uint32*)(CORE_BASE_ADD+0x444))
#define PRI18                                        *((volatile uint32*)(CORE_BASE_ADD+0x448))
#define PRI19                                        *((volatile uint32*)(CORE_BASE_ADD+0x44C))
#define PRI20                                        *((volatile uint32*)(CORE_BASE_ADD+0x450))
#define PRI21                                        *((volatile uint32*)(CORE_BASE_ADD+0x454))
#define PRI22                                        *((volatile uint32*)(CORE_BASE_ADD+0x458))
#define PRI23                                        *((volatile uint32*)(CORE_BASE_ADD+0x45C))
#define PRI24                                        *((volatile uint32*)(CORE_BASE_ADD+0x460))
#define PRI25                                        *((volatile uint32*)(CORE_BASE_ADD+0x464))
#define PRI26                                        *((volatile uint32*)(CORE_BASE_ADD+0x468))
#define PRI27                                        *((volatile uint32*)(CORE_BASE_ADD+0x46C))
#define PRI28                                        *((volatile uint32*)(CORE_BASE_ADD+0x470))
#define PRI29                                        *((volatile uint32*)(CORE_BASE_ADD+0x474))
#define PRI30                                        *((volatile uint32*)(CORE_BASE_ADD+0x478))
#define PRI31                                        *((volatile uint32*)(CORE_BASE_ADD+0x47C))
#define PRI32                                        *((volatile uint32*)(CORE_BASE_ADD+0x480))
#define PRI33                                        *((volatile uint32*)(CORE_BASE_ADD+0x484))
#define PRI34                                        *((volatile uint32*)(CORE_BASE_ADD+0x488))
#define SWTRIG                                       *((volatile uint32*)(CORE_BASE_ADD+0xF00))

/*------------------------------System Control Block (SCB) Registers-------------------------------------------------*/
#define ACTLR                                        *((volatile uint32*)(CORE_BASE_ADD+0x008))
#define CPUID                                        *((volatile uint32*)(CORE_BASE_ADD+0xD00))
#define INTCTRL                                      *((volatile uint32*)(CORE_BASE_ADD+0xD04))
#define VTABLE                                       *((volatile uint32*)(CORE_BASE_ADD+0xD08))
#define APINT                                        *((volatile uint32*)(CORE_BASE_ADD+0xD0C))
#define SYSCTRL                                      *((volatile uint32*)(CORE_BASE_ADD+0xD10))
#define CFGCTRL                                      *((volatile uint32*)(CORE_BASE_ADD+0xD14))
#define SYSPRI1                                      *((volatile uint32*)(CORE_BASE_ADD+0xD18))
#define SYSPRI2                                      *((volatile uint32*)(CORE_BASE_ADD+0xD1C))
#define SYSPRI3                                      *((volatile uint32*)(CORE_BASE_ADD+0xD20))
#define SYSHNDCTRL                                   *((volatile uint32*)(CORE_BASE_ADD+0xD24))
#define FAULTSTAT                                    *((volatile uint32*)(CORE_BASE_ADD+0xD28))
#define HFAULTSTAT                                   *((volatile uint32*)(CORE_BASE_ADD+0xD2C))
#define MMADDR                                       *((volatile uint32*)(CORE_BASE_ADD+0xD34))
#define FAULTADDR                                    *((volatile uint32*)(CORE_BASE_ADD+0xD38))

/*The following are defines for the bit fields in the NVIC_ST_CTRL register.                    */
#define NVIC_ST_CTRL_COUNT                           0x00010000  /* Count flag                  */
#define NVIC_ST_CTRL_CLK_SRC                         0x00000004  /* Clock Source                */
#define NVIC_ST_CTRL_INTEN                           0x00000002  /* Interrupt enable            */
#define NVIC_ST_CTRL_ENABLE                          0x00000001  /* Counter mode                */

/*The following are defines for the bit fields in the NVIC_APINT register.                      */
#define NVIC_APINT_VECTKEY_M                         0xFFFF0000  /* Vector key mask             */
#define NVIC_APINT_VECTKEY                           0x05FA0000  /* Vector key                  */
#define NVIC_APINT_ENDIANESS                         0x00008000  /* Data endianess              */
#define NVIC_APINT_PRIGROUP_M                        0x00000700  /* Priority group              */
#define NVIC_APINT_PRIGROUP_0_8                      0x00000700  /* Priority group 0.8 split    */
#define NVIC_APINT_PRIGROUP_1_7                      0x00000600  /* Priority group 1.7 split    */
#define NVIC_APINT_PRIGROUP_2_6                      0x00000500  /* Priority group 2.6 split    */
#define NVIC_APINT_PRIGROUP_3_5                      0x00000400  /* Priority group 3.5 split    */
#define NVIC_APINT_PRIGROUP_4_4                      0x00000300  /* Priority group 4.4 split    */
#define NVIC_APINT_PRIGROUP_5_3                      0x00000200  /* Priority group 5.3 split    */
#define NVIC_APINT_PRIGROUP_6_2                      0x00000100  /* Priority group 6.2 split    */
#define NVIC_APINT_SYSRESETREQ                       0x00000004  /* System reset request        */
#define NVIC_APINT_VECT_CLR_ACT                      0x00000002  /* Clear active NMI/fault info */
#define NVIC_APINT_VECT_RESET                        0x00000001  /* System reset                */
#define NVIC_APINT_PRIGROUP_7_1                      0x00000000  /* Priority group 7.1 split    */


/*The following are defines for the bit fields in the NVIC_SYS_HND_CTRL register.               */
#define NVIC_SYS_HND_CTRL_USAGE                      0x00040000  /* Usage fault enable          */
#define NVIC_SYS_HND_CTRL_BUS                        0x00020000  /* Bus fault enable            */
#define NVIC_SYS_HND_CTRL_MEM                        0x00010000  /* Mem manage fault enable     */
#define NVIC_SYS_HND_CTRL_SVC                        0x00008000  /* SVCall is pended            */
#define NVIC_SYS_HND_CTRL_BUSP                       0x00004000  /* Bus fault is pended         */
#define NVIC_SYS_HND_CTRL_TICK                       0x00000800  /* Sys tick is active          */
#define NVIC_SYS_HND_CTRL_PNDSV                      0x00000400  /* PendSV is active            */
#define NVIC_SYS_HND_CTRL_MON                        0x00000100  /* Monitor is active           */
#define NVIC_SYS_HND_CTRL_SVCA                       0x00000080  /* SVCall is active            */
#define NVIC_SYS_HND_CTRL_USGA                       0x00000008  /* Usage fault is active       */
#define NVIC_SYS_HND_CTRL_BUSA                       0x00000002  /* Bus fault is active         */
#define NVIC_SYS_HND_CTRL_MEMA                       0x00000001  /* Mem manage is active        */


/*-------------------------------------------Exception Types-------------------------------------------*/
#define NMI_EXCEPTION             2
#define HARD_FAULT_EXCEPTION      3
#define MPU_EXCEPTION             4
#define BUS_FAULT_EXCEPTION       5
#define USAGE_FAULT_EXCEPTION     6
#define SVCALL_EXCEPTION         11
#define DEBUG_EXCEPTION          12
#define PENDSV_EXCEPTION         14
#define SYSTICK_EXCEPTION        15
/*-------------------------------------------Interrupt 0-31-------------------------------------------*/
#define INT_GPIOA             0
#define INT_GPIOB             1
#define INT_GPIOC             2
#define INT_GPIOD             3
#define INT_GPIOE             4
#define INT_UART0             5
#define INT_UART1             6
#define INT_SSI0              7
#define INT_I2C0              8
#define INT_PWM0_FAULT        9
#define INT_PMW0_Generator0  10
#define INT_PMW0_Generator1  11
#define INT_PMW0_Generator2  12
#define INT_QEI0             13
#define INT_ADC0_Sequence0   14
#define INT_ADC0_Sequence1   15
#define INT_ADC0_Sequence2   16
#define INT_ADC0_Sequence3   17
#define INT_WATCHDOG         18
#define INT_16_32_Timer0A    19
#define INT_16_32_Timer0B    20
#define INT_16_32_Timer1A    21
#define INT_16_32_Timer1B    22
#define INT_16_32_Timer2A    23
#define INT_16_32_Timer2B    24
#define INT_Comparator0      25
#define INT_Comparator1      26
#define INT_SysControl       28
#define INT_FLASH            29
#define INT_GPIOF            30
/*      RESERVED             31*/
/*-------------------------------------------Interrupt 32-63-------------------------------------------*/
/*      RESERVED             32*/
#define INT_UART2            33
#define INT_SSI1             34
#define INT_16_32_TIMER3A    35
#define INT_16_32_TIMER3B    36
#define INT_I2C1             37
#define INT_QEI1             38
#define INT_CAN0             39
#define INT_CAN1             40
#define INT_HIBERNATE        43
#define INT_USB              44
#define INT_PMW0_Generator3  45
#define INT_UDMA             46
#define INT_UDMAERR          47
#define INT_ADC1_Sequence0   48
#define INT_ADC1_Sequence1   49
#define INT_ADC1_Sequence2   50
#define INT_ADC1_Sequence3   51
#define INT_SSI2             57
#define INT_SSI3             58
#define INT_UART3            59
#define INT_UART4            60
#define INT_UART5            61
#define INT_UART6            62
#define INT_UART7            63
/*-------------------------------------------Interrupt 64-95-------------------------------------------*/
#define INT_I2C2             68
#define INT_I2C3             69
#define INT_16_32_TIMER4A    70
#define INT_16_32_TIMER4B    71
#define INT_16_32_TIMER5A    92
#define INT_16_32_TIMER5B    93
#define INT_32_64_TIMER0A    94
#define INT_32_64_TIMER0B    95
/*-------------------------------------------Interrupt 96-127-------------------------------------------*/
#define INT_32_64_TIMER1A    96
#define INT_32_64_TIMER1B    97
#define INT_32_64_TIMER2A    98
#define INT_32_64_TIMER2B    99
#define INT_32_64_TIMER3A    100
#define INT_32_64_TIMER3B    101
#define INT_32_64_TIMER4A    102
#define INT_32_64_TIMER4B    103
#define INT_32_64_TIMER5A    104
#define INT_32_64_TIMER5B    105
#define INT_SYSEXC           106
/*-------------------------------------------Interrupt 128-138-------------------------------------------*/
#define INT_PMW1_Generator0  134
#define INT_PMW1_Generator1  135
#define INT_PMW1_Generator2  136
#define INT_PMW1_Generator3  137
#define INT_PWM1_FAULT       138


#define 	NUM_INTERRUPTS     129
#define 	NUM_PRIORITY         8
#define 	NUM_PRIORITY_BITS    3


/*-------------------------------------------GPIO REGISTERS-----------------------------------------------*/
#ifdef GPIO_APB
#define GPIO_OFFSET(x) ( (x<4) ? ((0x40004000)+((x)*0x1000)) : ((0x40024000)+((x-4)*0x1000)))
/*
 GPIO Port A (APB): 0x4000.4000
 GPIO Port B (APB): 0x4000.5000
 GPIO Port C (APB): 0x4000.6000
 GPIO Port D (APB): 0x4000.7000
 GPIO Port E (APB): 0x4002.4000
 GPIO Port F (APB): 0x4002.5000
*/
#elif defined GPIO_AHP
#define GPIO_OFFSET(x) ( (0x40058000) + ((x)*0x1000) )
/*
 GPIO Port A (AHB): 0x4005.8000
 GPIO Port B (AHB): 0x4005.9000
 GPIO Port C (AHB): 0x4005.A000
 GPIO Port D (AHB): 0x4005.B000
 GPIO Port E (AHB): 0x4005.C000
 GPIO Port F (AHB): 0x4005.D000
*/

#else 
#error "Please choose a BUS for GPIOs"
#define GPIO_OFFSET 0x40004000
#endif

#define GPIO_DATA_MASK                            (0x3FC)     /** This Mask Used To Unlock DATA reg */
#define GPIO_DATA(x)                              *((volatile uint32*)(GPIO_OFFSET(x)+0x3FC))
#define GPIO_DIR(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x400))
#define GPIO_IS(x)                                *((volatile uint32*)(GPIO_OFFSET(x)+0x404))
#define GPIO_IBE(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x408))
#define GPIO_IEV(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x40C))
#define GPIO_IM(x)                                *((volatile uint32*)(GPIO_OFFSET(x)+0x410))
#define GPIO_RIS(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x414))
#define GPIO_MIS(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x418))
#define GPIO_ICR(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x41C))
#define GPIO_AFSEL(x)                             *((volatile uint32*)(GPIO_OFFSET(x)+0x420))
#define GPIO_DR2R(x)                              *((volatile uint32*)(GPIO_OFFSET(x)+0x500))
#define GPIO_DR4R(x)                              *((volatile uint32*)(GPIO_OFFSET(x)+0x504))
#define GPIO_DR8R(x)                              *((volatile uint32*)(GPIO_OFFSET(x)+0x508))
#define GPIO_ODR(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x50C))
#define GPIO_PUR(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x510))
#define GPIO_PDR(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x514))
#define GPIO_SLR(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x518))
#define GPIO_DEN(x)                               *((volatile uint32*)(GPIO_OFFSET(x)+0x51C))
#define GPIO_LOCK(x)                              *((volatile uint32*)(GPIO_OFFSET(x)+0x520))
#define GPIO_CR(x)                                *((volatile uint32*)(GPIO_OFFSET(x)+0x524))
#define GPIO_AMSEL(x)                             *((volatile uint32*)(GPIO_OFFSET(x)+0x528))
#define GPIO_PCTL(x)                              *((volatile uint32*)(GPIO_OFFSET(x)+0x52C))
#define GPIO_ADCCTL(x)                            *((volatile uint32*)(GPIO_OFFSET(x)+0x530))
#define GPIO_DMACTL(x)                            *((volatile uint32*)(GPIO_OFFSET(x)+0x534))
#define GPIO_PeriphID4(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFD0))
#define GPIO_PeriphID5(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFD4))
#define GPIO_PeriphID6(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFD8))
#define GPIO_PeriphID7(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFDC))
#define GPIO_PeriphID0(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFE0))
#define GPIO_PeriphID1(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFE4))
#define GPIO_PeriphID2(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFE8))
#define GPIO_PeriphID3(x)                         *((volatile uint32*)(GPIO_OFFSET(x)+0xFEC))
#define GPIO_PCellID0(x)                          *((volatile uint32*)(GPIO_OFFSET(x)+0xFF0))
#define GPIO_PCellID1(x)                          *((volatile uint32*)(GPIO_OFFSET(x)+0xFF4))
#define GPIO_PCellID2(x)                          *((volatile uint32*)(GPIO_OFFSET(x)+0xFF8))
#define GPIO_PCellID3(x)                          *((volatile uint32*)(GPIO_OFFSET(x)+0xFFC))

#endif  /* Register_Map */

/**********************************************************************************************************************
 *  END OF FILE: Register_Map.h
 *********************************************************************************************************************/
