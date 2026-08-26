#ifndef INCLUDE_MCAL_PWM_PWM_PRIVATE_H_
#define INCLUDE_MCAL_PWM_PWM_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

/* Registers Addresses */
#define TCCR1A    *((volatile u8*)0x4F)
#define TCCR1B    *((volatile u8*)0x4E)
#define TCNT1     *((volatile u16*)0x4C)
#define OCR1A     *((volatile u16*)0x4A)
#define OCR1B     *((volatile u16*)0x48)
#define ICR1      *((volatile u16*)0x45)

/* TCCR1A Bits */
#define WGM10     0
#define WGM11     1
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

#endif /* INCLUDE_MCAL_PWM_PWM_PRIVATE_H_ */
