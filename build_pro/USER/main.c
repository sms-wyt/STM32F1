#include "stm32f10x.h"
#include "led.h"
#include "systick.h"
#include "uart.h"

int main(void)
{
    SystemInit();//系统初始�?,默认72M时钟，采用外�?8M晶振倍频

    delay_config();
    led_init();
   while (1)
   {
     led_opt(0);
     delay_ms(50);
     led_opt(1);
     delay_ms(50);
   }
  return 0;
}
