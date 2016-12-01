#include "main.h"
void Time_Configuration(void)//1��
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//����жϱ�־λ
	TIM_TimeBaseStructure.TIM_Period = 2000; //���ó�ֵ  72M��ϵͳʱ��  72M/36000=2000 0.5��Ӧ��ΪΪ1000
	TIM_TimeBaseStructure.TIM_Prescaler =36000-1; //Ԥ��ƵԤ����ϵ��
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMxģ��ļĴ���
 
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3ģ��
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//����TIM3�ж�
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;//���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
}
void TIM3_IRQHandler(void)//��ʱ��3��ں���
{
	static u8 i=0;
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//����жϱ�־λ
	GPIO_Write(GPIOC,(u16)~(0x01<<i++));
	if(i==8)i=0;
}
