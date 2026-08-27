/*
 * MANUAL_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: DELL
 */


#include "../INCLUDE/LIB/STD_TYPES.h"
#include <util/delay.h>

// MCAL & HAL
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/MENU/MENU_INTERFACE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_INTERFACE.h"
#include "../INCLUDE/HAL/LDR/LDR_INTERFACE.h"
#include "../INCLUDE/HAL/LM35/LM35_INTERFACE.h"
#include "../INCLUDE/HAL/LIGHT/LIGHT_INTERFACE.h"
#include "../INCLUDE/HAL/FAN/FAN_INTERFACE.h"

// APP
#include "../INCLUDE/APP/MANUAL/MANUAL_INTERFACE.h"
#include "../INCLUDE/APP/MANUAL/MANUAL_PRIVATE.h"

#define DOOR_CLOSED_ANGLE      0
#define DOOR_OPEN_ANGLE        90

void HMANUAL_voidRun(void)
{
    u8 Local_u8Selection;
    u8 Local_u8LightState = 0;
    u8 Local_u8FanState   = 0;
    u8 Local_u8Key;
    u8 Local_u8LightLevel;
    u8 Local_u8Temperature;

    while(1)
    {
        Local_u8Selection = HMENU_u8GetSelection();

        HLCD_voidClearDisplay();

        switch(Local_u8Selection)
        {
            case MENU_LIGHTS:
                Local_u8LightLevel = HLDR_u8GetLightLevel();

                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"LDR Val: ");
                HLCD_voidDisplayNumberUNSigned(Local_u8LightLevel);
                HLCD_voidSendString((u8*)"%");

                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"State: ");
                if(Local_u8LightState) { HLCD_voidSendString((u8*)"ON "); }
                else                   { HLCD_voidSendString((u8*)"OFF"); }

                HLCD_voidGoToPos(ROW3, col1);
                HLCD_voidSendString((u8*)"Press '1'=ON '2'=OFF");
                HLCD_voidGoToPos(ROW4, col1);
                HLCD_voidSendString((u8*)"#=Back to Menu");

                while(1)
                {
                    Local_u8Key = HKEYPAD_u8GetPressedKey();
                    if(Local_u8Key == '1')
                    {
                        Local_u8LightState = 1;
                        HLIGHT_voidOn();
                        HLCD_voidGoToPos(ROW2, col1);
                        HLCD_voidSendString((u8*)"State: ON ");
                    }
                    else if(Local_u8Key == '2')
                    {
                        Local_u8LightState = 0;
                        HLIGHT_voidOff();
                        HLCD_voidGoToPos(ROW2, col1);
                        HLCD_voidSendString((u8*)"State: OFF");
                    }
                    else if(Local_u8Key == '#')
                    {
                        break;
                    }
                }
                break;

            case MENU_TEMPERATURE:
                Local_u8Temperature = HLM35_u8GetTemperature();

                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Temp: ");
                HLCD_voidDisplayNumberUNSigned(Local_u8Temperature);
                HLCD_voidSendString((u8*)" C");

                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"Fan: ");
                if(Local_u8FanState) { HLCD_voidSendString((u8*)"ON "); }
                else                 { HLCD_voidSendString((u8*)"OFF"); }

                HLCD_voidGoToPos(ROW3, col1);
                HLCD_voidSendString((u8*)"Press '1'=ON '2'=OFF");
                HLCD_voidGoToPos(ROW4, col1);
                HLCD_voidSendString((u8*)"#=Back to Menu");

                while(1)
                {
                    Local_u8Key = HKEYPAD_u8GetPressedKey();
                    if(Local_u8Key == '1')
                    {
                        Local_u8FanState = 1;
                        HFAN_voidOn();
                        HLCD_voidGoToPos(ROW2, col1);
                        HLCD_voidSendString((u8*)"Fan: ON ");
                    }
                    else if(Local_u8Key == '2')
                    {
                        Local_u8FanState = 0;
                        HFAN_voidOff();
                        HLCD_voidGoToPos(ROW2, col1);
                        HLCD_voidSendString((u8*)"Fan: OFF");
                    }
                    else if(Local_u8Key == '#')
                    {
                        break;
                    }
                }
                break;

            case MENU_SECURITY:
                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Security Control");
                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"Opening Door...");

                HSERVO_voidSetAngle(DOOR_OPEN_ANGLE);
                _delay_ms(1500);

                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"Closing Door...");
                HSERVO_voidSetAngle(DOOR_CLOSED_ANGLE);
                _delay_ms(1000);
                break;

            case MENU_SYSTEM_INFO:
                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Smart Home Sys");
                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"Version: 2.0");
                HLCD_voidGoToPos(ROW3, col1);
                HLCD_voidSendString((u8*)"Press any key...");

                do {
                    Local_u8Key = HKEYPAD_u8GetPressedKey();
                } while(Local_u8Key == KPAD_NOT_PRESSED);
                break;

            default:
                break;
        }

    }

    HLIGHT_voidOff();
    HFAN_voidOff();
}
