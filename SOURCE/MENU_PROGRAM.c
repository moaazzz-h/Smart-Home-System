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
    HLCD_voidSendString("SMART HOME");

    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString("1.Lights  2.Temp");

    HLCD_voidGoToPos(ROW3, col1);
    HLCD_voidSendString("3.Security 4.Info");


    while(1)
    {
        Local_u8Key = HKEYPAD_u8GetPressedKey();

        if(Local_u8Key >= '1' && Local_u8Key <= '4')
        {
            return (Local_u8Key - '0');
        }
    }
}
