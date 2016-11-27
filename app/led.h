#ifndef _led_H
#define _led_H


#define LED GPIO_Pin_All	//π‹Ω≈∫Í∂®“Â
#include "stm32f10x.h"

void Led_Configuration(void);
void Led_display(void);
void Delay(u32 i);	 

#endif 
