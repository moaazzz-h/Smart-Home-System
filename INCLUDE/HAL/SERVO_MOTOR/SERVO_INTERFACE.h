/*
 * SERVO_INTERFACE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_SERVO_SERVO_INTERFACE_H_
#define INCLUDE_HAL_SERVO_SERVO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/* دالة تهيئة السيرفو وتشغيل الـ Timer1 */
void HSERVO_voidInit(void);

/* دالة تحريك السيرفو باستقبال الزاوية المطلوبة (من 0 إلى 180) */
void HSERVO_voidSetAngle(u8 Copy_u8Angle);

#endif /* INCLUDE_HAL_SERVO_SERVO_INTERFACE_H_ */
