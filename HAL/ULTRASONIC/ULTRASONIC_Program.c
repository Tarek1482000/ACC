/*=================================================================================*/
/*  File        : ULTRASONIC_Program.c                                             */
/*  Description : This Program file includes ULTRASONIC program                    */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPT/GPT_interface.h"

#include "ULTRASONIC_config.h"
#include "ULTRASONIC_Interface.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Set ultrasonic setting
 * First initialize Icu
 * call back edge processing function
 * Set Triggre pin output
 */

void Ultrasonic_init(void)
{
	ICU_Types ICU_Values = {ULTRASONIC_TIMER,CC_INPUT_TI2,ULTRASONIC_TIMER_CHANNEL,RISING_EDGE};
	GPT_u8Init(ULTRASONIC_TIMER, GPT_u8_COUNT_UP, 15);
	TIMER_VoidICUInit(&ICU_Values);
	GPIO_u8SetPinMode(ULTRASONIC_ECHO_PORT_ID, ULTRASONIC_ECHO_PIN_ID, GPIO_u8_INPUT_FLOATING);

	STK_u8SetmSBusyWait(486);
	GPIO_u8SetPinMode(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, GPIO_u8_OUTPUT_GP_PP_50MHZ);
	STK_u8SetmSBusyWait(1);

}

/*
 * Send signal for 10us
 */

void Ultrasonic_Trigger(void)
{
	GPIO_u8WritePinValue(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, GPIO_u8_LOW);
	STK_u8SetuSBusyWait(5);
	GPIO_u8WritePinValue(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, GPIO_u8_HIGH);
	STK_u8SetuSBusyWait(10);
	GPIO_u8WritePinValue(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, GPIO_u8_LOW);
}


//******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Ultrasonic_readTimer(u8 Copy_u8TimerNumber,u16 *Distance1,u16 *Distance2,u8 channel)
{
	/*empty timer 2 counter*/
	Timer_VoidEmptyCounterRegister(Copy_u8TimerNumber);
	while(Timer_U8IcuGetCaptureFlag(Copy_u8TimerNumber,channel)==0)
	{

	}
	/*get value in counter in a variable*/
	*Distance1=TIMER_U16IcuGetCaptureValue(Copy_u8TimerNumber,channel);
	/*set the UG bit*/
	Timer_VoidTimeEventGenerationSet(Copy_u8TimerNumber);
	/*start the timer*/
	Timer_start(Copy_u8TimerNumber);
	/*make edge detection falling*/
	Timer_VoidIcuTriggerEdge(Copy_u8TimerNumber,FALLING_EDGE, channel);
	while(Timer_U8IcuGetCaptureFlag(Copy_u8TimerNumber,channel)==0)
	{

	}

	*Distance2=TIMER_U16IcuGetCaptureValue(Copy_u8TimerNumber,channel);

	Timer_VoidIcuTriggerEdge(Copy_u8TimerNumber,RISING_EDGE, channel);

	Timer_VoidClearFlag(Copy_u8TimerNumber);

	Timer_stop(Copy_u8TimerNumber);

	Timer_VoidEmptyCounterRegister(Copy_u8TimerNumber);
}


/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
static u16 Ultrasonic_GetDistance(u16 *Distance1,u16 *Distance2)
{
	u16 Total_time=*Distance2-*Distance1;
	u16 total_distance=0;
	//	total_distance= (0.0085* Total_time);
	total_distance = Total_time/31;
	return total_distance;
}

/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
u16 Ultrasonic_readDistance(void)
{
	u16 Distance1=0,Distance2=0,total_distance;
	/*trigger the Ultra-sonic sensor*/
	Ultrasonic_Trigger();
	Ultrasonic_readTimer(ULTRASONIC_TIMER,&Distance1,&Distance2,ULTRASONIC_TIMER_CHANNEL);
	total_distance=Ultrasonic_GetDistance(&Distance1,&Distance2);

	return total_distance ;
}


u16 Ultrasonic_readDistance_average(void)
{
	u16 total_distance = 0;
	u8 i = 0;
	for(i = 0;i<10;i++)
	{
		total_distance += Ultrasonic_readDistance();
		STK_u8SetmSBusyWait(5);
	}
	total_distance = total_distance / 10;


	return total_distance;
}



