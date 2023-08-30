#include "My_stm32f4_uart_lib.h"


int main() {
UART_BaudrateType baudrate = UART_BAUDRATE_9600; //Anger den önskade baudraten
LIB_UART_Init (baudrate);


while(1){

 char getData = LIB_UART_Read //Läser in data från UART
LIB_UART_Write (getData); //Skickar data till UART
}

}