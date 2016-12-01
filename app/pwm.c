#include "main.h"

void PWM_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitstructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//���ö�ʱ��
	TIM_TimeBaseStructure.TIM_Period = 900; //���ó�ֵ 
	TIM_TimeBaseStructure.TIM_Prescaler =0; //Ԥ��ƵԤ����ϵ��
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3ģ��
	
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//�ı�ָ���ܽŵ�ӳ��
	
	//����pwm
	TIM_OCInitstructure.TIM_OCMode=TIM_OCMode_PWM1;//ģʽ����
	TIM_OCInitstructure.TIM_OutputState=TIM_OutputState_Enable;//PWM���ʹ��
	TIM_OCInitstructure.TIM_OCPolarity=TIM_OCPolarity_Low;//�͵�ƽLED������������Ϊ��
	TIM_OC2Init(TIM3,&TIM_OCInitstructure);
	
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//ʹ��PWM�Ĵ���
	
	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
	
}

void Pwm_display(void)
{
	static u8 fx=1;//����
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
		
		
		//ͨ����ʱ�����ã��ֲ�1����ö˿�PC6��ӦTIM3��1ͨ����ti��Ӧccs�Ĵ�����ֵ
		TIM_SetCompare2(TIM3,ti);
	
	}
}
