/*
 * File:   SPI.c
 * Author: debor
 *
 * Created on February 11, 2020, 11:28 PM
 */

//MASTER

#define _XTAL_FREQ   8000000
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "SPI.h"


void CONF_SPI(void) {
  //  ADCON1 = 0XFF;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    //////////////////////////////////////////////////////
    TRISCbits.TRISC5 =0; //SDO SALIDA DE DATOS
    TRISCbits.TRISC3 =0; //SCK ENTRADA DEL RELOJ
    TRISCbits.TRISC4 =1; //SDI ENTRADA DE DATOS
    TRISAbits.TRISA5 =0; //SS SALIDA PARA EL MAESTRO
    //-------CONFIGURACION SSPSTAT---------------------
    SSPSTATbits.SMP = 0; //
    SSPSTATbits.CKE = 0;
    //-------CONFIGURACION SSPCON---------------------
    SSPCONbits.SSPM = 0b0010;
    SSPCONbits.CKP = 1; //ESTADO IDLE DEL RELOJ ES NIVEL ALTO
    SSPCONbits.SSPEN = 1; //ACTIVAR PUERTO SERIAL
    //SSPCONbits.SSPOV = 0; //LIMPIAR BANDERA OVERFLOW
    //////////////////////////////////////////////////////////
}
void SPIWRITE (char dato){
    PORTAbits.RA5 =0;
    SSPBUF = dato;
    PORTAbits.RA5 =1;
    return;
    //while(!SSPSTATbits.BF); //ESPERAR A QUE CAMBIE LA BANDERA
   // SSPCONbits.SSPOV = 0; //LIMPIAR OVERFLOW BANDERA
}

void SPIREAD (void){
    PORTAbits.RA5 =0;
    if (SSPSTATbits.BF == 1){
        RANDOM = SSPBUF;
        SSPSTATbits.BF =0;  
        SSPCONbits.SSPOV = 0;
    }
    
    return;
}

