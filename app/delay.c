#include "main.h"

void delay_ms(unsigned int t)
{
	int i;
	for( i=0;i<t;i++)
	{
		int a=42000;
		while(a--);
	}
}
//void delay_ms(u32 i)
//{
//	u32 temp;
//	SysTick->LOAD=9000*i;	  
//	SysTick->CTRL=0X01;		
//	SysTick->VAL=0;			
//	do
//	{
//		temp=SysTick->CTRL;	  
//	}
//	while((temp&0x01)&&(!(temp&(1<<16))));
//	SysTick->CTRL=0;	
//	SysTick->VAL=0;	
//}

 
void delay_us(unsigned int t)
{
	int i;
	for( i=0;i<t;i++)
	{
		int a=40;
		while(a--);
	}
}
void delay(u32 i)	  
{
	while(i--);
}
