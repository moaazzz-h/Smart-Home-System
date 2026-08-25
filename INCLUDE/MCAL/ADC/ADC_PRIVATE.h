/*
 * ADC_PRIVATE.h
 *
 *  Created on: Aug 24, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX_REG   (*(volatile unsigned char*)0x27)
#define ADCSRA_REG  (*(volatile unsigned char*)0x26)
#define ADCH_REG    (*(volatile unsigned char*)0x25)
#define ADCL_REG    (*(volatile unsigned char*)0x24)
#define ADC_DATA    (*(volatile unsigned short*)0x24)

#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
