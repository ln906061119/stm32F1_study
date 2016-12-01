#ifndef _key_H
#define _key_H

void Key_Configuration(void);
void Key_display(void);
	 
#define KEY_UP GPIO_Pin_0//PA0	
#define KEY_LEFT GPIO_Pin_2//PE2
#define KEY_DOWN GPIO_Pin_3//PE3
#define KEY_RIGHT GPIO_Pin_4//PE4

#define key_up GPIO_ReadInputDataBit(GPIOA,KEY_UP)
#define key_left GPIO_ReadInputDataBit(GPIOE,KEY_LEFT)
#define key_down GPIO_ReadInputDataBit(GPIOE,KEY_DOWN)
#define key_right GPIO_ReadInputDataBit(GPIOE,KEY_RIGHT)

#endif 
