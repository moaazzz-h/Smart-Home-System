/*
 * TIMER0_PRIVATE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_

/* Timer0 Hardware Registers */
#define TCCR0   (*(volatile u8 *) 0x53)
#define TCNT0   (*(volatile u8 *) 0x52)
#define OCR0    (*(volatile u8 *) 0x5C)
#define TIMSK   (*(volatile u8 *) 0x59)
#define TIFR    (*(volatile u8 *) 0x58)


/* TCCR0 Bit Positions */
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

/* TCCR0 Field Masks */
#define CS_MASK     (0b111 << CS00)
#define COM_MASK    (0b11  << COM00)

/* TIMSK Bit Positions  */
#define TOIE0   0
#define OCIE0   1

#endif /* INCLUDE_MCAL_TIMER_TIMER0_TIMER0_PRIVATE_H_ */
