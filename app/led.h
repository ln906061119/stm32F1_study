#ifndef _led_H
#define _led_H


#define LED GPIO_Pin_All	//π‹Ω≈∫Í∂®“ÂPC0-7
#define LED_TOGGLE GPIO_ToggleBits(GPIOC,LED)
#define LED_ON GPIO_ResetBits(GPIOC,LED)
#define LED_OFF GPIO_SetBits(GPIOC,LED)

#define LED0_ON GPIO_ResetBits(GPIOC,GPIO_Pin_0)
#define LED1_ON GPIO_ResetBits(GPIOC,GPIO_Pin_1)
#define LED2_ON GPIO_ResetBits(GPIOC,GPIO_Pin_2)
#define LED3_ON GPIO_ResetBits(GPIOC,GPIO_Pin_3)
#define LED4_ON GPIO_ResetBits(GPIOC,GPIO_Pin_4)
#define LED5_ON GPIO_ResetBits(GPIOC,GPIO_Pin_5)
#define LED6_ON GPIO_ResetBits(GPIOC,GPIO_Pin_6)
#define LED7_ON GPIO_ResetBits(GPIOC,GPIO_Pin_7)

#define LED0_OFF GPIO_SetBits(GPIOC,GPIO_Pin_0)
#define LED1_OFF GPIO_SetBits(GPIOC,GPIO_Pin_1)
#define LED2_OFF GPIO_SetBits(GPIOC,GPIO_Pin_2)
#define LED3_OFF GPIO_SetBits(GPIOC,GPIO_Pin_3)
#define LED4_OFF GPIO_SetBits(GPIOC,GPIO_Pin_4)
#define LED5_OFF GPIO_SetBits(GPIOC,GPIO_Pin_5)
#define LED6_OFF GPIO_SetBits(GPIOC,GPIO_Pin_6)
#define LED7_OFF GPIO_SetBits(GPIOC,GPIO_Pin_7)

#define LED0_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_0)
#define LED1_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_1)
#define LED2_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_2)
#define LED3_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_3)
#define LED4_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_4)
#define LED5_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_5)
#define LED6_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_6)
#define LED7_TOGGLE GPIO_ToggleBits(GPIOC,GPIO_Pin_7)

#include "stm32f10x.h"

void Led_Configuration(void);
void Led_display(void);
	 

#endif 
