/*
 * TIMER1_PRIVATE.h
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER1_TIMER1_PRIVATE_H_

#define TCCR1A (*(volatile u8 *)0x4F)
#define TCCR1B (*(volatile u8 *)0x4E)
#define TCNT1H (*(volatile u8 *)0x4D)
#define TCNT1L (*(volatile u8 *)0x4C)
#define TCNT1  (*(volatile u16 *)0x4C)
#define OCR1A  (*(volatile u16 *)0x4A)
#define OCR1BH (*(volatile u8 *)0x49)
#define OCR1BL (*(volatile u8 *)0x48)
#define OCR1B  (*(volatile u16 *)0x48)
#define ICR1H  (*(volatile u8 *)0x47)
#define ICR1L  (*(volatile u8 *)0x46)
#define ICR1   (*(volatile u16 *)0x46)
#define TIMSK  (*(volatile u8 *)0x59)
#define TIFR   (*(volatile u8 *)0x58)

#endif /* INCLUDE_MCAL_TIMER_TIMER1_TIMER1_PRIVATE_H_ */
