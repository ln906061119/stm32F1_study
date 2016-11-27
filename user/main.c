 #include "public.h"

int main()
{
	BSP_Init();
	
	while(1)
	{
		Led_display();
		Sound1();
	}
}
