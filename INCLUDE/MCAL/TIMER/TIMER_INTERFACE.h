/*
 * TIMER_INTERFACE.h
 *
 *  Created on: Aug 25, 2026
 *      Author: HP
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_

/* Timer0 Modes */

#define NORMAL_MODE         0
#define PHASE_CORRECT_MODE  1
#define CTC_MODE            2
#define FAST_PWM_MODE       3


/* CTC Compare Output Modes */

#define NORMAL_DIO_PIN      0
#define TOGGLE_CTC          1
#define CLR_CTC             2
#define SET_CTC             3


/* Timer0 Functions */

void MTIMER0_voidInit(void);

void MTIMER0_voidSetPreloadValue(u8 A_u8NoOfTicks);

void MTIMER0_voidSetCompareValue(u8 A_u8CompareValue);

void MTIMER0_voidStopTimer(void);

void MTIMER0_voidSetOVFCallback(void (*A_PtrToFunc)(void));

void MTIMER0_voidSetCTCCallback(void (*A_PtrToFunc)(void));


#endif /* INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_ */
