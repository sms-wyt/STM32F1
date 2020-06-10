#ifndef UART_H
#define UART_H

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "stm32f10x.h" //¹Ì¼þ¿â°üº¬
#include "stm32f10x_usart.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

extern void uart1_init(void);
extern void Uart_write(u8 *pBuf,u8 ulLen);
extern void printfs(char*fmt,...);

#endif