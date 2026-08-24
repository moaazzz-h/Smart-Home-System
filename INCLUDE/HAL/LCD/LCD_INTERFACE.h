/*
 * LCD_INTERFACE.h

 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

typedef enum{
	ROW1=1,
	ROW2
}LCD_ROWS;

typedef enum{
	col1=1,
	col2,
	col3,
	col4,
	col5,
	col6,
	col7,
	col8,
	col9,
	col10,
	col11,
	col12,
	col13,
	col14,
	col15,
	col16,
}LCD_COLS;


void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Command);
void HLCD_voidInit(void);
void HLCD_voidSendString(u8 *A_Pu8String);
void HLCD_voidClearDisplay(void);
void HLCD_voidSendSpecialCharacter (u8 *A_pu8PatternArr, u8 A_u8PatternNumber,LCD_ROWS A_LcdRowNo,LCD_COLS A_LcdColNo );
void HLCD_voidDisplayNumber (u32 A_u32Number);
void HLCD_voidDisplayNumberSigned(s32 A_s32Number);
void HLCD_voidGoToPos (LCD_ROWS A_LcdRowNo,LCD_COLS A_LcdColNo);


#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
