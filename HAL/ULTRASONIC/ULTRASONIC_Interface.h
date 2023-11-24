/*=================================================================================*/
/*  File        : Ultrasonic_INTERFACE                                             */
/*  Description : This Header file for Ultrasonic_INTERFACE                        */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ECHO_EDGES                            2

#define SOUND_VELOCITY_IN_CM_AT_HALF_TIME     17000

#define Speed_Of_Sound 343

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


/*
 * Set ultrasonic setting
 * First initialize Icu
 * call back edge processing function
 * Set Triggre pin output
 */

void Ultrasonic_init(void);

/*
 * Send signal for 10us
 */

void Ultrasonic_Trigger(void);

/*
 * send 10us for ultrasonic trigger pin
 * wait until calculate edge  and calculate distance
 *return measured distance
 */

u16 Ultrasonic_readDistance(void);


u16 Ultrasonic_readDistance_average(void);




#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
