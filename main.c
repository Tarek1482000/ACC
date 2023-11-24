/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This Program file  For Application                               */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 15/11/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


#include "HAL/SYSTEM/SYSTYM_Interface.h"
#include "HAL/RC_CAR/RC_Interface.h"
#include "HAL/ULTRASONIC/ULTRASONIC_Interface.h"
int main(void)
{
	u16 Ultrasonic_u16_Distance_value = 0;
	u8 Current_Speed = 0, min_speed_flag = 1;
	SYSTEM_Init();

	Ultrasonic_init();

	RC_Init();

	RC_Forward(Current_Speed);
	for(;;)
	{
		Ultrasonic_u16_Distance_value = Ultrasonic_readDistance_average();


		if (Ultrasonic_u16_Distance_value >= MAX_SPEED)
		{
			Ultrasonic_u16_Distance_value = MAX_SPEED;
			min_speed_flag  = 1;
		}

		if(Ultrasonic_u16_Distance_value <= MINIMUM_DISTANCE && Ultrasonic_u16_Distance_value > STOP_DISTANCE)
		{
			if(min_speed_flag)
			{
				RC_Speed(MAX_SPEED);
				STK_u8SetmSBusyWait(3);
				min_speed_flag = 0;
			}
			Current_Speed = START_SPEED;
		}
		else if(Ultrasonic_u16_Distance_value > MINIMUM_DISTANCE && Ultrasonic_u16_Distance_value <= SAVE_DISTANCE)
		{
			Current_Speed = MIN_SPEED;
			min_speed_flag  = 1;
		}
		else if (Ultrasonic_u16_Distance_value > SAVE_DISTANCE)
		{
			Current_Speed = Ultrasonic_u16_Distance_value ;
			min_speed_flag  = 1;
		}
		else if(Ultrasonic_u16_Distance_value <= STOP_DISTANCE)
		{
			Current_Speed = ZERO_SPEED;
			min_speed_flag  = 1;
		}
		RC_Speed(Current_Speed);
		STK_u8SetmSBusyWait(10);
	}

}
