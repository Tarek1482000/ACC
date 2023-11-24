/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
/*******************************************************************************
*                      Private Variables	                                   *
*******************************************************************************/
static GPIO_RegDef_t * GPIO_Astr[5] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		GPIO_u8SetPinMode
********************************************************************************/
u8 GPIO_u8SetPinMode	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinMode)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_PortId <= GPIO_u8_GPIOE)
	{
		u8 Local_PullUpDown_Flag = GET_BIT(Copy_PinMode,4); /* Equal one in case of pull up only */
		CLR_BIT(Copy_PinMode,4); /*Get the Mode back to its value if it was input pull up */

		if(Copy_PinId <= GPIO_u8_PIN7)
		{
			GPIO_Astr[Copy_PortId]->CRL &= (~((0b1111) << (Copy_PinId * 4)));
			GPIO_Astr[Copy_PortId]->CRL |= (Copy_PinMode << (Copy_PinId * 4));

			if((Copy_PinMode == GPIO_u8_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 0))
			{
				/* Then the mode was input pull down */
				/* Turn off the internal pull up resistor */
				CLR_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
			else if((Copy_PinMode == GPIO_u8_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 1))
			{
				/* Then the mode was input pull up */
				/* Turn on the internal pull up resistor */
				SET_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
		}
		else if(Copy_PinId <= GPIO_u8_PIN15)
		{
			Copy_PinId -= 8;
			GPIO_Astr[Copy_PortId]->CRH &= (~((0b1111) << (Copy_PinId * 4)));
			GPIO_Astr[Copy_PortId]->CRH |= (Copy_PinMode << (Copy_PinId * 4));

			if((Copy_PinMode == GPIO_u8_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 0))
			{
				/* Then the mode was input pull down */
				/* Turn off the internal pull up resistor */
				CLR_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
			else if((Copy_PinMode == GPIO_u8_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 1))
			{
				/* Then the mode was input pull up */
				/* Turn on the internal pull up resistor */
				SET_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		GPIO_u8SetPinMode
********************************************************************************/
u8 GPIO_u8WritePinValue	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_PortId <= GPIO_u8_GPIOE && Copy_PinId <= GPIO_u8_PIN15)
	{
		switch(Copy_u8PinValue)
		{
		case GPIO_u8_HIGH:
			GPIO_Astr[Copy_PortId]->BSRR = (1<<Copy_PinId);
			break;
		case GPIO_u8_LOW:
			GPIO_Astr[Copy_PortId]->BRR = (1<<Copy_PinId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		GPIO_u8SetPinMode
********************************************************************************/
u8 GPIO_u8GetPinValue	(u8 Copy_PortId, u8 Copy_PinId , u8 * Copy_Pu8RetunredPinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_PortId <= GPIO_u8_GPIOE && Copy_PinId <= GPIO_u8_PIN15)
	{
		*Copy_Pu8RetunredPinValue = GET_BIT(GPIO_Astr[Copy_PortId]->IDR,Copy_PinId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		GPIO_u8TogPinValue
********************************************************************************/
u8 GPIO_u8TogPinValue	(u8 Copy_PortId, u8 Copy_PinId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_PortId <= GPIO_u8_GPIOE && Copy_PinId <= GPIO_u8_PIN15)
	{
		TOG_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		GPIO_u8TogPinValue
********************************************************************************/
u8 GPIO_u8LockPort	(u8 Copy_PortId, u8 Copy_PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_PortId <= GPIO_u8_GPIOE && Copy_PortValue <= 0xFF)
	{
		GPIO_Astr[Copy_PortId]->LCKR = Copy_PortValue;

		/* use the sequence to apply the lock */
		SET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16); /* Write 1 */
		CLR_BIT(GPIO_Astr[Copy_PortId]->LCKR,16); /* Write 0 */
		SET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16); /* Write 1 */
		if(GET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16) == 0)  /* Read 0 */
		{
			if(GET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16) == 0)  /* Read 1 "Optional" */
			{
				/* Done Successfully */
			}
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK; /* Error in the sequence */
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
