/*=================================================================================*/
/*  File        : RCC_Interface.h                                                  */
/*  Description : This Header file includes RCC_Interface for STM32f103C8T6        */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                        		AHB Peripherals                                *
*******************************************************************************/
#define	RCC_u8_DMA1					0
#define	RCC_u8_DMA2					1
#define	RCC_u8_SRAM					2
#define	RCC_u8_FLITF				4
#define	RCC_u8_CRC					6
#define	RCC_u8_FSMC					8

/*******************************************************************************
*                        		APB2 Peripherals                               *
*******************************************************************************/
#define	RCC_u8_AFIO					(0  +32)
#define	RCC_u8_GPIOA				(2  +32)
#define	RCC_u8_GPIOB				(3  +32)
#define	RCC_u8_GPIOC				(4  +32)
#define	RCC_u8_GPIOD				(5  +32)
#define	RCC_u8_GPIOE				(6  +32)
#define	RCC_u8_GPIOF				(7  +32)
#define	RCC_u8_GPIOG				(8  +32)
#define	RCC_u8_ADC1					(9  +32)
#define	RCC_u8_ADC2					(10 +32)
#define	RCC_u8_TIM1					(11 +32)
#define	RCC_u8_SPI1					(12 +32)
#define	RCC_u8_TIM8					(13 +32)
#define	RCC_u8_USART1				(14 +32)
#define	RCC_u8_ADC3					(15 +32)
#define	RCC_u8_TIM9					(19 +32)
#define	RCC_u8_TIM10				(20 +32)
#define	RCC_u8_TIM11				(21 +32)

/*******************************************************************************
*                        		APB1 Peripherals                               *
*******************************************************************************/
#define	RCC_u8_TIM2					(0  +64)
#define	RCC_u8_TIM3					(1  +64)
#define	RCC_u8_TIM4					(2  +64)
#define	RCC_u8_TIM5					(3  +64)
#define	RCC_u8_TIM6					(4  +64)
#define	RCC_u8_TIM7					(5  +64)
#define	RCC_u8_TIM12				(6  +64)
#define	RCC_u8_TIM13				(7  +64)
#define	RCC_u8_TIM14				(8  +64)
#define	RCC_u8_WWD					(11 +64)
#define	RCC_u8_SPI2					(14 +64)
#define	RCC_u8_SPI3					(15 +64)
#define	RCC_u8_USART2				(17 +64)
#define	RCC_u8_USART3				(18 +64)
#define	RCC_u8_USART4				(19 +64)
#define	RCC_u8_USART5				(20 +64)
#define	RCC_u8_I2C1					(21 +64)
#define	RCC_u8_I2C2					(22 +64)
#define	RCC_u8_USB					(23 +64)
#define	RCC_u8_CAN					(25 +64)
#define	RCC_u8_BKP					(27 +64)
#define	RCC_u8_PWR					(28 +64)
#define	RCC_u8_DAC					(29 +64)

/*******************************************************************************
*                        		Peripherals State                              *
*******************************************************************************/
#define RCC_u8_Disable		0
#define RCC_u8_Enable		1

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		RCC_u8InitSysClk
* Description:			Function to init the system clock source
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 RCC_u8InitSysClk	(void);

/*******************************************************************************
* Function Name:		RCC_u8EnablePeripheralClk
* Description:			Function to enable or disable clock for specific periphral
* Parameters (in):    	The required peripheral and its bus
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 RCC_u8EnableDisablPeripheralClk	(u8 Copy_u8PeripheralId ,u8 Copy_u8State);

#endif
