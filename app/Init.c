#include "main.h"

void BSP_Init(void)
{
	
	SystemInit();	// ±÷”≥ı ºªØ
	
	
	Led_Configuration();
	Beep_Configuration();
	Key_Configuration();
	Exti_configuration();
	USART1_Configuration();
	Time_Configuration();
	
}
