#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void MTIMER1_voidInit(void);
void MTIMER1_voidSetPreload(u16 A_u16PreloadValue);
void MTIMER1_voidSetCompareA(u16 A_u16CompareValue);
void MTIMER1_voidSetCompareB(u16 A_u16CompareValue);
void MTIMER1_voidSetICR1(u16 A_u16ICRValue);
u16  MTIMER1_u16GetTimerCounterValue(void);

/* CallBack Functions Registration */
void MTIMER1_voidSetCallBackOverflow(void (*A_pvCallBackFunc)(void));
void MTIMER1_voidSetCallBackCompareA(void (*A_pvCallBackFunc)(void));
void MTIMER1_voidSetCallBackCompareB(void (*A_pvCallBackFunc)(void));
void MTIMER1_voidSetCallBackICU(void (*A_pvCallBackFunc)(void));

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
