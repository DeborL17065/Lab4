/*
 * File:   ADC.c
 * Author: debor
 *
 * Created on February 12, 2020, 12:01 AM
 */


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SPI.h"
#include "ADC.h"
#include "LCD.h"


void CONF_ADC(void) {
   // INTCONbits.GIE = 1;
    //INTCONbits.PEIE = 1;
    ADCON0 = 0b01000001; //AN0
    ADCON1 = 0b00000000;
    ADCON0bits.GO_DONE =1; //se inicia la conversión
    while(ADCON0bits.GO_DONE ==1); 
    SENSOR1 = ADRESH;
   // SPIWRITE(SENSOR1); //ENVIAR EL DATO
    V_SENSOR1 =(SENSOR1*5.0)/255; //se pasa de 0-5
    NUM1 = (V_SENSOR1)*100; ///SI FUERA 1.98
    A = NUM1%10;   //8
    itoa(SA,A,10);
    B = (NUM1/10)%10;//9
    itoa(SB,B,10);
    C = (NUM1/100)%10;//1 
    itoa(SC,C,10);
    strcat(SB,SA); //se concatenan ambos chars
    strcpy(PUNTO1,"."); //se coloca el caracter dentro del char
    strcat(PUNTO1,SB); //se concatenan ambos chars
    strcat(SC,PUNTO1); //se concatenan ambos chars
  //  SerialSendString(val1); //DATOS A ENVIARA AL ARDUINO
    Lcd_Clear();
    LCD_XY(0,2);
    LCD_Cadena("S1:  S2:  S3:"); 
    LCD_XY(1,2);
    LCD_Cadena(SC);//manda el dato a la LCD
   

//    ADCON0 = 0b01000101; //AN1
//    ADCON1 = 0b00000000;
//    ADCON0bits.GO_DONE =1; //se inicia la conversión
//    while(ADCON0bits.GO_DONE ==1); 
//    SENSOR2 = ADRESH;
//  //  SPIWRITE(SENSOR2); //ENVIAR EL DATO
//    V_SENSOR2 =(SENSOR2*5.0)/255; //se pasa de 0-5
//    NUM2 = (V_SENSOR2)*100; ///SI FUERA 1.98
//    A = NUM2%10;   //8
//    itoa(SA,A,10);
//    B = (NUM2/10)%10;//9
//    itoa(SB,B,10);
//    C = (NUM2/100)%10;//1 
//    itoa(SC,C,10);
//    strcat(SB,SA); //se concatenan ambos chars
//    strcpy(PUNTO1,"."); //se coloca el caracter dentro del char
//    strcat(PUNTO1,SB); //se concatenan ambos chars
//    strcat(SC,PUNTO1); //se concatenan ambos chars
//    LCD_XY(1,7);
//    LCD_Cadena(SC);//manda el dato a la LCD
   // SerialSendString(val2); //DATOS A ENVIARA AL ARDUINO
  
    
}
