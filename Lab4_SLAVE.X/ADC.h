/* 
 * File:   ADC.h
 * Author: debor
 *
 * Created on February 12, 2020, 12:02 AM
 */

#ifndef ADC_H
#define	ADC_H

uint8_t SENSOR1;
uint8_t SENSOR2;
float V_SENSOR1;
float V_SENSOR2;
int NUM1,NUM2,A,B,C;
char SA[5],SB[5],SC[5];
char PUNTO1[5];
char S1[5];
char S2[5];

void CONF_ADC(void);


#endif	/* ADC_H */

