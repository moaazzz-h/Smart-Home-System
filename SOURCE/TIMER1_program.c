#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER1/TIMER1_interface.h"
#include "../INCLUDE/MCAL/TIMER1/TIMER1_private.h"
#include "../INCLUDE/MCAL/TIMER1/TIMER1_config.h"

/* Static CallBack Pointers */
static void (*MTIMER1_pvOverflowCallBack)(void)  = NULL;
static void (*MTIMER1_pvCompareACallBack)(void)  = NULL;
static void (*MTIMER1_pvCompareBCallBack)(void)  = NULL;
static void (*MTIMER1_pvICUCallBack)(void)       = NULL;

void MTIMER1_voidInit(void)
{
    /* 1. Configure Waveform Generation Mode (WGM13:10) */
    #if TIMER1_MODE == TIMER1_NORMAL_MODE
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        /* Enable Overflow Interrupt */
        SET_BIT(TIMSK, TOIE1);

    #elif TIMER1_MODE == TIMER1_CTC_OCR1A_TOP
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        /* Enable Compare A Interrupt */
        SET_BIT(TIMSK, OCIE1A);

    #elif TIMER1_MODE == TIMER1_FAST_PWM_ICR1_TOP
        CLR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        /* Non-Inverting Mode on Channel A by default */
        SET_BIT(TCCR1A, COM1A1);
        CLR_BIT(TCCR1A, COM1A0);

    #elif TIMER1_MODE == TIMER1_FAST_PWM_10BIT
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        SET_BIT(TCCR1A, COM1A1);
        CLR_BIT(TCCR1A, COM1A0);
    #endif

    /* 2. Set Prescaler */
    TCCR1B &= 0xF8; // Clear bits CS12, CS11, CS10
    TCCR1B |= TIMER1_PRESCALER;
}

void MTIMER1_voidSetPreload(u16 A_u16PreloadValue)
{
    TCNT1 = A_u16PreloadValue;
}

void MTIMER1_voidSetCompareA(u16 A_u16CompareValue)
{
    OCR1A = A_u16CompareValue;
}

void MTIMER1_voidSetCompareB(u16 A_u16CompareValue)
{
    OCR1B = A_u16CompareValue;
}

void MTIMER1_voidSetICR1(u16 A_u16ICRValue)
{
    ICR1 = A_u16ICRValue;
}

u16 MTIMER1_u16GetTimerCounterValue(void)
{
    return TCNT1;
}

/* CallBack Registering Functions */
void MTIMER1_voidSetCallBackOverflow(void (*A_pvCallBackFunc)(void))
{
    if (A_pvCallBackFunc != NULL)
    {
        MTIMER1_pvOverflowCallBack = A_pvCallBackFunc;
    }
}

void MTIMER1_voidSetCallBackCompareA(void (*A_pvCallBackFunc)(void))
{
    if (A_pvCallBackFunc != NULL)
    {
        MTIMER1_pvCompareACallBack = A_pvCallBackFunc;
    }
}

void MTIMER1_voidSetCallBackCompareB(void (*A_pvCallBackFunc)(void))
{
    if (A_pvCallBackFunc != NULL)
    {
        MTIMER1_pvCompareBCallBack = A_pvCallBackFunc;
    }
}

void MTIMER1_voidSetCallBackICU(void (*A_pvCallBackFunc)(void))
{
    if (A_pvCallBackFunc != NULL)
    {
        MTIMER1_pvICUCallBack = A_pvCallBackFunc;
    }
}

/* ISRs (Interrupt Service Routines) */

/* Timer1 Capture Event ISR */
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
    if (MTIMER1_pvICUCallBack != NULL)
    {
        MTIMER1_pvICUCallBack();
    }
}

/* Timer1 Compare Match A ISR */
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
    if (MTIMER1_pvCompareACallBack != NULL)
    {
        MTIMER1_pvCompareACallBack();
    }
}

/* Timer1 Compare Match B ISR */
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
    if (MTIMER1_pvCompareBCallBack != NULL)
    {
        MTIMER1_pvCompareBCallBack();
    }
}

/* Timer1 Overflow ISR */
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    if (MTIMER1_pvOverflowCallBack != NULL)
    {
        MTIMER1_pvOverflowCallBack();
    }
}
