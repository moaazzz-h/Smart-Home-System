#ifndef INCLUDE_HAL_MENU_MENU_INTERFACE_H_
#define INCLUDE_HAL_MENU_MENU_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define MENU_LIGHTS        1
#define MENU_TEMPERATURE   2
#define MENU_SECURITY      3
#define MENU_SYSTEM_INFO   4
#define MENU_TEST          5   // <-- ÃÖÝ ÇáÓØÑ Ïå åäÇ

u8 HMENU_u8GetSelection(void);

#endif /* INCLUDE_HAL_MENU_MENU_INTERFACE_H_ */
