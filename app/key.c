#include "main.h"

void Key_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=KEY_UP;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;	 //������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
	GPIO_InitStructure.GPIO_Pin=KEY_LEFT|KEY_DOWN|KEY_RIGHT;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	 //������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOE,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
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
