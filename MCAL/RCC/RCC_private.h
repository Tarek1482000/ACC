/*=================================================================================*/
/*  File        : RCC_Private.h                                                    */
/*  Description : This Header file includes RCC_Private for STM32f103C8T6          */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                        		Clock Source	                               *
*******************************************************************************/
#define RCC_u8_HSI	1
#define RCC_u8_HSE	2
#define RCC_u8_PLL	3

/*******************************************************************************
*                        		PLL Clock Source	                           *
*******************************************************************************/
#define RCC_u8_PLL_HSI_DIVIDED_BY_2			1
#define RCC_u8_PLL_HSE						2
#define RCC_u8_PLL_HSE_DIVIDED_BY_2			3

/*******************************************************************************
*                        		PLL Clock Multiplier	                       *
*******************************************************************************/
#define RCC_u8_PLL_MULTIPLY_BY_2 			0b0000
#define RCC_u8_PLL_MULTIPLY_BY_3 			0b0001
#define RCC_u8_PLL_MULTIPLY_BY_4 			0b0010
#define RCC_u8_PLL_MULTIPLY_BY_5 			0b0011
#define RCC_u8_PLL_MULTIPLY_BY_6 			0b0100
#define RCC_u8_PLL_MULTIPLY_BY_7 			0b0101
#define RCC_u8_PLL_MULTIPLY_BY_8 			0b0110
#define RCC_u8_PLL_MULTIPLY_BY_9 			0b0111
#define RCC_u8_PLL_MULTIPLY_BY_10			0b1000
#define RCC_u8_PLL_MULTIPLY_BY_11			0b1001
#define RCC_u8_PLL_MULTIPLY_BY_12			0b1010
#define RCC_u8_PLL_MULTIPLY_BY_13			0b1011
#define RCC_u8_PLL_MULTIPLY_BY_14			0b1100
#define RCC_u8_PLL_MULTIPLY_BY_15			0b1101
#define RCC_u8_PLL_MULTIPLY_BY_16			0b1110

/*******************************************************************************
*                        		HSE Clock Source	                           *
*******************************************************************************/
#define RCC_u8_HSE_NOT_BYPASS					1
#define RCC_u8_HSE_BYPASS						2

/*******************************************************************************
*                        		ADC Prescaler		                           *
*******************************************************************************/
#define RCC_u8_ADC_DIVIDED_BY_2						0b00
#define RCC_u8_ADC_DIVIDED_BY_4						0b01
#define RCC_u8_ADC_DIVIDED_BY_6						0b10
#define RCC_u8_ADC_DIVIDED_BY_8						0b11

/*******************************************************************************
*                        		APBx Prescaler		                           *
*******************************************************************************/
#define RCC_u8_APBx_DIVIDED_BY_1					0b000
#define RCC_u8_APBx_DIVIDED_BY_2					0b100
#define RCC_u8_APBx_DIVIDED_BY_4					0b101
#define RCC_u8_APBx_DIVIDED_BY_8					0b110
#define RCC_u8_APBx_DIVIDED_BY_16					0b111

/*******************************************************************************
*                        		AHB Prescaler		                           *
*******************************************************************************/
#define RCC_u8_AHB_DIVIDED_BY_1						0b0000
#define RCC_u8_AHB_DIVIDED_BY_2						0b1000
#define RCC_u8_AHB_DIVIDED_BY_4						0b1001
#define RCC_u8_AHB_DIVIDED_BY_8						0b1010
#define RCC_u8_AHB_DIVIDED_BY_16					0b1011
#define RCC_u8_AHB_DIVIDED_BY_64					0b1100
#define RCC_u8_AHB_DIVIDED_BY_128					0b1101
#define RCC_u8_AHB_DIVIDED_BY_256					0b1110
#define RCC_u8_AHB_DIVIDED_BY_512					0b1111

#endif
