/*
 * TIMER1_INTERFACE.h
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_

void MTIMERS_voidTimer1Init(void);

void MTIMERS_voidSetCR1AValue(u16 A_u16Value);

void MTIMERS_voidSetTimer1Value(u16 A_u16Value);
u16 MTIMERS_u16ReadTimer1Value(void);

#endif /* INCLUDE_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_ */
