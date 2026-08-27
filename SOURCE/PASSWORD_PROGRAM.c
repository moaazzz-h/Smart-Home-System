/*
 * PASSWORD_PROGRAM.c
 *
 *  Created on: Aug 26, 2026
 *      Author: HP
 */

#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

// MCAL

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

// HAL

#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"

#include "../INCLUDE/HAL/PASSWORD/PASSWORD_INTERFACE.h"
#include "../INCLUDE/HAL/PASSWORD/PASSWORD_PRIVATE.h"
#include "../INCLUDE/HAL/PASSWORD/PASSWORD_CFG.h"


u8 HPASSWORD_u8SelectUser(void)
{
    u8 Local_u8Key;

    HLCD_voidClearDisplay();

    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Select User:");

    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"1.Moaaz  2.Mohamed");

    HLCD_voidGoToPos(ROW3, col1);
    HLCD_voidSendString((u8*)"3.Abdo   4.Youssef");

    while(1)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();

        if(Local_u8Key >= '1' && Local_u8Key <= '4')
        {
            HLCD_voidClearDisplay();

            HLCD_voidGoToPos(ROW1, col1);
            HLCD_voidSendString((u8*)"User Selected: ");

            HLCD_voidGoToPos(ROW2, col1);
            HLCD_voidSendData(Local_u8Key);

            _delay_ms(500);

            return (Local_u8Key - '1');
        }
    }
}


u8 HPASSWORD_u8CheckPassword(u8 Copy_u8User)
{
    u8 Local_u8Key;
    u8 Local_u8Password[PASSWORD_LENGTH];
    u8 Local_u8Index;
    u8 Local_u8PasswordCorrect;


    HLCD_voidClearDisplay();

    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Enter Password:");


    Local_u8Index = 0;

    while(Local_u8Index < PASSWORD_LENGTH)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();

        if(Local_u8Key != 0xFF)
        {
            if(Local_u8Key >= '0' && Local_u8Key <= '9')
            {
                Local_u8Password[Local_u8Index] = Local_u8Key;

                HLCD_voidGoToPos(ROW2, col1 + Local_u8Index);
                HLCD_voidSendData('*');

                Local_u8Index++;
            }
        }
    }


    Local_u8PasswordCorrect = PASSWORD_CORRECT;

    for(Local_u8Index = 0;
        Local_u8Index < PASSWORD_LENGTH;
        Local_u8Index++)
    {
        if(Local_u8Password[Local_u8Index] !=
           Global_u8Passwords[Copy_u8User][Local_u8Index])
        {
            Local_u8PasswordCorrect = PASSWORD_WRONG;
        }
    }


    HLCD_voidClearDisplay();

    if(Local_u8PasswordCorrect == PASSWORD_CORRECT)
    {
        HLCD_voidGoToPos(ROW1, col1);
        HLCD_voidSendString((u8*)"Access Granted");
    }
    else
    {
        HLCD_voidGoToPos(ROW1, col1);
        HLCD_voidSendString((u8*)"Wrong Password");
    }

    return Local_u8PasswordCorrect;
}
