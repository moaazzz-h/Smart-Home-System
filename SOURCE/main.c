#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"

// MCAL
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"

// HAL
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/HAL/PASSWORD/PASSWORD_INTERFACE.h"
#include "../INCLUDE/HAL/MENU/MENU_INTERFACE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_INTERFACE.h"
#include "../INCLUDE/HAL/LDR/LDR_INTERFACE.h"
#include "../INCLUDE/HAL/LM35/LM35_INTERFACE.h"
#include "../INCLUDE/HAL/LIGHT/LIGHT_INTERFACE.h"
#include "../INCLUDE/HAL/FAN/FAN_INTERFACE.h"


/* زاوية الباب: مقفول = 0 درجة , مفتوح = 90 درجة */
#define DOOR_CLOSED_ANGLE      0
#define DOOR_OPEN_ANGLE        90

/* حدود التحكم الأوتوماتيكي */
#define LIGHT_DARK_THRESHOLD   30   /* أقل من 30% إضاءة يبقى الجو مضلم -> شغل اللمبة */
#define FAN_TEMP_THRESHOLD     30   /* أعلى من 30 درجة -> شغل المروحة  */


/* ---- وضع التحكم الأوتوماتيكي: بيقرا LDR و LM35 ويتحكم في اللمبة والمروحة لوحده ---- */
static void RunAutoMode(void)
{
    u8 Local_u8Key;
    u8 Local_u8LightLevel;
    u8 Local_u8Temperature;

    HLCD_voidClearDisplay();

    while(1)
    {
        Local_u8LightLevel  = HLDR_u8GetLightLevel();
        Local_u8Temperature = HLM35_u8GetTemperature();

        if(Local_u8LightLevel < LIGHT_DARK_THRESHOLD) { HLIGHT_voidOn();  }
        else                                          { HLIGHT_voidOff(); }

        if(Local_u8Temperature > FAN_TEMP_THRESHOLD)  { HFAN_voidOn();   }
        else                                           { HFAN_voidOff(); }

        HLCD_voidGoToPos(ROW1, col1);
        HLCD_voidSendString((u8*)"AUTO MODE RUNNING");

        HLCD_voidGoToPos(ROW2, col1);
        HLCD_voidSendString((u8*)"Light:");
        HLCD_voidDisplayNumberUNSigned(Local_u8LightLevel);
        HLCD_voidSendString((u8*)"% Temp:");
        HLCD_voidDisplayNumberUNSigned(Local_u8Temperature);
        HLCD_voidSendString((u8*)"C  ");

        HLCD_voidGoToPos(ROW3, col1);
        HLCD_voidSendString((u8*)"[*] Back to Menu");

        Local_u8Key = HKEYPAD_u8GetPressedKey();
        if(Local_u8Key == '*')
        {
            break;
        }

        _delay_ms(300);
    }

    HLIGHT_voidOff();
    HFAN_voidOff();
}


