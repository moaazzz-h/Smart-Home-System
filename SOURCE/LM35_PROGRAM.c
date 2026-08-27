/*
 * LM35_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: HP
 */

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"
// MCAL Directives
#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"
// HAL Directives
#include "../INCLUDE/HAL/LM35/LM35_INTERFACE.h"
#include "../INCLUDE/HAL/LM35/LM35_PRIVATE.h"
#include "../INCLUDE/HAL/LM35/LM35_CFG.h"

u8 HLM35_u8GetTemperature(void)
{
    u16 Local_u16ADCValue;
    u32 Local_u32Temperature;
    u8 Local_u8Temp;

    Local_u16ADCValue = MADC_u16ReadSync(LM35_ADC_CHANNEL);
    Local_u32Temperature =
            ((u32)Local_u16ADCValue * LM35_ADC_REFERENCE * 100)
            / LM35_ADC_MAX_VALUE;
    Local_u8Temp = (u8)Local_u32Temperature;

    return Local_u8Temp;
}
