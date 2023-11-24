/*=================================================================================*/
/*  File        : LED_Interface.h                                                  */
/*  Description : This Header file includes LED_Interface                          */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
typedef enum
{
	LA0,LA1,LA2,LA3,LA4,LA5,LA6,LA7,LA8,LA9,LA10,LA11,LA12,LA13,LA14,LA15,
	LB0,LB1,LB2,LB3,LB4,LB5,LB6,LB7,LB8,LB9,LB10,LB11,LB12,LB13,LB14,LB15,
	LC13=45,LC14,LC15
}LED_NUM;
/*******************************************************************************
* Function Name:		LED_init
********************************************************************************/
u8 LED_init(LED_NUM led);
/*******************************************************************************
* Function Name:		LED_ON
********************************************************************************/
u8 LED_ON(LED_NUM led);
/*******************************************************************************
* Function Name:		LED_OFF
********************************************************************************/
u8 LED_OFF(LED_NUM led);
/*******************************************************************************
* Function Name:		LED_TOG
********************************************************************************/
u8 LED_TOG(LED_NUM led);


#endif /* LED_INTERFACE_H_ */
