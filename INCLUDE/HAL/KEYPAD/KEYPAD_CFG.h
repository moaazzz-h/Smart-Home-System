/*
 * KEYPAD_CFG.h
 *
 *  Created on: Aug 21, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_

#include "../../LIB/STD_TYPES.h"


#define KEYPAD_PRESSED        0
#define KEYPAD_NOT_PRESSED    1

#define ROW_NO 4
#define COL_NO 4

u8 Global_u8ArrOfKeyValue[ROW_NO][COL_NO] ={ {'1','2','3','+'},
											 {'4','5','6','-'},
											 {'7','8','9','*'},
											 {'C','0','=','/'}};


#define KEYPAD_PORT   PORTA

#define ROW0  PIN0
#define ROW1  PIN1
#define ROW2  PIN2
#define ROW3  PIN3

#define COL0  PIN4
#define COL1  PIN5
#define COL2  PIN6
#define COL3  PIN7

static u8 Global_u8RowsArr[] = {PIN0, PIN1, PIN2, PIN3};
static u8 Global_u8ColsArr[] = {PIN4, PIN5, PIN6, PIN7};







#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
