/*
 * File:   main.c
 * Author: debor
 *
 * Created on February 12, 2020, 12:00 AM
 */
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ   8000000
#include <xc.h>
#include <pic16F887.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "ADC.h"
#include "SPI.h"
#include "LCD.h"



void init(void);

void main(void) {
    init();
    CONF_SPI();
    LCD_INIT();
    while (1) {
        
       
      
        SPIWRITE(3); //ENVIAR EL DATO
        SPIREAD();
        
          
       // CONF_ADC();
    
    }
           
    return;
}

void __interrupt() isr(void){
    
    


}

void init(void) { 
    ///8MH
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF2 = 1; 
    ///////////////////////////////////////////////////////////
    TRISAbits.TRISA5 =1;  
    TRISAbits.TRISA0 =1; //POTENCIOMETRO 0 
    TRISAbits.TRISA1 =1; //POTENCIOMETRO 1 
    TRISD =0b00000000; //se define el puerto D como salidas
    //////////////////////////////////////////////////////////////
    PORTC =0;            //se limpia el puerto C
    PORTD =0;          //se limpia el puerto D
    PORTA =0;          //se limpia el puerto A
    //////////////////////////////////////////////////////////
    ANSELH =0;
    ANSELbits.ANS0 =1; //RA0 ANALÛGICO
    ANSELbits.ANS1 =1; //RA1 ANALÛGICO  
}

