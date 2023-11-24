/*=================================================================================*/
/*  File        : TIMER1_interface.h                                               */
/*  Description : This Header file includes TIMER1_interface for STM32f103C8T6     */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                 	     		Advanced Timers                               *
*******************************************************************************/
#define TIMER_u8_1								1

/*******************************************************************************
*                 	     		Counting Direction	                           *
*******************************************************************************/
#define TIMER1_u8_COUNT_UP					0
#define TIMER1_u8_COUNT_DOWN				1

/*******************************************************************************
*                 	     		Pwm Channels		                           *
*******************************************************************************/
#define TIMER1_u8_PWM_CHANNEL1					0
#define TIMER1_u8_PWM_CHANNEL2					1
#define TIMER1_u8_PWM_CHANNEL3					2
#define TIMER1_u8_PWM_CHANNEL4					3

/*******************************************************************************
*                    		  Functions Prototypes                             *
*******************************************************************************/

/*******************************************************************************
* Function Name:		TIMER1_u8Init
* Description:			Function to initialize timer1
* Parameters (in):    	Timer direction (up or down) and the prescaler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 TIMER1_u8Init(u8 Copy_u8Direction , u16 Copy_u16Prescaler);

/*******************************************************************************
* Function Name:		TIMER1_u8SetBusyWait
* Description:			Function to create delay with the timer 1
* Parameters (in):    	Number of ticks and the repetition number
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 TIMER1_u8SetBusyWait(u16 Copy_u32NumOfTicks , u8 Copy_u8RepetitionNumebr);

/*******************************************************************************
* Function Name:		TIMER1_u8SetIntervalPeriodic
* Description:			Number of ticks, repetition number and pointer to function to act as ISR
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 TIMER1_u8SetIntervalPeriodic(u16 Copy_u32NumOfTicks , u8 Copy_u8RepetitionNumebr , void(*Copy_pf)(void));

/*******************************************************************************
* Function Name:		TIMER1_u8InitPwmChannel
* Description:			Function to initialize PWM channel
* Parameters (in):    	Channel Number
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 TIMER1_u8InitPwmChannel(u8 Copy_u8PwmChannel);

/*******************************************************************************
* Function Name:		TIMER1_u8SetPWM
* Description:			Function to create PWM with the timer 1
* Parameters (in):    	Frequency , duty cycle and channel number
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 TIMER1_u8SetPWM(u8 Copy_u8PwmChannel , u8 Copy_u8PwmFrequency , f32 Copy_u8PwmDutyCycle);

/*******************************************************************************
* Function Name:		TIMER1_u8Stop
* Description:			Function to stop and disable the timer
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 TIMER1_u8Stop(void);

#endif /* TIMER1_INTERFACE_H_ */
