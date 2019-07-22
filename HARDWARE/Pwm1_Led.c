#include "Pwm1_Led.h"
#include "Wait_Clock.h"

void Pwm14_Init(uint32_t pre, uint16_t psc)
{
	GPIO_InitTypeDef					GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef					TIM_OCInitStruct;
	
	//开启TIM14，TIM1，GPIOF，GPIOE时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	//选择F9，E13，E14
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9, GPIO_AF_TIM14);
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource13, GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource14, GPIO_AF_TIM1);
	
	//设置F9，E13，E14的模式
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd	= GPIO_PuPd_UP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	//配置TIM14，TIM1
	TIM_TimeBaseInitStructure.TIM_Period				= pre;								//预装值
	TIM_TimeBaseInitStructure.TIM_Prescaler			= psc;								//预分频系数
	TIM_TimeBaseInitStructure.TIM_ClockDivision	= TIM_CKD_DIV1;				
	TIM_TimeBaseInitStructure.TIM_CounterMode		= TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
	
	//选择PWM1模式
	TIM_OCInitStruct.TIM_OCMode						= TIM_OCMode_PWM1;      	//PWM1模式
	TIM_OCInitStruct.TIM_OCPolarity				= TIM_OCPolarity_Low;			
	TIM_OCInitStruct.TIM_OutputState			= TIM_OutputState_Enable;	//输出比较
	//TIM_OCInitStruct.TIM_Pulse					=	
	//TIM_OCInitStruct.TIM_OCIdleState		=						//1&8有效
	//TIM_OCInitStruct.TIM_OCNIdleState		= 					//1&8有效
	//TIM_OCInitStruct.TIM_OCNPolarity		=						//1&8有效
	//TIM_OCInitStruct.TIM_OutputNState		=						//1&8有效
	
	TIM_OC1Init(TIM14, &TIM_OCInitStruct);						//TIM14_1
	TIM_OC3Init(TIM1,&TIM_OCInitStruct);							//TIM1_3
	TIM_OC4Init(TIM1,&TIM_OCInitStruct);							//TIM1_4
	
	//开启TIM14
	TIM_Cmd(TIM14,ENABLE);
	
	
	TIM_Cmd(TIM1,ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);                             //TIM1的pwm输出--》必须
	//灯灭
	GPIO_SetBits(GPIOF,GPIO_Pin_9);
	GPIO_SetBits(GPIOE,GPIO_Pin_13 | GPIO_Pin_14);
}

//呼吸灯
void Multi_Function(int n)
{
	int i = 0;
			while(i<=400)
			{
				TIM_SetCompare1(TIM14,i);
				TIM_SetCompare3(TIM1,i);
				TIM_SetCompare4(TIM1,i);
				delay_ms(100);
				i = i + n;
			}

			while(i!=0)
			{
				TIM_SetCompare1(TIM14,i);
				TIM_SetCompare3(TIM1,i);
				TIM_SetCompare4(TIM1,i);
				delay_ms(100);
				i = i - n;
			}
}
