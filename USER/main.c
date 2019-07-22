#include "stm32f4xx.h"
#include "Wait_Clock.h"
#include "Pwm1_Led.h"

int main(void)
{
	Systick_Init();
	Pwm14_Init(500-1,84-1);
		
	while(1){
		Multi_Function(40);	//ºôÎüÆµÂÊ1--400
	}
	
}
