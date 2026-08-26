/*


/*
 /*
 * TIMER_PROGRAM.c
 *
 *  Created on: Aug 26, 2026
 *      Author: DELL
 */

//library Directives
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// TIMER Directives
#include "../INCLUDE/MCAL/TIMER/TIMER0/TIMER0_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER0/TIMER0_PRIVATE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER0/TIMER0_CFG.h"

static void (*TIMER0_OVF_CALLBACK)(void) = NULL;
static void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void MTIMER_voidInit(void){

#if TIMER0_MODE==NORMAL_MODE

    CLR_BIT(TCCR0, WGM01);   // WGM01 = 0
    CLR_BIT(TCCR0, WGM00);   // WGM00 = 0

    SET_BIT(TIMSK, TOIE0);
    CLR_BIT(TIMSK, OCIE0);

    /* Clear COM + CS fields, keep WGM/FOC0 as set above */
    TCCR0 &= ~(COM_MASK | CS_MASK);
    TCCR0 |= TIMER0_CLK_CFG;


#elif TIMER0_MODE==CTC_MODE

    /*  CTC -> WGM01 = 1 , WGM00 = 0 */
    SET_BIT(TCCR0, WGM01);   // WGM01 = 1
    CLR_BIT(TCCR0, WGM00);   // WGM00 = 0

    CLR_BIT(TIMSK, TOIE0);
    SET_BIT(TIMSK, OCIE0);

    /* Clear COM + CS fields, keep WGM/FOC0 as set above */
    TCCR0 &= ~(COM_MASK | CS_MASK);
    TCCR0 |= (TIMER0_CLK_CFG | (TIMER0_CTC_OC0_PIN_MODE << COM00));

#elif TIMER0_MODE==FAST_PWM_MODE

    CLR_BIT(TIMSK, TOIE0);
    CLR_BIT(TIMSK, OCIE0);

    /* Clear everything except FOC0, then rebuild the whole register */
    TCCR0 &= (1 << FOC0);
    SET_BIT(TCCR0, WGM01);   // WGM01 = 1
    SET_BIT(TCCR0, WGM00);   // WGM00 = 1
    TCCR0 |= (TIMER0_CLK_CFG | (TIMER0_PWM_MODE << COM00));

#elif TIMER0_MODE==PHASE_CORRECT_MODE

    CLR_BIT(TIMSK, TOIE0);
    CLR_BIT(TIMSK, OCIE0);

    /* Phase Correct PWM -> WGM01 = 0 , WGM00 = 1 */
    /* Clear everything except FOC0, then rebuild the whole register */
    TCCR0 &= (1 << FOC0);
    SET_BIT(TCCR0, WGM00);   // WGM00 = 1
    TCCR0 |= (TIMER0_CLK_CFG | (TIMER0_PHASE_CORRECT_MODE << COM00));


#endif


}

void MTIMER0_voidSetOCR0Value(u8 A_u8OCR0Value)
{
    OCR0 = A_u8OCR0Value;
}

void MTIMER0_voidSetPreloadValue(u8 A_u8NoOfTicks)
{
    TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidStopTimer(void)
{
    TCCR0 &= ~CS_MASK;
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
    if(TIMER0_OVF_CALLBACK != NULL)
    {
        TIMER0_OVF_CALLBACK();
    }
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if(TIMER0_CTC_CALLBACK != NULL)
    {
        TIMER0_CTC_CALLBACK();
    }
}
