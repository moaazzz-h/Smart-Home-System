
// DIO Directives

#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_PRIVATE.h"
#include "../INCLUDE/MCAL/ADC/ADC_CFG.h"

void MADC_voidInit(void)
{
    /* Select ADC Reference Voltage */

    CLR_BIT(ADMUX_REG, REFS0);
    CLR_BIT(ADMUX_REG, REFS1);

    ADMUX_REG |= (ADC_VREF_MODE << REFS0);

    /* Right Adjust Result */
    CLR_BIT(ADMUX_REG, ADLAR);

    /* Select ADC Prescaler */

    ADCSRA_REG &= 0xF8;
    ADCSRA_REG |= ADC_PRESCALER;

    /* Enable ADC */

    SET_BIT(ADCSRA_REG, ADEN);
}


u16 MADC_u16ReadSync(u8 u8_CopyChannel)
{
    u16 Local_u16ADCValue;

    /* Select ADC Channel */

    ADMUX_REG &= 0xE0;
    ADMUX_REG |= (u8_CopyChannel & 0x07);

    /* Start Conversion */

    SET_BIT(ADCSRA_REG, ADSC);

    /* Wait Until Conversion Complete */

    while(GET_BIT(ADCSRA_REG, ADSC) == 1);

    /* Read ADC Result */

    Local_u16ADCValue = ADCL_REG;
    Local_u16ADCValue |= ((u16)ADCH_REG << 8);

    return Local_u16ADCValue;
}
