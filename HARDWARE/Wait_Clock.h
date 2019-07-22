#ifndef _WAIT_CLOCK_H_
#define _WAIT_CLOCK_H_

#include "stm32f4xx.h"

/************************** 宏定义 **********************/

/************************* 函数声明 **********************/

 /*
  * 功  能：初始化定时器
  * 参  数：void
  * 返回值：void
  *
 */
void Systick_Init(void);

/*
  * 功  能：微秒计时
  * 参  数：u32 nus
  * 返回值：void
  *
 */
void delay_us(u32 nus);

/*
  * 功  能：毫秒计时
  * 参  数：u32 nms
  * 返回值：void
  *
 */
void delay_ms(u32 nms);

/*
  * 功  能：秒计时
  * 参  数：u32 ns
  * 返回值：void
  *
 */
void delay_s(u32 ns);

#endif
