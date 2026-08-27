/*
 * TIMER1_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: HP
 */

//library Directives
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// TIMER Directives
#include "../INCLUDE/MCAL/TIMER/TIMER1/TIMER1_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER1/TIMER1_PRIVATE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER1/TIMER1_CFG.h"

void MTIMERS_voidTimer1Init(void)
{

    #if TIMER1_COM1A1 == 1
        SET_BIT(TCCR1A, 7);
    #else
        CLR_BIT(TCCR1A, 7);
    #endif

    #if TIMER1_COM1A0 == 1
        SET_BIT(TCCR1A, 6);
    #else
        CLR_BIT(TCCR1A, 6);
    #endif

    #if TIMER1_COM1B1 == 1
        SET_BIT(TCCR1A, 5);
    #else
        CLR_BIT(TCCR1A, 5);
    #endif

    #if TIMER1_COM1B0 == 1
        SET_BIT(TCCR1A, 4);
    #else
        CLR_BIT(TCCR1A, 4);
    #endif

    #if TIMER1_FOC1A == 1
        SET_BIT(TCCR1A, 3);
    #else
        CLR_BIT(TCCR1A, 3);
    #endif

    #if TIMER1_FOC1B == 1
        SET_BIT(TCCR1A, 2);
    #else
        CLR_BIT(TCCR1A, 2);
    #endif

    #if TIMER1_WGM11 == 1
        SET_BIT(TCCR1A, 1);
    #else
        CLR_BIT(TCCR1A, 1);
    #endif

    #if TIMER1_WGM10 == 1
        SET_BIT(TCCR1A, 0);
    #else
        CLR_BIT(TCCR1A, 0);
    #endif

    #if TIMER1_ICNC1 == 1
        SET_BIT(TCCR1B, 7);
    #else
        CLR_BIT(TCCR1B, 7);
    #endif

    #if TIMER1_ICES1 == 1
        SET_BIT(TCCR1B, 6);
    #else
        CLR_BIT(TCCR1B, 6);
    #endif

    #if TIMER1_WGM13 == 1
        SET_BIT(TCCR1B, 4);
    #else
        CLR_BIT(TCCR1B, 4);
    #endif

    #if TIMER1_WGM12 == 1
        SET_BIT(TCCR1B, 3);
    #else
        CLR_BIT(TCCR1B, 3);
    #endif

    #if TIMER1_CS12 == 1
        SET_BIT(TCCR1B, 2);
    #else
        CLR_BIT(TCCR1B, 2);
    #endif

    #if TIMER1_CS11 == 1
        SET_BIT(TCCR1B, 1);
    #else
        CLR_BIT(TCCR1B, 1);
    #endif

    #if TIMER1_CS10 == 1
        SET_BIT(TCCR1B, 0);
    #else
        CLR_BIT(TCCR1B, 0);
    #endif


    ICR1 = 19999;
}

void MTIMERS_voidSetTimer1Value(u16 A_u16Value)
{
    TCNT1 = A_u16Value;
}

u16 MTIMERS_u16ReadTimer1Value(void)
{
    return TCNT1;
}

void MTIMERS_voidSetCR1AValue(u16 A_u16Value)
{
    OCR1A = A_u16Value;
}
