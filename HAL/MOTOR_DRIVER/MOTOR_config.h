/*=================================================================================*/
/*  File        : MOTOR_config                                                     */
/*  Description : This Header file for MOTOR_config                                */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_MOTOR_DRIVER_MOTOR_CONFIG_H_
#define HAL_MOTOR_DRIVER_MOTOR_CONFIG_H_


/* LEFT SIDE IN MY CAR*/
#define MOTOR1_TIMER           TIMER_u8_1
#define MOTOR1_TIMER_CC        TIMER1_u8_PWM_CHANNEL1
#define MOTOR1_PORT            GPIO_u8_GPIOA
#define MOTOR1_PWM_PIN         GPIO_u8_PIN8
#define MOTOR1_PIN0            GPIO_u8_PIN9
#define MOTOR1_PIN1            GPIO_u8_PIN10

/* RIGHT SIDE IN MY CAR*/
#define MOTOR2_TIMER           TIMER_u8_2
#define MOTOR2_TIMER_CC        GPT_u8_PWM_CHANNEL2
#define MOTOR2_PORT            GPIO_u8_GPIOA
#define MOTOR2_PWM_PIN         GPIO_u8_PIN1
#define MOTOR2_PIN0            GPIO_u8_PIN4
#define MOTOR2_PIN1            GPIO_u8_PIN5

#endif /* HAL_MOTOR_DRIVER_MOTOR_CONFIG_H_ */
