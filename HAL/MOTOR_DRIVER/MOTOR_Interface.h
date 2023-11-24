/*=================================================================================*/
/*  File        : MOTOR_INTERFACE                                                  */
/*  Description : This Header file for MOTOR_INTERFACE                             */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_MOTOR_DRIVER_MOTOR_INTERFACE_H_
#define HAL_MOTOR_DRIVER_MOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/



void Motors_Init(void);
void MOTORS_Forward(u8 speed);
void MOTORS_Back(u8 speed);
void Motors_Speed(u8 speed);


void Motor1_Forward(void);
void Motor2_Forward(void);

void Motor1_Back(void);
void Motor2_Back(void);

void Motor1_Stop(void);
void Motor2_Stop(void);

void Motor1_Speed(u8 speed);
void Motor2_Speed(u8 speed);


#endif /* HAL_MOTOR_DRIVER_MOTOR_INTERFACE_H_ */
