/******************************************************************************
*  File name:		stm32f103xx.h
*  Date:			Mar 5, 2023
*  Author:			Ahmed Tarek
*  Version:         1.0
*******************************************************************************/
#ifndef STM32F103xx_H
#define STM32F103xx_H

#include "STD_TYPES.h"
/*******************************************************************************
*                      				RCC                     		           *
*******************************************************************************/

#define RCC_u32_BASE_ADDRESS						0x40021000

typedef struct
{	
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;		
	volatile u32 CSR;				
}RCC_RegDef_t;

#define RCC						((RCC_RegDef_t *)RCC_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				GPIO                     		           *
*******************************************************************************/

#define GPIOA_u32_BASE_ADDRESS						0x40010800U
#define GPIOB_u32_BASE_ADDRESS						0x40010C00U
#define GPIOC_u32_BASE_ADDRESS						0x40011000U
#define GPIOD_u32_BASE_ADDRESS						0x40011400U
#define GPIOE_u32_BASE_ADDRESS						0x40011800U

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_RegDef_t;

#define GPIOA					((GPIO_RegDef_t *)GPIOA_u32_BASE_ADDRESS)
#define GPIOB					((GPIO_RegDef_t *)GPIOB_u32_BASE_ADDRESS)
#define GPIOC					((GPIO_RegDef_t *)GPIOC_u32_BASE_ADDRESS)
#define GPIOD					((GPIO_RegDef_t *)GPIOD_u32_BASE_ADDRESS)
#define GPIOE					((GPIO_RegDef_t *)GPIOE_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				AFIO                     		           *
*******************************************************************************/

#define AFIO_u32_BASE_ADDRESS						0x40010000U

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 RESERVED1;
	volatile u32 MAPR2;
}AFIO_RegDef_t;

#define AFIO					((AFIO_RegDef_t*)AFIO_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				SYSTICK                    		           *
*******************************************************************************/

#define STK_u32_BASE_ADDRESS						0xE000E010U

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_RegDef_t;

#define STK						((STK_RegDef_t *)STK_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				NVIC                    		           *
*******************************************************************************/

#define NVIC_u32_BASE_ADDRESS						0xE000E100U

typedef struct
{
	volatile u32 ISER[2];
	volatile u32 RESERVED1[30];
	volatile u32 ICER[2];
	volatile u32 RESERVED2[30];
	volatile u32 ISPR[2];
	volatile u32 RESERVED3[30];
	volatile u32 ICPR[2];
	volatile u32 RESERVED4[30];
	volatile u32 IABR[2];
	volatile u32 RESERVED5[62];
	volatile u32 IPR[11]; /* Can handle up to 43 interrupt So IPR10 -> 10*4+3 = 43 */
	volatile u32 RESERVED6[693];
	volatile u32 STIR;
}NVIC_RegDef_t;

#define NVIC					((NVIC_RegDef_t *)NVIC_u32_BASE_ADDRESS)
#define SCB_AIRCR				(*(volatile u32*)(0xE000ED0CU))

/*******************************************************************************
*                      				EXTI                    		           *
*******************************************************************************/

#define EXTI_u32_BASE_ADDRESS						0x40010400U

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_RegDef_t;

#define EXTI						((EXTI_RegDef_t*)EXTI_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				DMA	                    		           *
*******************************************************************************/

#define DMA_u32_BASE_ADDRESS						0x40020000U

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	volatile u32 CCR1;
	volatile u32 CNDTR1;
	volatile u32 CPAR1;
	volatile u32 CMAR1;
	volatile u32 RESERVED1;
	volatile u32 CCR2;
	volatile u32 CNDTR2;
	volatile u32 CPAR2;
	volatile u32 CMAR2;
	volatile u32 RESERVED2;
	volatile u32 CCR3;
	volatile u32 CNDTR3;
	volatile u32 CPAR3;
	volatile u32 CMAR3;
	volatile u32 RESERVED3;
	volatile u32 CCR4;
	volatile u32 CNDTR4;
	volatile u32 CPAR4;
	volatile u32 CMAR4;
	volatile u32 RESERVED4;
	volatile u32 CCR5;
	volatile u32 CNDTR5;
	volatile u32 CPAR5;
	volatile u32 CMAR5;
	volatile u32 RESERVED5;
	volatile u32 CCR6;
	volatile u32 CNDTR6;
	volatile u32 CPAR6;
	volatile u32 CMAR6;
	volatile u32 RESERVED6;
	volatile u32 CCR7;
	volatile u32 CNDTR7;
	volatile u32 CPAR7;
	volatile u32 CMAR7;
	volatile u32 RESERVED7;
}DMA_RegDef_t;

#define DMA						((DMA_RegDef_t*)DMA_u32_BASE_ADDRESS)

/*******************************************************************************
*                      			UART	                    		          *
*******************************************************************************/

#define UART1_u32_BASE_ADDRESS						0x40013800U
#define UART2_u32_BASE_ADDRESS						0x40004400U
#define UART3_u32_BASE_ADDRESS						0x40004800U

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_RegDef_t;

#define UART1						((UART_RegDef_t*)UART1_u32_BASE_ADDRESS)
#define UART2						((UART_RegDef_t*)UART2_u32_BASE_ADDRESS)
#define UART3						((UART_RegDef_t*)UART3_u32_BASE_ADDRESS)

/*******************************************************************************
*                      			SPI	                    		          *
*******************************************************************************/

#define SPI1_u32_BASE_ADDRESS						0x40013000U
#define SPI2_u32_BASE_ADDRESS						0x40003800U

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_RegDef_t;

#define SPI1						((SPI_RegDef_t*)SPI1_u32_BASE_ADDRESS)
#define SPI2						((SPI_RegDef_t*)SPI2_u32_BASE_ADDRESS)

/*******************************************************************************
*                      			TIMER1	                    		          *
*******************************************************************************/

#define TIMER1_u32_BASE_ADDRESS						0x40012C00U

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;
}TIMER1_RegDef_t;

#define TIMER1				((TIMER1_RegDef_t *)TIMER1_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				GPT	                      		           *
*******************************************************************************/

#define TIMER2_u32_BASE_ADDRESS						0x40000000U
#define TIMER3_u32_BASE_ADDRESS						0x40000400U
#define TIMER4_u32_BASE_ADDRESS						0x40000800U

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 :32;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 :32;
	volatile u32 DCR;
	volatile u32 DMAR;
}GPT_RegDef_t;

#define TIMER2				((GPT_RegDef_t *)TIMER2_u32_BASE_ADDRESS)
#define TIMER3				((GPT_RegDef_t *)TIMER3_u32_BASE_ADDRESS)
#define TIMER4				((GPT_RegDef_t *)TIMER4_u32_BASE_ADDRESS)


/*******************************************************************************
*                      			FPEC	                    		          *
*******************************************************************************/

#define FPEC_BASE_ADDRESS						0x40022000U

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_RegDef_t;

#define FPEC 				((FPEC_RegDef_t*)FPEC_BASE_ADDRESS)

#endif
