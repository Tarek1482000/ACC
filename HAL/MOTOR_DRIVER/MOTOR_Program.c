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
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPT/GPT_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "MOTOR_config.h"
#include "MOTOR_Interface.h"
#include "MOTOR_Private.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void Motors_Init(void)
{
	if(MOTOR1_TIMER == TIMER_u8_1)
	{
		TIMER1_u8InitPwmChannel(MOTOR1_TIMER_CC);
	}
	else
	{
		GPT_u8InitPwmChannel(MOTOR1_TIMER, MOTOR1_TIMER_CC);
	}

	if(MOTOR2_TIMER == TIMER_u8_1)
	{
		TIMER1_u8InitPwmChannel(MOTOR2_TIMER_CC);
	}
	else
	{
		GPT_u8InitPwmChannel(MOTOR2_TIMER, MOTOR2_TIMER_CC);
	}


	GPIO_u8SetPinMode(MOTOR1_PORT, MOTOR1_PWM_PIN, GPIO_u8_OUTPUT_AF_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_OUTPUT_GP_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_OUTPUT_GP_PP_50MHZ);

	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);

	GPIO_u8SetPinMode(MOTOR2_PORT, MOTOR2_PWM_PIN, GPIO_u8_OUTPUT_AF_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_OUTPUT_GP_PP_50MHZ);
	GPIO_u8SetPinMode(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_OUTPUT_GP_PP_50MHZ);

	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);

	Motors_Speed(0);
}



void MOTORS_Forward(u8 speed)
{
	Motor1_Forward();
	Motor2_Forward();
	Motors_Speed(speed);
}


void MOTORS_Back(u8 speed)
{
	Motor1_Back();
	Motor2_Back();
	Motors_Speed(speed);
}

void Motors_Speed(u8 speed)
{
	Motor1_Speed(speed);
	Motor2_Speed(speed);
}




void Motor1_Forward(void)
{
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);
}

void Motor2_Forward(void)
{
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_HIGH);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);
}

void Motor1_Back(void)
{
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_HIGH);
}

void Motor2_Back(void)
{
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_HIGH);
}

void Motor1_Stop(void)
{
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR1_PORT, MOTOR1_PIN1, GPIO_u8_LOW);
}

void Motor2_Stop(void)
{
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN0, GPIO_u8_LOW);
	GPIO_u8WritePinValue(MOTOR2_PORT, MOTOR2_PIN1, GPIO_u8_LOW);
}

void Motor1_Speed(u8 speed)
{
	if(speed <= 99)
		speed ++;
	if(MOTOR1_TIMER == TIMER_u8_1)
	{
		TIMER1_u8SetPWM(MOTOR1_TIMER_CC, 50, speed);
	}
	else
	{
		GPT_u8SetPWM(MOTOR1_TIMER, MOTOR1_TIMER_CC, 50, speed);
	}
}

void Motor2_Speed(u8 speed)
{
	if(MOTOR2_TIMER == TIMER_u8_1)
	{
		TIMER1_u8SetPWM(MOTOR1_TIMER_CC, 50, speed);
	}
	else
	{
		GPT_u8SetPWM(MOTOR2_TIMER, MOTOR2_TIMER_CC, 50, speed);
	}
}



