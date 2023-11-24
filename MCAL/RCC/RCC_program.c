/*=================================================================================*/
/*  File        : RCC_Program.c                                                    */
/*  Description : This Program file includes RCC program for STM32f103C8T6         */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		RCC_u8InitSysClk
********************************************************************************/

u8 RCC_u8InitSysClk	(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32  Local_u32TimeOut = 0;

	RCC->CR = (RCC->CR &~ (0b11111<<3)) | (RCC_u8_HSI_TRIM<<3); /* Setting the TRIM value for HSI */
	#if (RCC_u8_CLK_SYS == RCC_u8_HSI)

		SET_BIT(RCC->CR,0); /* write one bit no0 HSION to enable it*/
		/* wait until HSI RDY flag = 1 or timeout occurs*/
		while( (GET_BIT(RCC->CR,1) == 0) && (Local_u32TimeOut < 100000)){Local_u32TimeOut++;}
		if(Local_u32TimeOut > 100000)
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		CLR_BIT(RCC->CFGR,0); /* Select HSI as clock source from SW registers */
		CLR_BIT(RCC->CFGR,1);

	#elif (RCC_u8_CLK_SYS == RCC_u8_HSE)
		#if (RCC_u8_HSE_TYPE == RCC_u8_HSE_BYPASS)
			SET_BIT(RCC->CR,18);
		#elif (RCC_u8_HSE_TYPE == RCC_u8_HSE_NOT_BYPASS)
			CLR_BIT(RCC->CR,18);
		#else
			#error"Wrong System Clock Choice"
		#endif
		SET_BIT(RCC->CR,16); /* write one bit no16 HSEON */

		/* wait until HSE RDY flag = 1  or timeout occurs */
		while(GET_BIT(RCC->CR,17) == 0 && (Local_u32TimeOut < 100000)){Local_u32TimeOut++;}
		if(Local_u32TimeOut > 100000)
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		SET_BIT(RCC->CFGR,0); /* select HSE as system clock in SW registers */
		CLR_BIT(RCC->CFGR,1);

	#elif (RCC_u8_CLK_SYS == RCC_u8_PLL)
		/* Starting of First Nested If */
		#if ((RCC_u8_PLL_MULTIPLIER >= RCC_u8_PLL_MULTIPLY_BY_2) && (RCC_u8_PLL_MULTIPLIER <= RCC_u8_PLL_MULTIPLY_BY_16))
			RCC->CFGR = (RCC->CFGR &~ (0b1111 << 18)) | (RCC_u8_PLL_MULTIPLIER << 18) ;
		#else
			#warning "Wrong Multiplication Factor"
		#endif
		/* End of First Nested If */

		/* Starting of First Nested If */
		#if (RCC_u8_PLL_SOURCE == RCC_u8_PLL_HSI_DIVIDED_BY_2)
			CLR_BIT(RCC->CFGR,16);
		#elif (RCC_u8_PLL_SOURCE == RCC_u8_PLL_HSE)
			SET_BIT(RCC->CR,16); /* Enable the HSE first */
			SET_BIT(RCC->CFGR,16);
			CLR_BIT(RCC->CFGR,17);
		#elif (RCC_u8_PLL_SOURCE == RCC_u8_PLL_HSE_DIVIDED_BY_2)
			SET_BIT(RCC->CR,16); /* Enable the HSE first */
			SET_BIT(RCC->CFGR,16);
			SET_BIT(RCC->CFGR,17);
		#else
			#error"Wrong System Clock Choice"
		#endif
		/* End of First Nested If */

		SET_BIT(RCC->CR,24); /* write one bit no24 PLLON */
		/* wait until PLL RDY flag = 1 */
		while(GET_BIT(RCC->CR,25) == 0 && (Local_u32TimeOut < 100000)){Local_u32TimeOut++;}
		if(Local_u32TimeOut > 100000)
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		SET_BIT(RCC->CFGR,1); /* select PLL as system clock in SW registers */
		CLR_BIT(RCC->CFGR,0);

	#else

		#error"Wrong System Clock Choice"

	#endif

	/* Setting the Prescaler */
	RCC->CFGR = (RCC->CFGR &~ (0b11<<14))  | (RCC_u8_ADC_PRESCALER<<14);  /* ADC */
	RCC->CFGR = (RCC->CFGR &~ (0b111<<11)) | (RCC_u8_APB2_PRESCALER<<11); /* APB2 */
	RCC->CFGR = (RCC->CFGR &~ (0b111<<8))  | (RCC_u8_APB1_PRESCALER<<8);  /* APB1 */
	RCC->CFGR = (RCC->CFGR &~ (0b1111<<4)) | (RCC_u8_AHB_PRESCALER<<4);   /* AHB */
	
	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		RCC_u8EnablePeripheralClk
********************************************************************************/

u8 RCC_u8EnableDisablPeripheralClk	(u8 Copy_u8PeripheralId ,u8 Copy_u8State)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PeripheralId < 32) /* from 0 to 31 AHB BUS */
	{
		switch(Copy_u8State)
		{
		case RCC_u8_Enable:
			SET_BIT(RCC->AHBENR,Copy_u8PeripheralId);
			break;
		case RCC_u8_Disable:
			CLR_BIT(RCC->AHBENR,Copy_u8PeripheralId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK; /* user entered wrong state */
		}
	}
	else if(Copy_u8PeripheralId < 64) /* from 32 to 63 APB2 BUS */
	{
		Copy_u8PeripheralId -= 32;
		switch(Copy_u8State)
		{
		case RCC_u8_Enable:
			SET_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
			break;
		case RCC_u8_Disable:
			CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK; /* user entered wrong state */
		}
	}
	else if(Copy_u8PeripheralId < 96) /* from 64 to 95 APB1 BUS */
	{
		Copy_u8PeripheralId -= 64;
		switch(Copy_u8State)
		{
		case RCC_u8_Enable:
			SET_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
			break;
		case RCC_u8_Disable:
			CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK; /* user entered wrong state */
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK; /* user entered wrong peripheral number */
	}
	return Local_u8ErrorState;
}
