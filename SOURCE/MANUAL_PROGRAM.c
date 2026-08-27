/*
 * MANUAL_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
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
            HLCD_voidGoToPos(ROW3, col1);
            HLCD_voidSendString((u8*)"Press 1.ON    2.OFF");
            HLCD_voidGoToPos(ROW4, col1);
            HLCD_voidSendString((u8*)"C. Back to Menu");

            while(1)
            {

                Local_u8LightLevel = HLDR_u8GetLightLevel();
                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"LDR Value: ");
                HLCD_voidDisplayNumberUNSigned(Local_u8LightLevel);
                HLCD_voidSendString((u8*)"%   ");

                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"State: ");
                if(Local_u8LightState) { HLCD_voidSendString((u8*)"ON "); }
                else                   { HLCD_voidSendString((u8*)"OFF"); }

                Local_u8Key = HKEYPAD_u8GetPressedKey();
                if(Local_u8Key == '1')
                {
                    Local_u8LightState = 1;
                    HLIGHT_voidOn();
                }
                else if(Local_u8Key == '2')
                {
                    Local_u8LightState = 0;
                    HLIGHT_voidOff();
                }
                else if(Local_u8Key == 'C')
                {
                    break;
                }

                _delay_ms(100);
            }
            break;

        case MENU_TEMPERATURE:
            HLCD_voidGoToPos(ROW3, col1);
            HLCD_voidSendString((u8*)"Press 1.ON    2.OFF");
            HLCD_voidGoToPos(ROW4, col1);
            HLCD_voidSendString((u8*)"C. Back to Menu");

            while(1)
            {
                Local_u8Temperature = HLM35_u8GetTemperature();
                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Temp: ");
                HLCD_voidDisplayNumberUNSigned(Local_u8Temperature);
                HLCD_voidSendString((u8*)" C   ");

                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"Fan: ");
                if(Local_u8FanState) { HLCD_voidSendString((u8*)"ON "); }
                else                 { HLCD_voidSendString((u8*)"OFF"); }

                Local_u8Key = HKEYPAD_u8GetPressedKey();
                if(Local_u8Key == '1')
                {
                    Local_u8FanState = 1;
                    HFAN_voidOn();
                }
                else if(Local_u8Key == '2')
                {
                    Local_u8FanState = 0;
                    HFAN_voidOff();
                }
                else if(Local_u8Key == 'C')
                {
                    break;
                }

                _delay_ms(100);
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
                HLCD_voidSendString((u8*)"Smart Home System");
                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"Status: Ready");
                HLCD_voidGoToPos(ROW3, col1);
                HLCD_voidSendString((u8*)"Press any key...");

                do {
                    _delay_ms(50);
                    Local_u8Key = HKEYPAD_u8GetPressedKey();
                } while (Local_u8Key == 0xFF);

                break;
            case MENU_BACK:
            	return;
            default:
                break;
        }

    }

    HLIGHT_voidOff();
    HFAN_voidOff();
}
