#include "main.h"

void BSP_Init(void)
{
	
	SystemInit();	//ʱ�ӳ�ʼ��
	
	Beep_Configuration();
	Led_Configuration();
	Key_Configuration();
//	Exti_configuration();
//	USART1_Configuration();
//	Time_Configuration();
//	PWM_Configuration();
}
