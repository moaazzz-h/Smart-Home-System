#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

/* Registers Addresses for ATmega32 Timer1 */
#define TCCR1A    *((volatile u8*)0x4F)
#define TCCR1B    *((volatile u8*)0x4E)
#define TCNT1H    *((volatile u8*)0x4D)
#define TCNT1L    *((volatile u8*)0x4C)
#define TCNT1     *((volatile u16*)0x4C) // 16-bit access

#define OCR1AH    *((volatile u8*)0x4B)
#define OCR1AL    *((volatile u8*)0x4A)
#define OCR1A     *((volatile u16*)0x4A) // 16-bit access

#define OCR1BH    *((volatile u8*)0x49)
#define OCR1BL    *((volatile u8*)0x48)
#define OCR1B     *((volatile u16*)0x48) // 16-bit access

#define ICR1H     *((volatile u8*)0x46)
#define ICR1L     *((volatile u8*)0x45)
#define ICR1      *((volatile u16*)0x45) // 16-bit access

#define TIMSK     *((volatile u8*)0x59)
#define TIFR      *((volatile u8*)0x58)

/* TCCR1A Bits */
#define WGM10     0
#define WGM11     1
#define FOC1B     2
#define FOC1A     3
#define COM1B0    4
#define COM1B1    5
#define COM1A0    6
#define COM1A1    7

/* TCCR1B Bits */
#define CS10      0
#define CS11      1
#define CS12      2
#define WGM12     3
#define WGM13     4
#define ICES1     6
#define ICNC1     7

/* TIMSK Bits for Timer1 */
#define TOIE1     2
#define OCIE1B    3
#define OCIE1A    4
#define TICIE1    5

/* Modes Definitions */
#define TIMER1_NORMAL_MODE                0
#define TIMER1_PWM_PHASE_CORRECT_8BIT     1
#define TIMER1_PWM_PHASE_CORRECT_9BIT     2
#define TIMER1_PWM_PHASE_CORRECT_10BIT    3
#define TIMER1_CTC_OCR1A_TOP              4
#define TIMER1_FAST_PWM_8BIT              5
#define TIMER1_FAST_PWM_9BIT              6
#define TIMER1_FAST_PWM_10BIT             7
#define TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1 8
#define TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A 9
#define TIMER1_PWM_PHASE_CORRECT_ICR1    10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A   11
#define TIMER1_CTC_ICR1_TOP               12
#define TIMER1_FAST_PWM_ICR1_TOP          14
#define TIMER1_FAST_PWM_OCR1A_TOP         15

/* Prescaler Definitions */
#define TIMER1_STOP                       0
#define TIMER1_DIV_BY_1                   1
#define TIMER1_DIV_BY_8                   2
#define TIMER1_DIV_BY_64                  3
#define TIMER1_DIV_BY_256                 4
#define TIMER1_DIV_BY_1024                5

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
