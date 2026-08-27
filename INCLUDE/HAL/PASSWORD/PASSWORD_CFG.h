/*
 * PASSWORD_CFG.h
 *
 *  Created on: Aug 26, 2026
 *      Author: HP
 */

#ifndef INCLUDE_HAL_PASSWORD_PASSWORD_CFG_H_
#define INCLUDE_HAL_PASSWORD_PASSWORD_CFG_H_

#define PASSWORD_LENGTH     4
#define PASSWORD_NO_OF_USERS 4

u8 Global_u8Passwords[PASSWORD_NO_OF_USERS][PASSWORD_LENGTH] =
{
    {'1', '2', '3', '4'},   // Moaaz
    {'5', '6', '7', '8'},   // Mohamed
    {'9', '0', '1', '2'},   // Abdo
	{'5', '4', '2', '7'}	// Youssef
};

#endif /* INCLUDE_HAL_PASSWORD_PASSWORD_CFG_H_ */
