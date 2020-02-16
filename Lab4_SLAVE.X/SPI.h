/* 
 * File:   SPI.h
 * Author: debor
 *
 * Created on February 12, 2020, 12:01 AM
 */

#ifndef SPI_H
#define	SPI_H

#define SDO  RC5
#define SDI  RC4
#define SCK  RC3
#define SS   RA5

void SPIWRITE (int dato);
void CONF_SPI(void);




#endif	/* SPI_H */

