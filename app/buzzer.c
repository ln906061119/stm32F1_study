#include "main.h"


void Beep_Configuration(void)	  
{
	GPIO_InitTypeDef GPIO_InitStructure;	

	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  

	GPIO_InitStructure.GPIO_Pin=BUZ;		
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;		
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	 
}

void Sound(void)  
{
	int n;
	u32 i=1000;
	for(n=0;n<500;n++)			  
	{
		GPIO_SetBits(GPIOB,BUZ);		 
		delay(i);
		GPIO_ResetBits(GPIOB,BUZ);	  
		delay(i);
	}	
}

void Sound1(void)  
{
	u32 i=5000;
	while(i--)			  
	{
		GPIO_SetBits(GPIOB,BUZ);		 
		delay(i);
		GPIO_ResetBits(GPIOB,BUZ);	  
		delay(i--);
	}	
}


void Sound2(void)  
{
	u32 i=1000;
	while(i--)					
	{
		GPIO_SetBits(GPIOB,BUZ);	  
		delay(i);
		GPIO_ResetBits(GPIOB,BUZ);	
		delay(i--);
	}	
}
