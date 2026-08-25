/*
 * TIMER_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: HP
 */

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

#include "../INCLUDE/MCAL/TIMER/TIMER_PRIVATE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER_CFG.h"


void (*TIMER0_OVF_CALLBACK)(void) = NULL;

void (*TIMER0_CTC_CALLBACK)(void) = NULL;


void MTIMER0_voidInit(void)
{
#if TIMER0_MODE == NORMAL_MODE

    CLR_BIT(TCCR0, 3);
    CLR_BIT(TCCR0, 6);

    SET_BIT(TIMSK, 0);
    CLR_BIT(TIMSK, 1);

    TCCR0 &= ~0b00000111;
    TCCR0 |= TIMER0_CLK_CFG;


#elif TIMER0_MODE == CTC_MODE

    SET_BIT(TCCR0, 3);
    CLR_BIT(TCCR0, 6);

    TCCR0 &= ~0b00110000;

#if TIMER0_CTC_MODE == NORMAL_DIO_PIN

#elif TIMER0_CTC_MODE == TOGGLE_CTC

    SET_BIT(TCCR0, 4);

#elif TIMER0_CTC_MODE == CLR_CTC

    SET_BIT(TCCR0, 5);

#elif TIMER0_CTC_MODE == SET_CTC

    SET_BIT(TCCR0, 5);
    SET_BIT(TCCR0, 4);

#endif

    CLR_BIT(TIMSK, 0);
    SET_BIT(TIMSK, 1);

    TCCR0 &= ~0b00000111;
    TCCR0 |= TIMER0_CLK_CFG;

#endif
}


void MTIMER0_voidSetPreloadValue(u8 A_u8NoOfTicks)
{
    TCNT0 = A_u8NoOfTicks;
}


void MTIMER0_voidSetCompareValue(u8 A_u8CompareValue)
{
    OCR0 = A_u8CompareValue;
}


void MTIMER0_voidStopTimer(void)
{
    TCCR0 &= ~0b00000111;
}


void MTIMER0_voidSetOVFCallback(void (*A_PtrToFunc)(void))
{
    if (A_PtrToFunc != NULL)
    {
        TIMER0_OVF_CALLBACK = A_PtrToFunc;
    }
}


void MTIMER0_voidSetCTCCallback(void (*A_PtrToFunc)(void))
{
    if (A_PtrToFunc != NULL)
    {
        TIMER0_CTC_CALLBACK = A_PtrToFunc;
    }
}


void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
    if (TIMER0_OVF_CALLBACK != NULL)
    {
        TIMER0_OVF_CALLBACK();
    }
}


void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
    if (TIMER0_CTC_CALLBACK != NULL)
    {
        TIMER0_CTC_CALLBACK();
    }
}
