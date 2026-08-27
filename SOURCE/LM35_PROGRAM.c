/*
 * LM35_PROGRAM.c
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

#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"   // update path if yours is different

#include "../INCLUDE/HAL/LM35/LM35_INTERFACE.h"
#include "../INCLUDE/HAL/LM35/LM35_PRIVATE.h"
#include "../INCLUDE/HAL/LM35/LM35_CFG.h"

// keeps track of the highest/lowest reading since power up
static u8 MaxTemp = 0;
static u8 MinTemp = 0;
static u8 FirstTime = TRUE;

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

    // update max/min
    if(FirstTime == TRUE)
    {
        MaxTemp = Local_u8Temp;
        MinTemp = Local_u8Temp;
        FirstTime = FALSE;
    }
    else if(Local_u8Temp > MaxTemp)
    {
        MaxTemp = Local_u8Temp;
    }
    else if(Local_u8Temp < MinTemp)
    {
        MinTemp = Local_u8Temp;
    }

    return Local_u8Temp;
}

u8 HLM35_u8GetMaxTemperature(void)
{
    return MaxTemp;
}

u8 HLM35_u8GetMinTemperature(void)
{
    return MinTemp;
}

void HLM35_voidDisplayOnLCD(void)
{
    u8 Local_u8Temp = HLM35_u8GetTemperature();

    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Temp: ");
    HLCD_voidDisplayNumberUNSigned(Local_u8Temp);
    HLCD_voidSendString((u8*)" C   ");

    HLCD_voidGoToPos(ROW2, col1);
    if(Local_u8Temp < LM35_MIN_NORMAL)
    {
        HLCD_voidSendString((u8*)"Status: Low    ");
    }
    else if(Local_u8Temp > LM35_MAX_NORMAL)
    {
        HLCD_voidSendString((u8*)"Status: High   ");
    }
    else
    {
        HLCD_voidSendString((u8*)"Status: Normal ");
    }

    HLCD_voidGoToPos(ROW3, col1);
    HLCD_voidSendString((u8*)"Max: ");
    HLCD_voidDisplayNumberUNSigned(MaxTemp);
    HLCD_voidSendString((u8*)" C   ");

    HLCD_voidGoToPos(ROW4, col1);
    HLCD_voidSendString((u8*)"Min: ");
    HLCD_voidDisplayNumberUNSigned(MinTemp);
    HLCD_voidSendString((u8*)" C   ");
}
