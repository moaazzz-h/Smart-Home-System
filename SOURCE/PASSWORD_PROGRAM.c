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


u8 HPASSWORD_u8CheckPassword(void)
{
    u8 Local_u8Key; // Button pressed by user
    u8 Local_u8Password[PASSWORD_LENGTH]; // Password entered by user
    u8 Local_u8Index; //index of password
    u8 Local_u8PasswordCorrect; //password state




    HLCD_voidClearDisplay();

    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString("Enter Password:");




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


    /* Compare Password */

    Local_u8PasswordCorrect = PASSWORD_CORRECT;

    for(Local_u8Index = 0;
        Local_u8Index < PASSWORD_LENGTH;
        Local_u8Index++)
    {
        if(Local_u8Password[Local_u8Index] != Global_u8Password[Local_u8Index])
        {
            Local_u8PasswordCorrect = PASSWORD_WRONG;
        }
    }


    /* Display Result */

    HLCD_voidClearDisplay();

    if(Local_u8PasswordCorrect == PASSWORD_CORRECT)
    {
        HLCD_voidGoToPos(ROW1, col1);
        HLCD_voidSendString("Access Granted");
    }
    else
    {
        HLCD_voidGoToPos(ROW1, col1);
        HLCD_voidSendString("Wrong Password");
    }

    //_delay_ms(2000);


    return Local_u8PasswordCorrect;
}
