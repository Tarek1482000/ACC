/*=================================================================================*/
/*  File        : TIMER1_program.c                                                 */
/*  Description : This Program file includes TIMER program for STM32f103C8T6       */
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

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

/*******************************************************************************
*                           Global Variables                                  *
*******************************************************************************/

/* to store the address of the function to be the ISR */
static void (*TIMER1_Pf)(void) = NULL;

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		TIMER1_u8SetBusyWait
********************************************************************************/
u8 TIMER1_u8Init(u8 Copy_u8Direction , u16 Copy_u16Prescaler)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	TIMER1->CR1 = 0;
	SET_BIT(TIMER1->CR1,7); /* Auto reload pre-load enable */
	TIMER1->CR1 |= ((Copy_u8Direction & 0b1) << 4); /* Set the direction up or down */
	TIMER1->PSC = ( Copy_u16Prescaler - 1 ) ;

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		TIMER1_u8SetBusyWait
********************************************************************************/
u8 TIMER1_u8SetBusyWait(u16 Copy_u32NumOfTicks , u8 Copy_u8RepetitionNumebr)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	CLR_BIT(TIMER1->DIER,0); /* Disable the interrupt */
	TIMER1->ARR = (Copy_u32NumOfTicks & 0xFFFF);
	TIMER1->RCR = ((Copy_u8RepetitionNumebr - 1) & 0xFF);
	SET_BIT(TIMER1->CR1,0); /* Enable The timer */
	while(GET_BIT(TIMER1->SR,0) == 0); /* Wait until update occurs */
	CLR_BIT(TIMER1->SR,0); /* Clear the update flag */
	CLR_BIT(TIMER1->CR1,0); /* Disable The timer */

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		TIMER1_u8SetIntervalPeriodic
********************************************************************************/
u8 TIMER1_u8SetIntervalPeriodic(u16 Copy_u32NumOfTicks , u8 Copy_u8RepetitionNumebr , void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pf != NULL)
	{
		TIMER1_Pf = Copy_pf;
		TIMER1->ARR = (Copy_u32NumOfTicks & 0xFFFF);
		TIMER1->RCR = ((Copy_u8RepetitionNumebr - 1) & 0xFF);
		SET_BIT(TIMER1->DIER,0); /* Enable the interrupt */
		SET_BIT(TIMER1->CR1,0); /* Enable The timer */
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		TIMER1_u8InitPwmChannel
********************************************************************************/
u8 TIMER1_u8InitPwmChannel(u8 Copy_u8PwmChannel)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	switch(Copy_u8PwmChannel)
	{
	case TIMER1_u8_PWM_CHANNEL1:
		TIMER1->CCMR1 &= ~(0b11); /* Channel is output compare */
		SET_BIT(TIMER1->CCMR1,3); /* Output compare preload enable */
		TIMER1->CCMR1 |= (0b11 << 5); /* PWM mode 1 */
		CLR_BIT(TIMER1->CCMR1,4); /* PWM mode 1 */
		CLR_BIT(TIMER1->CCER,1); /* high output polarity */
		SET_BIT(TIMER1->CCER,0); /* Output enable */
		break;

	case TIMER1_u8_PWM_CHANNEL2:
		TIMER1->CCMR1 &= ~(0b11<<8);
		SET_BIT(TIMER1->CCMR1,11);
		TIMER1->CCMR1 |= (0b11 << 13);
		CLR_BIT(TIMER1->CCMR1,12);
		CLR_BIT(TIMER1->CCER,5);
		SET_BIT(TIMER1->CCER,4);
		break;

	case TIMER1_u8_PWM_CHANNEL3:
		TIMER1->CCMR2 &= ~(0b11);
		SET_BIT(TIMER1->CCMR2,3);
		TIMER1->CCMR2 |= (0b11 << 5);
		CLR_BIT(TIMER1->CCMR2,4);
		CLR_BIT(TIMER1->CCER,9);
		SET_BIT(TIMER1->CCER,8);
		break;

	case TIMER1_u8_PWM_CHANNEL4:
		TIMER1->CCMR2 &= ~(0b11<<8);
		SET_BIT(TIMER1->CCMR2,11);
		TIMER1->CCMR2 |= (0b11 << 13);
		CLR_BIT(TIMER1->CCMR2,12);
		CLR_BIT(TIMER1->CCER,13);
		SET_BIT(TIMER1->CCER,12);
		break;

	default:
		Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		TIMER1_u8SetPWM
********************************************************************************/
u8 TIMER1_u8SetPWM(u8 Copy_u8PwmChannel , u8 Copy_u8PwmFrequency , f32 Copy_u8PwmDutyCycle)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u16ReloadValue;
	u16 Local_u16CompareValue;
	if(Copy_u8PwmDutyCycle >= 0 && Copy_u8PwmDutyCycle <= 100)
	{
		switch(Copy_u8PwmChannel)
		{
		case TIMER1_u8_PWM_CHANNEL1:
			Local_u16ReloadValue = ((F_CPU/(TIMER1->PSC+1))/Copy_u8PwmFrequency);
			Local_u16CompareValue = ((Copy_u8PwmDutyCycle*Local_u16ReloadValue)/100) ;
			TIMER1->ARR = Local_u16ReloadValue ; /* Setup Frequency */
			TIMER1->CCR1 = Local_u16CompareValue; /* Setup Duty Cycle */

			SET_BIT(TIMER1->BDTR,15); /* Enable MOE */
			SET_BIT(TIMER1->CR1,0); /* Enable the timer */
			break;

		case TIMER1_u8_PWM_CHANNEL2:
			Local_u16ReloadValue = ((F_CPU/(TIMER1->PSC+1))/Copy_u8PwmFrequency);
			Local_u16CompareValue = ((Copy_u8PwmDutyCycle*Local_u16ReloadValue)/100) ;
			TIMER1->ARR = Local_u16ReloadValue ; /* Setup Frequency */
			TIMER1->CCR2 = Local_u16CompareValue; /* Setup Duty Cycle */

			SET_BIT(TIMER1->BDTR,15); /* Enable MOE */
			SET_BIT(TIMER1->CR1,0); /* Enable the timer */
			break;

		case TIMER1_u8_PWM_CHANNEL3:
			Local_u16ReloadValue = ((F_CPU/(TIMER1->PSC+1))/Copy_u8PwmFrequency);
			Local_u16CompareValue = ((Copy_u8PwmDutyCycle*Local_u16ReloadValue)/100) ;
			TIMER1->ARR = Local_u16ReloadValue ; /* Setup Frequency */
			TIMER1->CCR3 = Local_u16CompareValue; /* Setup Duty Cycle */

			SET_BIT(TIMER1->BDTR,15); /* Enable MOE */
			SET_BIT(TIMER1->CR1,0); /* Enable the timer */
			break;

		case TIMER1_u8_PWM_CHANNEL4:
			Local_u16ReloadValue = ((F_CPU/(TIMER1->PSC+1))/Copy_u8PwmFrequency);
			Local_u16CompareValue = ((Copy_u8PwmDutyCycle*Local_u16ReloadValue)/100) ;
			TIMER1->ARR = Local_u16ReloadValue ; /* Setup Frequency */
			TIMER1->CCR4 = Local_u16CompareValue; /* Setup Duty Cycle */

			SET_BIT(TIMER1->BDTR,15); /* Enable MOE */
			SET_BIT(TIMER1->CR1,0); /* Enable the timer */
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
			break;
		}

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		TIMER1_u8Stop
********************************************************************************/
u8 TIMER1_u8Stop(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	TIMER1->CR1 = 0;
	TIMER1->ARR = 0;
	TIMER1->RCR = 0;
	TIMER1->PSC = 0;
	CLR_BIT(TIMER1->DIER,0); /* Disable the interrupt */
	SET_BIT(TIMER1->EGR,0);

	return Local_u8ErrorState;
}


/*******************************************************************************
*                       Interrupt Service Routines                            *
*******************************************************************************/
void TIM1_UP_IRQHandler(void)
{
	if(TIMER1_Pf != NULL)
	{
		TIMER1_Pf();
	}
	CLR_BIT(TIMER1->SR,0); /* Clear the update flag */
}
