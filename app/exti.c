#include "main.h"

void Exti_configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;//�жϽṹ��
	NVIC_InitTypeDef NVIC_InitStructure;//���ȼ��ṹ��
	
	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ж��迪���Ĺ��ܸ���IOʱ��
	
	GPIO_InitStructure.GPIO_Pin=KEY_LEFT;  //ѡ����Ҫ���õ�IO��,PE2
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOE,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);//ѡ��GPIOE2�ܽ������ⲿ�ж���·
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	//�����ж����ȼ�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//��EXTI2��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//��Ӧ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ��
	NVIC_Init(&NVIC_InitStructure);
}
void EXTI2_IRQHandler(void)//�ⲿ�ж�2��ں���
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
	{
		EXTI_ClearITPendingBit(EXTI_Line2);//�����·2���ⲿ�жϹ���λ
//		LED_ON;
		delay_ms(10);//����
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)
		{
			delay_ms(10);//����
			LED5_TOGGLE;
		}
		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0);
	}
}
