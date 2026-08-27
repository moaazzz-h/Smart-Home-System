#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"

// MCAL
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"

// HAL
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/PASSWORD/PASSWORD_INTERFACE.h"
#include "../INCLUDE/HAL/MENU/MENU_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/HAL/SERVO_MOTOR/SERVO_INTERFACE.h"
#include "../INCLUDE/HAL/FAN/FAN_INTERFACE.h"
#include "../INCLUDE/HAL/LIGHT/LIGHT_INTERFACE.h"
#include "../INCLUDE/APP/AUTO/AUTO_INTERFACE.h"
#include "../INCLUDE/APP/MANUAL/MANUAL_INTERFACE.h"


int main(void)
{
    u8 Local_u8User;
    u8 Local_u8PasswordState;
    u8 Local_u8Mode;
    u8 Local_u8Attempts = 0;

    MDIO_voidInit();
    MADC_voidInit();

    HLCD_voidInit();
    KPAD_voidInit();
    HBUZZER_voidInit();

    HSERVO_voidInit();
    HFAN_voidInit();
    HLIGHT_voidInit();

    HFAN_voidOff();
    HLIGHT_voidOff();
    HSERVO_voidSetAngle(0);


    while(1)
    {

        Local_u8User = HPASSWORD_u8SelectUser();

        Local_u8PasswordState = HPASSWORD_u8CheckPassword(Local_u8User);


        if(Local_u8PasswordState == PASSWORD_CORRECT)
        {
            Local_u8Attempts = 0;

            HLCD_voidClearDisplay();

            HLCD_voidGoToPos(ROW1, col1);
            HLCD_voidSendString((u8*)"Access Granted");

            HLCD_voidGoToPos(ROW2, col1);
            HLCD_voidSendString((u8*)"Opening Door...");

            HSERVO_voidSetAngle(90);

            _delay_ms(1000);


            Local_u8Mode = HMENU_u8GetMode();

            while(Local_u8Mode != MODE_LOGOUT)
            {
                if(Local_u8Mode == MODE_AUTO)
                {
                    HLCD_voidClearDisplay();

                    HLCD_voidGoToPos(ROW1, col1);
                    HLCD_voidSendString((u8*)"Auto Mode");

                    HLCD_voidGoToPos(ROW2, col1);
                    HLCD_voidSendString((u8*)"System Running");

                    _delay_ms(1000);

                    HAUTO_voidRun();

                }

                else if(Local_u8Mode == MODE_MANUAL)
                {
                	HLCD_voidClearDisplay();
                    HLCD_voidGoToPos(ROW1, col1);
                    HLCD_voidSendString((u8*)"Manual Mode");

                    _delay_ms(1000);

                    HMANUAL_voidRun();
                }

                Local_u8Mode = HMENU_u8GetMode();
            }


            if(Local_u8Mode == MODE_LOGOUT)
            {
                HLCD_voidClearDisplay();

                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString((u8*)"Logging Out...");

                HSERVO_voidSetAngle(0);

                _delay_ms(1000);
            }
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


                for(u8 Local_u8Counter = 0;
                    Local_u8Counter < 5;
                    Local_u8Counter++)
                {
                    HBUZZER_voidBeep();
                    _delay_ms(200);
                }

                Local_u8Attempts = 0;

                _delay_ms(1000);
            }
        }
    }

    return 0;
}
