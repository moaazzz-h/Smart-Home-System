/*
 * TIMER0_INTERFACE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_

#define  NORMAL_MODE         0
#define  PHASE_CORRECT_MODE  1
#define  CTC_MODE            2
#define  FAST_PWM_MODE       3

#define  NORMAL_DIO_PIN   0
#define  TOGGLE_CTC       1
#define  CLR_CTC          2
#define  SET_CTC          3

#define  PWM_DISCONNECTED    0
#define  PWM_NON_INVERTING   2
#define  PWM_INVERTING       3

#define  PHASE_CORRECT_PWM_DISCONNECTED     0
#define  PHASE_CORRECT_PWM_DOWNCOUNTING     2
#define  PHASE_CORRECT_PWM_UPCOUNTING       3

#define  NULL 0

void MTIMER_voidInit(void);
void MTIMER0_voidSetOCR0Value(u8 A_u8OCR0Value);
void MTIMER0_voidSetPreloadValue(u8 A_u8NoOfTicks);
void MTIMER0_voidStopTimer(void);
void MTIMER0_voidSetOVFCallback(void (*A_PtrToFunc)(void));
void MTIMER0_voidSetCTCCallback(void (*A_PtrToFunc)(void));

#endif /* INCLUDE_MCAL_TIMER_TIMER0_TIMER0_INTERFACE_H_ */
