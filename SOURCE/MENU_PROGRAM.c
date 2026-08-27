/*
 * MENU_PROGRAM.c
 *
 *  Created on: Aug 26, 2026
 *      Author: HP
 */

// Library

#include "../INCLUDE/LIB/STD_TYPES.h"

// HAL

#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"

#include "../INCLUDE/HAL/MENU/MENU_INTERFACE.h"
#include "../INCLUDE/HAL/MENU/MENU_PRIVATE.h"
#include "../INCLUDE/HAL/MENU/MENU_CFG.h"


u8 HMENU_u8GetSelection(void)
{
    u8 Local_u8Key;


    HLCD_voidClearDisplay();

    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"SMART HOME");

    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"1.Lights  2.Temp");

    HLCD_voidGoToPos(ROW3, col1);
    HLCD_voidSendString((u8*)"3.Security 4.Info");


    while(1)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();

        if(Local_u8Key >= '1' && Local_u8Key <= '4')
        {
            return (Local_u8Key - '0');
        }
    }
}

u8 HMENU_u8GetMode(void)
{
    u8 Local_u8Key;


    HLCD_voidClearDisplay();

    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)"Select Mode:");

    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"1.Auto");

    HLCD_voidGoToPos(ROW3, col1);
    HLCD_voidSendString((u8*)"2.Manual");

    HLCD_voidGoToPos(ROW4, col1);
    HLCD_voidSendString((u8*)"0.Logout");


    while(1)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();

        if(Local_u8Key == '1' || Local_u8Key == '2' || Local_u8Key == '0')
        {
            return (Local_u8Key - '0');
        }
    }
}
