/*
 * LDR_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: HP
 */

// Library Directives

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

// MCAL Directives

#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"

// HAL Directives

#include "../INCLUDE/HAL/LDR/LDR_INTERFACE.h"
#include "../INCLUDE/HAL/LDR/LDR_PRIVATE.h"
#include "../INCLUDE/HAL/LDR/LDR_CFG.h"


u8 HLDR_u8GetLightLevel(void)
{
    u16 Local_u16ADCValue;
    u32 Local_u32LightLevel;

    Local_u16ADCValue = MADC_u16ReadSync(LDR_ADC_CHANNEL);

    if(Local_u16ADCValue <= LDR_ADC_MIN_VALUE)
    {
        return 0;
    }

    if(Local_u16ADCValue >= LDR_ADC_MAX_VALUE)
    {
        return 100;
    }

    Local_u32LightLevel =
            ((u32)(Local_u16ADCValue - LDR_ADC_MIN_VALUE) * 100)
            / (LDR_ADC_MAX_VALUE - LDR_ADC_MIN_VALUE);

    return (u8)Local_u32LightLevel;
}
