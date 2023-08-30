#include "My_stm32f4_uart_lib.h"


#define UART_Baudrate_9600 9600
#define UART_Baudrate_115299 115200

#define UART_CR1_EN //Aktiverar UART
#define UART_CR1_RX //Aktiverar mottagning
#define UART_CR1_TX //Aktiverar sändning

#define UART_STB UART_CR2_STOP // Stoppbit

// Flödeskontroll
#define UART_FCTRL_RTS_EN (1 << 8) //Aktivera flödeskontroll med RTS
#define UART_FCTRL_CTS_EN (1 << 9) //Akivera flödeskontroll med CTS
#define UART_FCTRL_NONE 0x0000 

#define UART_EN() (USART2->CR1 | = UART_CR1_EN)
#define UART_RX_EN() (USART2->CR1 | = UART_CR1_RX)
#define UART_TX_EN (USART2->CR1 | = UART_CR1_TX)


void LIB_UART_Init (UART_BaudrateType baudrate) {

 RCC-> APB1ENR |= 0x20000; //Aktivera klockan till UART2
 RCC->AHB1ENR |= 0x01; //Aktivera klockan till portA
 GPIOA->MODER &= ~0x00F0; // Återställer fyra bitar i registret
 GPIOA->MODER |= 0x00A0; //Ställer in två pinnar.

 GPIOA->AFR[0] & 0xFF00;
 GPIO->AFR[0] | 0x7700;

 UART2->CR2 &= ~UART_CR2_STOP; //Rensar de tidigare stoppbitinställningarna
 UART2->CR2 |=UART_STOPBIT; //Använder den definierade stopbiten
}

UART_ENABLE();

USART2->CR1 | = UART_CR1_RX; //Mottagning
USART2->CR1 | = UART_CR1_TX; //Sändning
USART2 ->CR3 & = FLCTR_DIS; //Inaktiverar flödeskontroll
USART2-> CR2 &= UART_STOP_BIT_2; //Ställer in antal stoppbitar till 1



if (baudrate == UART_BAUDRATE_9600) {
    UART2->BRR |= 9600;
} else if (baudrate ==UART_BAUDRATE_115200) {
   UART2->BRR |=115200;
}
 
 UART2->CR1 |= UART_CR1_EN;

char LIB_UART_READ() {
    while(!(UART2->SR &0x0020)){}
    return UART2->DR;


}

void LIB_UART_Write (int c) {

while(!(UART2->SR & 0x0080)) {}
UART2->DR =(ch & 0xFF);

return c;
}