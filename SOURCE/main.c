#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"

// MCAL
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

// HAL
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/PASSWORD/PASSWORD_INTERFACE.h"
#include "../INCLUDE/HAL/MENU/MENU_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"




int main(void)
{


    u8 Local_u8PasswordState;
    u8 Local_u8Selection;
    u8 Local_u8Attempts = 0;


    MDIO_voidInit();
    HLCD_voidInit();
    KPAD_voidInit();
    HBUZZER_voidInit();




    while (1)
    {



    }

        Local_u8PasswordState = HPASSWORD_u8CheckPassword();


        if(Local_u8PasswordState == PASSWORD_CORRECT)
        {
            Local_u8Attempts = 0;

            Local_u8Selection = HMENU_u8GetSelection();

            HLCD_voidClearDisplay();

            switch(Local_u8Selection)
            {
                case MENU_LIGHTS:
                    HLCD_voidSendString("Lights Selected");
                    break;

                case MENU_TEMPERATURE:
                    HLCD_voidSendString("Temp Selected");
                    break;

                case MENU_SECURITY:
                    HLCD_voidSendString("Security Selected");
                    break;

                case MENU_SYSTEM_INFO:
                    HLCD_voidSendString("System Info");
                    break;

                default:
                    break;
            }

            _delay_ms(1000);
        }


        else
        {
            Local_u8Attempts++;


            HBUZZER_voidBeep();




            HLCD_voidClearDisplay();

            HLCD_voidGoToPos(ROW1, col1);
            HLCD_voidSendString("Wrong Password");

            HLCD_voidGoToPos(ROW2, col1);
            HLCD_voidSendString("Attempt: ");

            HLCD_voidDisplayNumberUNSigned(Local_u8Attempts);


            _delay_ms(1000);


            if(Local_u8Attempts >= PASSWORD_MAX_ATTEMPTS)
            {
                HLCD_voidClearDisplay();

                HLCD_voidGoToPos(ROW1, col1);
                HLCD_voidSendString("Access Denied");



                for(u8 Local_u8Counter = 0 ; Local_u8Counter < 5 ; Local_u8Counter++){
                	HBUZZER_voidBeep();
                	_delay_ms(200);
                }

                Local_u8Attempts = 0;
            }
        }



    return 0;

}
