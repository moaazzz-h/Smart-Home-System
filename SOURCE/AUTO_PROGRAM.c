/*
 * AUTO_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
 */

#include "../INCLUDE/LIB/STD_TYPES.h"

// HAL
#include "../INCLUDE/HAL/LM35/LM35_INTERFACE.h"
#include "../INCLUDE/HAL/FAN/FAN_INTERFACE.h"
#include "../INCLUDE/HAL/LDR/LDR_INTERFACE.h"
#include "../INCLUDE/HAL/LIGHT/LIGHT_INTERFACE.h"

// APP
#include "../INCLUDE/APP/AUTO/AUTO_INTERFACE.h"
#include "../INCLUDE/APP/AUTO/AUTO_PRIVATE.h"
#include "../INCLUDE/APP/AUTO/AUTO_CFG.h"


void HAUTO_voidRun(void)
{
    u8 Local_u8Temperature;
    u8 Local_u8LightLevel;

    while(1)
    {

        Local_u8Temperature = HLM35_u8GetTemperature();
        Local_u8LightLevel = HLDR_u8GetLightLevel();


        if(Local_u8Temperature > AUTO_FAN_ON_TEMPERATURE)
        {
            HFAN_voidOn();
        }
        else
        {
            HFAN_voidOff();
        }



        if(Local_u8LightLevel <= 50)
        {
            HLIGHT_voidOn();
        }
        else
        {
            HLIGHT_voidOff();
        }
    }
}