/* ---- وضع التحكم اليدوي: بيستخدم منيو الـ4 اختيارات الموجود بالفعل ---- */
static void RunManualMode(void)
{
    u8 Local_u8Selection;
    u8 Local_u8LightState = 0;
    u8 Local_u8FanState   = 0;
    u8 Local_u8Key;

    while(1)
    {
        Local_u8Selection = HMENU_u8GetSelection();

        HLCD_voidClearDisplay();

        switch(Local_u8Selection)
        {
            case MENU_LIGHTS:
                Local_u8LightState ^= 1;
                if(Local_u8LightState) { HLIGHT_voidOn();  HLCD_voidSendString((u8*)"Light: ON"); }
                else                   { HLIGHT_voidOff(); HLCD_voidSendString((u8*)"Light: OFF"); }
                _delay_ms(1000);
                break;

            case MENU_TEMPERATURE:
                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Temp: ");
                HLCD_voidDisplayNumberUNSigned(HLM35_u8GetTemperature());
                HLCD_voidSendString((u8*)" C");

                HLCD_voidGoToPos(ROW2, col1);
                Local_u8FanState ^= 1;
                if(Local_u8FanState) { HFAN_voidOn();  HLCD_voidSendString((u8*)"Fan: ON"); }
                else                 { HFAN_voidOff(); HLCD_voidSendString((u8*)"Fan: OFF"); }
                _delay_ms(1500);
                break;

            case MENU_SECURITY:
                HLCD_voidSendString((u8*)"Toggle Door...");
                HSERVO_voidSetAngle(DOOR_OPEN_ANGLE);
                _delay_ms(1500);
                HSERVO_voidSetAngle(DOOR_CLOSED_ANGLE);
                break;

            case MENU_SYSTEM_INFO:
                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Smart Home Sys");
                HLCD_voidGoToPos(ROW2, col1);
                HLCD_voidSendString((u8*)"[*] Back to Menu");
                _delay_ms(1500);
                break;

            default:
                break;
        }

        HLCD_voidGoToPos(ROW4, col1);
        HLCD_voidSendString((u8*)"[*]=Exit Manual");

        do
        {
            Local_u8Key = HKEYPAD_u8GetPressedKey();
        } while(Local_u8Key == KPAD_NOT_PRESSED);

        if(Local_u8Key == '*')
        {
            break;
        }
    }

    HLIGHT_voidOff();
    HFAN_voidOff();
}


int main(void)
{
    u8 Local_u8PasswordState;
    u8 Local_u8Mode;
    u8 Local_u8Attempts = 0;


    MDIO_voidInit();
    HLCD_voidInit();
    KPAD_voidInit();
    HBUZZER_voidInit();
    MADC_voidInit();
    HSERVO_voidInit();
    HLIGHT_voidInit();
    HFAN_voidInit();

    HSERVO_voidSetAngle(DOOR_CLOSED_ANGLE);


    while (1)
    {
        Local_u8PasswordState = HPASSWORD_u8CheckPassword();


        if(Local_u8PasswordState == PASSWORD_CORRECT)
        {
            Local_u8Attempts = 0;

            /* افتح الباب بالسيرفو */
            HLCD_voidClearDisplay();
            HLCD_voidGoToPos(ROW1, col1);
            HLCD_voidSendString((u8*)"Door Opening...");
            HSERVO_voidSetAngle(DOOR_OPEN_ANGLE);
            _delay_ms(1500);

            /* اختيار Auto/Manual وتشغيل النظام لحد ما اليوزر يعمل Logout */
            while(1)
            {
                Local_u8Mode = HMENU_u8GetMode();

                if(Local_u8Mode == MODE_AUTO)
                {
                    RunAutoMode();
                }
                else if(Local_u8Mode == MODE_MANUAL)
                {
                    RunManualMode();
                }
                else /* MODE_LOGOUT */
                {
                    break;
                }
            }

            /* اقفل الباب ورجع لشاشة الباسورد */
            HLCD_voidClearDisplay();
            HLCD_voidGoToPos(ROW1, col1);
            HLCD_voidSendString((u8*)"Door Closing...");
            HSERVO_voidSetAngle(DOOR_CLOSED_ANGLE);
            _delay_ms(1000);
        }


        else
        {
            Local_u8Attempts++;

            HBUZZER_voidBeep();

            HLCD_voidClearDisplay();

            HLCD_voidGoToPos(ROW1, col1);
            HLCD_voidSendString((u8*)"Wrong Password");

            HLCD_voidGoToPos(ROW2, col1);
            HLCD_voidSendString((u8*)"Attempt: ");
            HLCD_voidDisplayNumberUNSigned(Local_u8Attempts);

            _delay_ms(1000);


            if(Local_u8Attempts >= PASSWORD_MAX_ATTEMPTS)
            {
                HLCD_voidClearDisplay();

                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Access Denied");

                for(u8 Local_u8Counter = 0 ; Local_u8Counter < 5 ; Local_u8Counter++)
                {
                    HBUZZER_voidBeep();
                    _delay_ms(200);
                }

                Local_u8Attempts = 0;
            }
        }
    }

    return 0;
}
