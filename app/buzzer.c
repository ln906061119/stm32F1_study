#include "public.h"


void BEEP_Init()	  
{
	GPIO_InitTypeDef GPIO_InitStructure;	

	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  

	GPIO_InitStructure.GPIO_Pin=BUZ;		
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;		
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	 
}


void Sound1(void)  
{
	u32 i=5000;
	while(i--)			  
	{
		GPIO_SetBits(GPIOB,BUZ);		 
		Delay(i);
		GPIO_ResetBits(GPIOB,BUZ);	  
		Delay(i--);
	}	
}


void Sound2(void)  
{
	u32 i=1000;
	while(i--)					
	{
		GPIO_SetBits(GPIOB,BUZ);	  
		Delay(i);
		GPIO_ResetBits(GPIOB,BUZ);	
		Delay(i--);
	}	
}
