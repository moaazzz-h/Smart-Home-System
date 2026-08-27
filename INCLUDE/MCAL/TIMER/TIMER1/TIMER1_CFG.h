/*
 * TIMER1_CFG.h
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER1_TIMER1_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER1_TIMER1_CFG_H_

/*
 * TCCR1A Bits configuration (Fast PWM Non-Inverting Mode 14)
 * COM1A1 = 1, COM1A0 = 0, WGM11 = 1, WGM10 = 0
 */
#define TIMER1_COM1A1   1
#define TIMER1_COM1A0   0
#define TIMER1_COM1B1   0
#define TIMER1_COM1B0   0
#define TIMER1_FOC1A    0
#define TIMER1_FOC1B    0
#define TIMER1_WGM11    1
#define TIMER1_WGM10    0

/*
 * TCCR1B Bits configuration (WGM13 = 1, WGM12 = 1 & Prescaler = 8 -> CS11 = 1)
 */
#define TIMER1_ICNC1    0
#define TIMER1_ICES1    0
#define TIMER1_WGM13    1
#define TIMER1_WGM12    1
#define TIMER1_CS12     0
#define TIMER1_CS11     1
#define TIMER1_CS10     0

/*
 * Interrupt Enable Configurations
 */
#define TIMER1_OVF_INT_EN       0
#define TIMER1_COMPA_INT_EN     0
#define TIMER1_COMPB_INT_EN     0
#define TIMER1_CAPT_INT_EN      0


#endif /* INCLUDE_MCAL_TIMER_TIMER1_TIMER1_CFG_H_ */
