#include "main.h"

void BSP_Init(void)
{
	
	SystemInit();	//ʱ�ӳ�ʼ��
	
	
	Led_Configuration();
	Beep_Configuration();
	Key_Configuration();
	Exti_configuration();
	USART1_Configuration();
	Time_Configuration();
	
}
