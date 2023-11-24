/*=================================================================================*/
/*  File        : GPIO_Interface.h                                                 */
/*  Description : This Header file includes GPIO Interface for STM32f103C8T6       */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                        			PORT 	  	                               *
*******************************************************************************/
#define GPIO_u8_GPIOA						0
#define GPIO_u8_GPIOB						1
#define GPIO_u8_GPIOC						2
#define GPIO_u8_GPIOD						3
#define GPIO_u8_GPIOE						4

/*******************************************************************************
*                        			PIN 	  	                               *
*******************************************************************************/
#define GPIO_u8_PIN0						0
#define GPIO_u8_PIN1						1
#define GPIO_u8_PIN2						2
#define GPIO_u8_PIN3						3
#define GPIO_u8_PIN4						4
#define GPIO_u8_PIN5						5
#define GPIO_u8_PIN6						6
#define GPIO_u8_PIN7						7
#define GPIO_u8_PIN8						8
#define GPIO_u8_PIN9						9
#define GPIO_u8_PIN10						10
#define GPIO_u8_PIN11						11
#define GPIO_u8_PIN12						12
#define GPIO_u8_PIN13						13
#define GPIO_u8_PIN14						14
#define GPIO_u8_PIN15						15

/*******************************************************************************
*                        			INPUT MODES 	  	                       *
*******************************************************************************/
#define GPIO_u8_INPUT_ANALOG					0b0000
#define GPIO_u8_INPUT_FLOATING					0b0100
#define GPIO_u8_INPUT_PULL_DOWN					0b1000
#define GPIO_u8_INPUT_PULL_UP					0b11000 /* To know if it is pull up or down */

/*******************************************************************************
*                        			OUTPUT MODES 	  	                       *
*******************************************************************************/
#define GPIO_u8_OUTPUT_GP_PP_10MHZ				0b0001
#define GPIO_u8_OUTPUT_GP_OD_10MHZ				0b0101
#define GPIO_u8_OUTPUT_AF_PP_10MHZ				0b1001
#define GPIO_u8_OUTPUT_AF_OD_10MHZ				0b1101

#define GPIO_u8_OUTPUT_GP_PP_2MHZ				0b0010
#define GPIO_u8_OUTPUT_GP_OD_2MHZ				0b0110
#define GPIO_u8_OUTPUT_AF_PP_2MHZ				0b1010
#define GPIO_u8_OUTPUT_AF_OD_2MHZ				0b1110

#define GPIO_u8_OUTPUT_GP_PP_50MHZ				0b0011
#define GPIO_u8_OUTPUT_GP_OD_50MHZ				0b0111
#define GPIO_u8_OUTPUT_AF_PP_50MHZ				0b1011
#define GPIO_u8_OUTPUT_AF_OD_50MHZ				0b1111

/*******************************************************************************
*                        			OUTPUT VALUES 	  	                       *
*******************************************************************************/
#define GPIO_u8_HIGH                       1
#define GPIO_u8_LOW                        0

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		GPIO_u8SetPinMode
* Description:			Function to set the mode for the required pin mode
* Parameters (in):    	The required pin number ,port and mode
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 GPIO_u8SetPinMode	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinMode);

/*******************************************************************************
* Function Name:		GPIO_u8WritePinValue
* Description:			Function to write the required pin value
* Parameters (in):    	Required pin number and port
* 						Value to write in the required pin
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 GPIO_u8WritePinValue	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_u8PinValue);

/*******************************************************************************
* Function Name:		GPIO_u8SetPinMode
* Description:			Function to get the required pin value
* Parameters (in):    	Required pin number and port
* 						Pointer to variable to get the ping value in it
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 GPIO_u8GetPinValue	(u8 Copy_PortId, u8 Copy_PinId , u8 * Copy_Pu8RetunredPinValue);

/*******************************************************************************
* Function Name:		GPIO_u8TogPinValue
* Description:			Function to toggle the required pin value
* Parameters (in):    	Required pin number and port
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 GPIO_u8TogPinValue	(u8 Copy_PortId, u8 Copy_PinId);

/*******************************************************************************
* Function Name:		GPIO_u8LockPin
* Description:			Function to toggle the required pin value
* Parameters (in):    	Required pin number and port
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 GPIO_u8LockPort	(u8 Copy_PortId, u8 Copy_PortValue);

#endif
