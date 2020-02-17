/*
 * File:   SPI.c
 * Author: debor
 *
 * Created on February 12, 2020, 12:01 AM
 */

///SLAVE

#include <xc.h>
#include <pic16f887.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "SPI.h"

void CONF_SPI(void){
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    ///////////////////////////////////////////////////////
    TRISCbits.TRISC5 =0; //SDO SALIDA DE DATOS
    TRISCbits.TRISC3 =1; //SCK ENTRADA DEL RELOJ
    TRISCbits.TRISC4 =1; //SDI ENTRADA DE DATOS
    TRISAbits.TRISA5 =1; //SS ENTRADA PARA EL ESCLAVO
    //-------CONFIGURACION SSPSTAT---------------------
    SSPSTATbits.SMP = 0; //DEBE SER 0 EN MODO ESCLAVO
    SSPSTATbits.CKE = 0;
    //-------CONFIGURACION SSPCON---------------------
    SSPCON = 0b0100;
    SSPCONbits.CKP = 1; //ESTADO IDLE DEL RELOJ ES NIVEL ALTO
    SSPCONbits.SSPEN = 1; //ACTIVAR PUERTO SERIAL
  //  SSPCONbits.SSPOV = 0; //LIMPIAR BANDERA OVERFLOW
    
    //////////////////////////////////////////////////////////

}

void SPIWRITE (char dato){
    //PORTAbits.RA5 =0;
    SSPBUF = dato;
    while(!SSPSTATbits.BF); //ESPERAR A QUE CAMBIE LA BANDERA
   // SSPCONbits.SSPOV = 0; //LIMPIAR OVERFLOW BANDERA
    return;
}

void SPIREAD (void){
    if (SSPSTATbits.BF == 1){
        RANDOM = SSPBUF;
        SSPSTATbits.BF =0;   
    }
    return;
}

