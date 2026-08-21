
/*
 * LCD_PROGRAM.c
 *
 *  Created on: Aug 20, 2026
 *      Author: DELL
 */

#include <util/delay.h>
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/LCD/LCD_PRIVATE.h"
#include "../INCLUDE/HAL/LCD/LCD_CFG.h"


void HLCD_voidInit(void)
{
	//Wait for more the 30ms
	_delay_ms(32);
	//FUNCTION Set Command
	HLCD_voidSendCommand(FUNCTION_SET);
	//wait for more than 39 us
	_delay_ms(1);
	//Display on/off control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	//wait for more than 39 us
	_delay_ms(1);
	//Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
	//Entry Mode Set
	HLCD_voidSendCommand(ENTRY_MODE_SET);

}

void HLCD_voidSendCommand(u8 A_u8Command)
{
	//RS -->0 ,RW --> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	//set data port with the command
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

	//set pulse on E pin with 2ms delay

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}

// display the char
void HLCD_voidSendData(u8 A_u8Data)
{
	//RS -->1 ,RW --> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		//set data port with the command
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

		//set pulse on E pin with 2ms delay
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}



void HLCD_voidSendString(u8 *A_Pu8String)
{
	while(*A_Pu8String>0)
	{
		HLCD_voidSendData(*A_Pu8String++);
	}
}

void HLCD_voidClearDisplay(void)
{
	//Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
}

void HLCD_voidGoToPos(LCD_ROWS A_LcdRowNo , LCD_COLS  A_LcdColNo)
{
	switch(A_LcdRowNo)
	{
	case ROW1: HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_LcdColNo); break;
	case ROW2: HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_LcdColNo); break;
	default: break;
	}
	_delay_ms(1);
}

void HLCD_voidDisplayNumberUNSigned(u32 A_u32Number)
{
	u32 local_u32Number=1;
	if(A_u32Number==0)
	{
		HLCD_voidSendData('0');
	}
	while(A_u32Number != 0)
	{
		local_u32Number = ((local_u32Number*10)+(A_u32Number %10));
		A_u32Number/=10;
	}
	while(A_u32Number != 1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number/=10;
	}
}

 void HLCD_voidDisplayNumberSigned(s32 A_s32Number)
  {
   u32 local_u32Number=1;
   if(A_s32Number==0)
   {
      HLCD_voidSendData('0');
   }
   if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number *= -1;
	}

	while (A_s32Number != 0)
	{
		local_u32Number = ((local_u32Number*10)+ (A_s32Number%10));
		A_s32Number /= 10;
	}
	while (local_u32Number!= 1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number /= 10;
	}
  }

void HLCD_voidSendSpecialCharacter(u8 *A_pu8PatternArr, u8 A_u8PatternNumber,LCD_ROWS A_LcdRowNo,LCD_COLS A_LcdColNo)
{
	u8 local_u8CGRamAdderss;
	//calculate CGRam Address = Pattern No.*8
	local_u8CGRamAdderss = A_u8PatternNumber * 8;
	// data sheet say that the pin six is must be high
	SET_BIT(local_u8CGRamAdderss,6);
	//Send CGRam Write Command
	HLCD_voidSendCommand(local_u8CGRamAdderss);

	for(u8 i=0; i<8;i++)
	{
		HLCD_voidSendData(A_pu8PatternArr[i]);
	}
	//send go to position Command to the DDRam
	HLCD_voidGoToPos(A_LcdRowNo,A_LcdColNo);
	//display pattern
	HLCD_voidSendData(A_u8PatternNumber);
}

