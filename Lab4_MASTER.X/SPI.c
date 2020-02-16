/*
 * File:   SPI.c
 * Author: debor
 *
 * Created on February 11, 2020, 11:28 PM
 */


#include <xc.h>
#include "SPI.h"


void CONF_SPI(void){
    //////////////////////////////////////////////////////
    TRISCbits.TRISC5 =0; //SDO SALIDA DE DATOS
    TRISCbits.TRISC3 =0; //SCK ENTRADA DEL RELOJ
    TRISCbits.TRISC4 =1; //SDI ENTRADA DE DATOS
    TRISAbits.TRISA5 =0; //SS SALIDA PARA EL MAESTRO
    //-------CONFIGURACION SSPSTAT---------------------
    SSPSTATbits.SMP = 0; //
    SSPSTATbits.CKE = 0;
    //-------CONFIGURACION SSPCON---------------------
    SSPCON = 0b00000000;
    SSPCONbits.CKP = 1; //ESTADO IDLE DEL RELOJ ES NIVEL ALTO
    SSPCONbits.SSPEN = 1; //ACTIVAR PUERTO SERIAL
    //SSPCONbits.SSPOV = 0; //LIMPIAR BANDERA OVERFLOW
    //////////////////////////////////////////////////////////


}
