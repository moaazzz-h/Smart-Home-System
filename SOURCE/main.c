#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/APP/APP_INTERFACE.h"
#include <util/delay.h>
int main(void)
{
    u8 Local_u8SelectedUser;
    u8 Local_u8PasswordStatus;
    u8 Local_u8Attempts = 0;
    u8 Local_u8SelectedMode;

    // 1.  ÂÌ∆… «·‰Ÿ«„ «·ﬂ«„·…
    APP_voidSystemInit();

    // 2. —”«·… «· —ÕÌ» «·√Ê·Ï
    APP_voidWelcomeScreen();

    while(1)
    {
        // 3. «Œ Ì«— «·„” Œœ„ (ALI, OMAR, SARA, ANAS)
        Local_u8SelectedUser = APP_u8SelectUser();
        Local_u8Attempts = 0;

        while(Local_u8Attempts < 3)
        {
            // 4. ≈œŒ«· «·»«”Ê—œ „⁄ ≈„ﬂ«‰Ì… «· »œÌ· »“— (*)
            Local_u8PasswordStatus = APP_u8GetPasswordWithMask(Local_u8SelectedUser);

            if(Local_u8PasswordStatus == 1)
            {
                // ≈œŒ«· ’ÕÌÕ
                APP_voidPlayWelcomeTone();             // ‰€„…  —ÕÌ»
                APP_voidScrollWelcomeUser(Local_u8SelectedUser); // ‘—Ìÿ  —ÕÌ» »«”„ «·„” Œœ„

                // 5. «Œ Ì«— «·„Êœ (Manual / Auto / Test)
                Local_u8SelectedMode = APP_u8SelectMode();

                switch(Local_u8SelectedMode)
                {
                    case MODE_MANUAL: APP_voidHandleManualMode(); break;
                    case MODE_AUTO:   APP_voidHandleAutoMode();   break;
                    case MODE_TEST:   APP_voidHandleTestMode();   break;
                }
                break; // «·Œ—ÊÃ Ê«·⁄Êœ… ··ﬁ«∆„… «·—∆Ì”Ì… »⁄œ ≈‰Â«¡ «·„Êœ
            }
            else
            {
                // ≈œŒ«· Œ«ÿ∆
                Local_u8Attempts++;
                HBUZZER_voidBeep();

                HLCD_voidClearDisplay();
                HLCD_voidGoToPos(1, 1);
                HLCD_voidSendString("Wrong Password!");
                HLCD_voidGoToPos(2, 1);
                HLCD_voidSendString("Attempts Left: ");
                HLCD_voidDisplayNumberUNSigned(3 - Local_u8Attempts);
                _delay_ms(1500);
            }
        }

        // «·„Õ«Ê·… «·—«»⁄… ( Ã«Ê“ «·‹ 3 „Õ«Ê·« ) ->  ›⁄Ì· «·≈‰–«—
        if(Local_u8Attempts >= 3)
        {
            HLCD_voidClearDisplay();
            HLCD_voidGoToPos(1, 1);
            HLCD_voidSendString("ACCESS DENIED!");

            //  ‘€Ì· ’›«—… ≈‘⁄«— „ ﬂ——… »«·»“—
            for(u8 i = 0; i < 6; i++)
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
