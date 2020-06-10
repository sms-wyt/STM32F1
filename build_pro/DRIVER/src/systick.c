#include "systick.h"

__IO uint32_t delay_num;

void delay_config(void)
{
    //�ж�ʱ��72000*��1/72000000��= 1us��
    while(SysTick_Config(72) == 1);
}

void SysTick_Handler(void)
{
    if(delay_num-- != 0);
}

void delay_ms(u16 ms)
{
  delay_num = ms*1000;
  while(delay_num != 0);
}


void delay_us(u16 us)
{
  delay_num = us;
  while(delay_num != 0);
}