#include "public.h"


void Delay(u32 i)	  
{
	while(i--);
}

void Led_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=LED;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* 初始化GPIO */
	GPIO_SetBits(GPIOC,LED);
}
void Led_display(void)
{
	GPIO_SetBits(GPIOC,LED);
	Delay(600000);//延时约为1s
	GPIO_ResetBits(GPIOC,LED);
	Delay(6000000);
}

