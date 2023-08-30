#ifndef __MYSTM32F4_UART_LIB
#define __MY_STM32F4_UART_LIB


#include "My_stm32f4_uart_driver.h"


typedef enum {
UART_BAUDRATE_9600,
UART_BAUDRATE_115200,
} UART_BaudrateType;

// Enumerationskonstanter som definieras



void LIB_UART_Write (int ch);
// Funktionen skriver ut en character till UART
int LIB_UART_Read(void)
// Läser in en character från UART och returnerar den 
void LIB_UART_Init(UART_BaudrateType baudrate);
// Funktionen initierar UART med angiven Baudrate

#endif