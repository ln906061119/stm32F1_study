#include "public.h"


void Delay(u32 i)	  
{
	while(i--);
}

void Led_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=LED;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	GPIO_SetBits(GPIOC,LED);
}
void Led_display(void)
{
	GPIO_SetBits(GPIOC,LED);
	Delay(600000);//��ʱԼΪ1s
	GPIO_ResetBits(GPIOC,LED);
	Delay(6000000);
}

