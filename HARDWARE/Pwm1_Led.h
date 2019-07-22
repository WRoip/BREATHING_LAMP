#ifndef _PWM1_LED_H_
#define _PWM1_LED_H_

#include "stm32f4xx.h"

/************************** 宏定义 **********************/

/************************* 函数声明 **********************/

 /*
  * 功  能：初始化PWM
  * 参  数：uint32_t pre,预装值 uint16_t psc，预分频系数
  * 返回值：void
  *
 */
void Pwm14_Init(uint32_t pre, uint16_t psc);

/*
  * 功  能：实现呼吸灯
  * 参  数：int n
  * 返回值：void
  *
 */
void Multi_Function(int n);

/****************************** 变量声明 ***************************/

#endif
