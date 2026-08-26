/*
 * TIMER1_INTERFACE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_


void MTIMERS_voidTimer1Init(void);

// النوع u16 عشان OCR1A بياخد قيم لغاية 19999 (ICR1 = TOP) مش u8
void MTIMERS_voidSetCR1AValue(u16 A_u16Value);

void MTIMERS_voidSetTimer1Value(u16 A_u16Value);
u16 MTIMERS_u16ReadTimer1Value(void);
#endif /* INCLUDE_MCAL_TIMER_TIMER1_TIMER1_INTERFACE_H_ */
