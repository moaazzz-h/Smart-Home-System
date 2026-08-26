/*
 * SERVO_CFG.h
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_SERVO_SERVO_CFG_H_
#define INCLUDE_HAL_SERVO_SERVO_CFG_H_


#define SERVO_ANGLE_MIN      0
#define SERVO_ANGLE_MAX      180

/*
 * القيم المتوافقة مع ICR1 = 19999 و Prescaler = 8 (تردد 50Hz):
 * - زاوية 0 درجة تقابل نبضة 1ms -> تعادل 1000 في OCR1A
 * - زاوية 180 درجة تقابل نبضة 2ms -> تعادل 2000 في OCR1A
 */
#define SERVO_MIN_PWM_TICKS  1000
#define SERVO_MAX_PWM_TICKS  2000

#endif /* INCLUDE_HAL_SERVO_SERVO_CFG_H_ */
