/*=================================================================================*/
/*  File        : SYSTICK_Program.c                                                */
/*  Description : This Program file includes SYSTICK program for STM32f103C8T6     */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"

#include "STK_interface.h"
#include "STK_private.h"

/*******************************************************************************
*                           Global Variables                                  *
*******************************************************************************/

/* to store the address of the function to be the ISR */
static void (*STK_Pf)(void) = NULL;
static u8 STK_u8ModeOfInterval; /* Variable to save the current mode of the STK */

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		STK_voidInit
********************************************************************************/
u8 STK_u8Init(u8 Copy_u8ClockSource)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/* Choose the Clock Source */
	if(Copy_u8ClockSource == STK_u8_AHB)
	{
		SET_BIT(STK->CTRL,2);
	}
	else if (Copy_u8ClockSource == STK_u8_AHB_8)
	{
		CLR_BIT(STK->CTRL,2);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/* Disable the timer */
	CLR_BIT(STK->CTRL,0);

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetBusyWait
********************************************************************************/
u8 STK_u8SetuSBusyWait(u32 Copy_u32Time_us)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u32LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u32LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}

	if(Local_u32LoadValue <= 0x00FFFFFFFF)
	{
		/* Close the exception request */
		CLR_BIT(STK->CTRL,1);
		/* Load the required delay */
		STK->LOAD = Local_u32LoadValue ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Start the change immediately by writing any value to VAL register */
		STK->VAL = 0;
		/* Wait until timer reach zero */
		while(GET_BIT(STK->CTRL,16) == 0);
		/* Disable Timer */
		CLR_BIT(STK->CTRL,0);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetmSBusyWait
********************************************************************************/
u8 STK_u8SetmSBusyWait(u32 Copy_u32Time_ms)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	for(u32 i = 0 ; i < Copy_u32Time_ms ; i++)
	{
		STK_u8SetuSBusyWait(1000);
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetIntervalSingle
********************************************************************************/
u8 STK_u8SetIntervalSingle(u32 Copy_u32Time_us, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u32LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u32LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}
	if((Local_u32LoadValue <= 0x00FFFFFF) && (Copy_pf != NULL))
	{
		/* Set Callback Function */
		STK_Pf = Copy_pf;
		/* Load the required delay */
		STK->LOAD = Local_u32LoadValue ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Set the mode = interval */
		STK_u8ModeOfInterval = STK_u8_SINGLE_INTERVAL;
		/* Enable the exception request */
		SET_BIT(STK->CTRL,1);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetIntervalPeriodic
********************************************************************************/
u8 STK_u8SetIntervalPeriodic(u32 Copy_u32Time_us, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u32 Local_u8LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u8LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u8LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}
	if((Local_u8LoadValue <= 0x00FFFFFF) && (Copy_pf != NULL))
	{
		/* Set Callback Function */
		STK_Pf = Copy_pf;
		/* Load the required delay */
		STK->LOAD = Local_u8LoadValue-1 ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Set the mode = interval */
		STK_u8ModeOfInterval = STK_u8_PERIODIC_INTERVAL;
		/* Enable the exception request */
		SET_BIT(STK->CTRL,1);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8Stop
********************************************************************************/
u8 STK_u8Stop(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	CLR_BIT(STK->CTRL,0);
	STK->LOAD = 0;
	STK->VAL  = 0;

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8GetElapsedTime
********************************************************************************/
u8 STK_u8GetElapsedTime      (u32 * Copy_pu32ElapsedTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pu32ElapsedTime != NULL)
	{
		*Copy_pu32ElapsedTime = (STK->LOAD - STK->VAL) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8GetRemainingTime
********************************************************************************/
u8 STK_u8GetRemainingTime    (u32 * Copy_pu32RemainingTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pu32RemainingTime != NULL)
	{
		*Copy_pu32RemainingTime = STK->VAL ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
*                       Interrupt Service Routines                            *
*******************************************************************************/
void SysTick_Handler(void)
{
	if(STK_u8ModeOfInterval == STK_u8_SINGLE_INTERVAL)
	{
		/* Disable and Stop The Timer */
		CLR_BIT(STK->CTRL,0);
		CLR_BIT(STK->CTRL,1);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	if(STK_Pf != NULL)
	{
		STK_Pf();
	}
	/* Clear The Interrupt Flag */
	CLR_BIT(STK->CTRL,16);
}
