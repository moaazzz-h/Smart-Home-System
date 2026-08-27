/*
 * PASSWORD_INTERFACE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: HP
 */

#ifndef INCLUDE_HAL_PASSWORD_PASSWORD_INTERFACE_H_
#define INCLUDE_HAL_PASSWORD_PASSWORD_INTERFACE_H_


#define PASSWORD_CORRECT       1
#define PASSWORD_WRONG         0
#define PASSWORD_MAX_ATTEMPTS    3

u8 HPASSWORD_u8SelectUser(void);
u8 HPASSWORD_u8CheckPassword(u8 Copy_u8User);

#endif /* INCLUDE_HAL_PASSWORD_PASSWORD_INTERFACE_H_ */
