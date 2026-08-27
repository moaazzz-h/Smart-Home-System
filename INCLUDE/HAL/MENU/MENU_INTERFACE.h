/*
 * MENU_INTERFACE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: HP
 */

#ifndef INCLUDE_HAL_MENU_MENU_INTERFACE_H_
#define INCLUDE_HAL_MENU_MENU_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define MENU_LIGHTS        1
#define MENU_TEMPERATURE   2
#define MENU_SECURITY      3
#define MENU_SYSTEM_INFO   4

#define MODE_AUTO          1
#define MODE_MANUAL        2
#define MODE_LOGOUT        0

u8 HMENU_u8GetSelection(void);
u8 HMENU_u8GetMode(void);

#endif /* INCLUDE_HAL_MENU_MENU_INTERFACE_H_ */
