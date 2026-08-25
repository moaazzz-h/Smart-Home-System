/*
 * ADC_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: DELL
 */
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// DIO Directives

#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_PRIVATE.h"
#include "../INCLUDE/MCAL/ADC/ADC_CFG.h"
void MADC_voidInit(void) {

    CLR_BIT(ADMUX_REG, REFS0);
    CLR_BIT(ADMUX_REG, REFS1);
    ADMUX_REG |= (ADC_VREF_MODE << REFS0);

    CLR_BIT(ADMUX_REG, ADLAR);

    ADCSRA_REG &= 0xF8;
    ADCSRA_REG |= ADC_PRESCALER;

    SET_BIT(ADCSRA_REG, ADEN);
}

u16 ADC_u16ReadSync(unsigned char u8_CopyChannel) {

    ADMUX_REG &= 0xE0;
    ADMUX_REG |= (u8_CopyChannel & 0x1F);

    SET_BIT(ADCSRA_REG, ADSC);

    while (GET_BIT(ADCSRA_REG, ADSC) == 1);

    return ADC_DATA;
}
