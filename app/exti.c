#include "main.h"

void Exti_configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;//中断结构体
	NVIC_InitTypeDef NVIC_InitStructure;//优先级结构体
	
	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//中断需开启的功能复用IO时钟
	
	GPIO_InitStructure.GPIO_Pin=KEY_LEFT;  //选择你要设置的IO口,PE2
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOE,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);//选择GPIOE2管脚用作外部中断线路
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	//配置中断优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//打开EXTI2的全局中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//响应优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能
	NVIC_Init(&NVIC_InitStructure);
}
void EXTI2_IRQHandler(void)//外部中断2入口函数
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
	{
		EXTI_ClearITPendingBit(EXTI_Line2);//清除线路2的外部中断挂起位
//		LED_ON;
		delay_ms(10);//消抖
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)
		{
			delay_ms(10);//消抖
			LED5_TOGGLE;
		}
		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0);
	}
}
