#include "main.h"

void BSP_Init(void)
{
	
	SystemInit();	// ±÷”≥ı ºªØ
	
	Beep_Configuration();
	Led_Configuration();
	Key_Configuration();
//	Exti_configuration();
//	USART1_Configuration();
//	Time_Configuration();
//	PWM_Configuration();
}
