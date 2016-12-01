#include "main.h"
void Time_Configuration(void)//1秒
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//清除中断标志位
	TIM_TimeBaseStructure.TIM_Period = 2000; //设置初值  72M的系统时钟  72M/36000=2000 0.5秒应设为为1000
	TIM_TimeBaseStructure.TIM_Prescaler =36000-1; //预分频预分配系数
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx模块的寄存器
 
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3模块
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//开启TIM3中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;//打开中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
}
void TIM3_IRQHandler(void)//定时器3入口函数
{
	static u8 i=0;
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//清除中断标志位
	GPIO_Write(GPIOC,(u16)~(0x01<<i++));
	if(i==8)i=0;
}
