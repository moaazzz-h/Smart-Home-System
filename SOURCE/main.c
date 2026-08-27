#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/APP/APP_INTERFACE.h"
#include <util/delay.h>
int main(void)
{
    u8 Local_u8SelectedUser;
    u8 Local_u8PasswordStatus;
    u8 Local_u8Attempts;
    u8 Local_u8SelectedMode;

    APP_voidSystemInit();
    APP_voidWelcomeScreen();

    while(1)
    {
        // «Œ Ì«— «·„” Œœ„
        Local_u8SelectedUser = APP_u8SelectUser();
        Local_u8Attempts = 0;

        while(Local_u8Attempts < 3)
        {
            Local_u8PasswordStatus = APP_u8GetPasswordWithMask(Local_u8SelectedUser);

            if(Local_u8PasswordStatus == 1)
            {
                APP_voidPlayWelcomeTone();
                APP_voidScrollWelcomeUser(Local_u8SelectedUser);

                // **Õ·ﬁ…  À»Ì  «·„Êœ**: » Œ·Ì «·ÌÊ“— Ì›÷· ÃÊ… «·ﬁ«∆„… Ê«·√Ê÷«⁄ Ê„ÌŒ—Ã‘ ·‘«‘… «·‹ Users €Ì— ·Ê ÂÊ «Œ «—
                while(1)
                {
                    Local_u8SelectedMode = APP_u8SelectMode();

                    if(Local_u8SelectedMode == MODE_MANUAL)
                    {
                        APP_voidHandleManualMode();
                    }
                    else if(Local_u8SelectedMode == MODE_AUTO)
                    {
                        APP_voidHandleAutoMode();
                    }
                    else if(Local_u8SelectedMode == MODE_TEST)
                    {
                        APP_voidHandleTestMode();
                    }
                }
                break;
            }
            else
            {
                Local_u8Attempts++;
                HBUZZER_voidBeep();

                HLCD_voidClearDisplay();
                HLCD_voidGoToPos(ROW2, col4);
                HLCD_voidSendString((u8*)"WRONG PASSWORD!");
                HLCD_voidGoToPos(ROW3, col3);
                HLCD_voidSendString((u8*)"ATTEMPTS LEFT: ");
                HLCD_voidDisplayNumberUNSigned(3 - Local_u8Attempts);
                _delay_ms(1500);
            }
        }

        // «·≈‰–«— ⁄‰œ «” ‰›«œ 3 „Õ«Ê·« 
        if(Local_u8Attempts >= 3)
        {
            HLCD_voidClearDisplay();
            HLCD_voidGoToPos(ROW2, col3);
            HLCD_voidSendString((u8*)"SYSTEM LOCKED!");
            HLCD_voidGoToPos(ROW3, col3);
            HLCD_voidSendString((u8*)"ACCESS DENIED!");

            for(u8 i = 0; i < 8; i++)
            {
                HBUZZER_voidOn();
                _delay_ms(200);
                HBUZZER_voidOff();
                _delay_ms(100);
            }
        }
    }

    return 0;
}
