/*
 * ADC_INTERFACE.h
 *
 *  Created on: Aug 24, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

#define ADC_Channel_0   0
#define ADC_Channel_1   1
#define ADC_Channel_2   2
#define ADC_Channel_3   3
#define ADC_Channel_4   4
#define ADC_Channel_5   5
#define ADC_Channel_6   6
#define ADC_Channel_7   7

void MADC_voidInit(void);
unsigned short MADC_u16ReadSync(unsigned char u8_CopyChannel);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
