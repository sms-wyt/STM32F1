#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h" //¹Ì¼þ¿â°üº¬
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


extern void led_init(void);
extern void led_opt(u8 opt);

#endif