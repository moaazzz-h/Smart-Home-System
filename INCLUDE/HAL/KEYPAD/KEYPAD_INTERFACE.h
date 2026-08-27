/*
 * KEYPAD_INTERFACE.h
 *
 *  Created on: Aug 20, 2026
 *      Author: HP
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define KPAD_NOT_PRESSED    0xFF
#include "../../LIB/STD_TYPES.h"
u8 HKEYPAD_u8GetPressedKey(void);
void KPAD_voidInit(void);


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
