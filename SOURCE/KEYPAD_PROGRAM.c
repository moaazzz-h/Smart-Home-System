/*
 * KEYPAD_PROGRAM.c
 *
 *  Created on: Aug 21, 2026
 *      Author: DELL
 */
#include <util/delay.h>
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_PRIVATE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_CFG.h"



void KEPAD_voidInit(void){

	u8 Local_u8Iterator;


	    for (Local_u8Iterator = 0; Local_u8Iterator < COL_NO; Local_u8Iterator++) {
	        MDIO_voidSetPinDirection(KEYPAD_PORT, Global_u8ColsArr[Local_u8Iterator], DIO_OUTPUT);
	        MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ColsArr[Local_u8Iterator], DIO_HIGH);
	    }


	    for (Local_u8Iterator = 0; Local_u8Iterator < ROW_NO; Local_u8Iterator++) {
	        MDIO_voidSetPinDirection(KEYPAD_PORT, Global_u8RowsArr[Local_u8Iterator], DIO_INPUT);
	        MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8RowsArr[Local_u8Iterator], DIO_HIGH);
	    }


}


u8 HKEYPAD_u8GetPressedKey(void){

	    u8 Local_u8PressedKey = 0xFF;
	    u8 Local_u8RowIndex, Local_u8ColIndex;
	    u8 Local_u8PinValue ;
	    u8 Local_u8Flag = 0 ;
	    for (Local_u8ColIndex = 0; Local_u8ColIndex < COL_NO; Local_u8ColIndex++) {

	        MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ColsArr[Local_u8ColIndex], DIO_LOW);

	        for (Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NO; Local_u8RowIndex++) {
	        	Local_u8PinValue =MDIO_PinstatusGetPinValue(KEYPAD_PORT, Global_u8RowsArr[Local_u8RowIndex]);
	            if ( Local_u8PinValue== DIO_LOW) {

	                _delay_ms(20);


	                while (Local_u8PinValue == DIO_LOW) {
	                	    Local_u8PressedKey = Global_u8ArrOfKeyValue[Local_u8RowIndex][Local_u8ColIndex] ;
	                	    Local_u8PinValue = MDIO_PinstatusGetPinValue( KEYPAD_PORT , Global_u8RowsArr[Local_u8RowIndex] );
	                	    Local_u8Flag = 1 ;
	                }

	                Local_u8PressedKey = Global_u8ArrOfKeyValue[Local_u8RowIndex][Local_u8ColIndex];
	                break;
	            }
	        }
	                MDIO_voidSetPinValue(KEYPAD_PORT, Global_u8ColsArr[Local_u8ColIndex], DIO_HIGH);
	                if ( Local_u8Flag == 1 )
	                {
	                   break;
	                }

	        }




	    return Local_u8PressedKey;
	}




