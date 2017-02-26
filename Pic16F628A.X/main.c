/*
 * File:   main.c
 * Author: Scuud
 *
 * Created on 18 janvier 2017, 00:12
 */

#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ     4000000

#include <xc.h>
#include "PWM.h"
#include "Uart.h"





unsigned int donnee_recu=0;

void main(void) {
   //  OSCCONbits.IRCF = 0x0D; 
    
    UART_Init(300); //9600
    PWM_Init();

    //TRISC=0x00;

    
    while(1){ 
        if (UART_Data_Ready())
        {
        donnee_recu=UART_Read();
        PWM_Read(donnee_recu);
        UART_Write(donnee_recu);
        }
        __delay_ms(50);
        //donnee_recu++;
    };
    
    return;
}
