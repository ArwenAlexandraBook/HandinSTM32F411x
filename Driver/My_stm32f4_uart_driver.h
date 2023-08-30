#ifndef _MY_STM32F4_UART_DRIVER_H
#define _MY_STM32F4_UART_DRIVER_H

#include "my_stm32f4_gpio_driver.h"
#include <stdint.h>



//Basadresser för periferibussar
#define APB1PERIPH_BASE (0x40000000u) //Basadressen för APB1 bussen
#define APB2PERIPH_BASE ( APB1PERIPH_BASE + 0x10000u) // Basadressen för APB2 bussen

// APB2 är periferibusen. Periferierna nedan är anslutna till denna buss. Nedan lägger vi till förskjutning för att komma åt basadresserna.

#define USART1_BASE (APB2PERIPH_BASE + 0x1000u) 
#define USART2_BASE (APB1PERIPH_BASE + 0x4400u) 
#define USART6_BASE (APB2PERIPH_BASE + 0x1400u)


TypeDef struct 
{
volatile uint32_t SR; //Statusregistret
volatile uint32_t DR; //Dataregistret
volatile uint32_t BRR; //Baudrate-registret
volatile uint32_t CR1; // Control register 1
volatile uint32_t CR2;  // Control register 2
volatile uint32_t CR3; // Control register 3
volatile uint32_t GTPR; // Guardtime och prescaler
}USART_TypeDef; 

#define USART1 ((USART_TypeDef *)USART1_BASE)
#define USART2 ((USART_TypeDef *)USART2_BASE)
#define USART6 ((USART_TypeDef *)USART6_BASE)

#endif