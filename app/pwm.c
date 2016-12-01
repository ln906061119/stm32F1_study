#include "main.h"

void PWM_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitstructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//配置定时器
	TIM_TimeBaseStructure.TIM_Period = 900; //设置初值 
	TIM_TimeBaseStructure.TIM_Prescaler =0; //预分频预分配系数
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3模块
	
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//改变指定管脚的映射
	
	//配置pwm
	TIM_OCInitstructure.TIM_OCMode=TIM_OCMode_PWM1;//模式设置
	TIM_OCInitstructure.TIM_OutputState=TIM_OutputState_Enable;//PWM输出使能
	TIM_OCInitstructure.TIM_OCPolarity=TIM_OCPolarity_Low;//低电平LED亮，所以设置为低
	TIM_OC2Init(TIM3,&TIM_OCInitstructure);
	
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//使能PWM寄存器
	
	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	
}

void Pwm_display(void)
{
	static u8 fx=1;//方向
	static u32 ti=0;//ti:  0->300->0->300->...
	while(1)
	{
		delay_ms(2);
		if(fx==1)
		{
			ti++;
			if(ti>300)
			{
				fx=0;
			}
		}
		else
		{
			ti--;
			if(ti==0)
			{
				fx=1;
			}
		}
		
		
		//通过定时器复用（手册1）查得端口PC6对应TIM3的1通道。ti对应ccs寄存器的值
		TIM_SetCompare2(TIM3,ti);
	
	}
}
