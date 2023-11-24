/*=================================================================================*/
/*  File        : RC_Program.c                                                     */
/*  Description : This Program file includes RC program                            */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


#include "../../HAL/MOTOR_DRIVER/MOTOR_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "RC_Config.h"
#include "RC_Interface.h"


void RC_Init(void)
{
	LED_init(RC_FRONT_LED);
	LED_init(RC_FRONT_RIGHT_LED);
	LED_init(RC_FRONT_LEFT_LED);

	LED_init(RC_BACK_RIGHT_LED);
	LED_init(RC_BACK_LEFT_LED);

	Motors_Init();

}

void RC_Speed(u8 speed)
{
	Motors_Speed(speed);
}


void RC_Forward(u8 speed)
{
	LED_OFF(RC_FRONT_RIGHT_LED);
	LED_OFF(RC_FRONT_LEFT_LED);
	LED_OFF(RC_BACK_RIGHT_LED);
	LED_OFF(RC_BACK_LEFT_LED);

	LED_ON(RC_FRONT_LED);
	MOTORS_Forward(speed);
}



void RC_Right(u8 speed)
{
	LED_OFF(RC_FRONT_LED);
	LED_OFF(RC_FRONT_LEFT_LED);
	LED_OFF(RC_BACK_RIGHT_LED);
	LED_OFF(RC_BACK_LEFT_LED);

	LED_ON(RC_FRONT_RIGHT_LED);

	RC_Speed(speed);
	Motor2_Stop();
	Motor1_Forward();
}

void RC_Left(u8 speed)
{
	LED_OFF(RC_FRONT_LED);
	LED_OFF(RC_FRONT_RIGHT_LED);
	LED_OFF(RC_BACK_RIGHT_LED);
	LED_OFF(RC_BACK_LEFT_LED);

	LED_ON(RC_FRONT_LEFT_LED);

	RC_Speed(speed);
	Motor1_Stop();
	Motor2_Forward();
}

void RC_Back(u8 speed)
{
	LED_OFF(RC_FRONT_LED);
	LED_OFF(RC_FRONT_RIGHT_LED);
	LED_OFF(RC_FRONT_LEFT_LED);

	LED_ON(RC_BACK_RIGHT_LED);
	LED_ON(RC_BACK_LEFT_LED);

	MOTORS_Back(speed);
}
void RC_Back_Right(u8 speed)
{
	LED_OFF(RC_FRONT_LED);
	LED_OFF(RC_FRONT_RIGHT_LED);
	LED_OFF(RC_FRONT_LEFT_LED);

	LED_OFF(RC_BACK_RIGHT_LED);

	LED_ON(RC_BACK_LEFT_LED);

	RC_Speed(speed);
	Motor2_Stop();
	Motor1_Back();
}
void RC_Back_Left(u8 speed)
{
	LED_OFF(RC_FRONT_LED);
	LED_OFF(RC_FRONT_RIGHT_LED);
	LED_OFF(RC_FRONT_LEFT_LED);

	LED_OFF(RC_BACK_LEFT_LED);

	LED_ON(RC_BACK_RIGHT_LED);

	RC_Speed(speed);
	Motor1_Stop();
	Motor2_Back();
}
void RC_Stop(void)
{
	LED_OFF(RC_FRONT_LED);
	LED_OFF(RC_FRONT_RIGHT_LED);
	LED_OFF(RC_FRONT_LEFT_LED);

	LED_ON(RC_BACK_RIGHT_LED);
	LED_ON(RC_BACK_LEFT_LED);

	RC_Speed(0);
	Motor1_Stop();
	Motor2_Stop();
}
