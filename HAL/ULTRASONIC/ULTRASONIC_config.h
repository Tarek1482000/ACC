/*=================================================================================*/
/*  File        : Ultrasonic_config                                                */
/*  Description : This Header file for Ultrasonic_config                           */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_
#define HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_


#define ULTRASONIC_TRIGGER_PORT_ID           GPIO_u8_GPIOA
#define ULTRASONIC_TRIGGER_PIN_ID            GPIO_u8_PIN7

#define ULTRASONIC_ECHO_PORT_ID              GPIO_u8_GPIOB
#define ULTRASONIC_ECHO_PIN_ID               GPIO_u8_PIN0

#define ULTRASONIC_TIMER                     TIMER_u8_3
#define ULTRASONIC_TIMER_CHANNEL             CC3

#endif /* HAL_ULTRASONIC_ULTRASONIC_CONFIG_H_ */
