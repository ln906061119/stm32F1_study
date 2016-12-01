#include "main.h"

void Key_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=KEY_UP;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;	 //设置下拉输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	GPIO_InitStructure.GPIO_Pin=KEY_LEFT|KEY_DOWN|KEY_RIGHT;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	 //设置上拉输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOE,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	GPIO_ResetBits(GPIOA,KEY_UP);
}
void Key_display(void)
{
	if(key_up == 1)
	{
		delay_ms(50);
		LED0_TOGGLE;
		while(key_up == 1);
	}
	if(key_left == 0)
	{
		delay_ms(50);
		LED1_TOGGLE;
		while(key_left == 0);
	}
	if(key_down == 0)
	{
		delay_ms(50);
		LED2_TOGGLE;
		while(key_down == 0);
	}
	if(key_right == 0)
	{
		delay_ms(50);
		LED_TOGGLE;
		while(key_right == 0);
	}
}
