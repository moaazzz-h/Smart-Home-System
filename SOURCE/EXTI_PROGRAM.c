/*

 * EXTI_PROGRAM.c
 *
 *  Created on: Aug 23, 2026
 *      Author: DELL
 */

#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// EXTI Directives

#include "../INCLUDE/MCAL/EXTI/EXTI_INTERFACE.h"
#include "../INCLUDE/MCAL/EXTI/EXTI_PRIVATE.h"
#include "../INCLUDE/MCAL/EXTI/EXTI_CFG.h"

void (*EXTI0_CallBack)(void) = NULL;
void (*EXTI1_CallBack)(void) = NULL;
void (*EXTI2_CallBack)(void) = NULL;

void MEXTI_voidConfig (EXTI_ID A_EXTI_ID, EXTI_SENSE_MODE A_EXTI_SENSE_MODE)
{
    if((A_EXTI_ID <= EXTI2) && (A_EXTI_SENSE_MODE <= RISING))
    {
    	switch(A_EXTI_ID){
    	case EXTI0:
    		MCUCR &= ~(SENSE_MODE_MASK << EXTI0_SENSE_MODE_BITS);
    		MCUCR |= (A_EXTI_SENSE_MODE << EXTI0_SENSE_MODE_BITS);
    		break ;
    	case EXTI1:
    		MCUCR &= ~(SENSE_MODE_MASK << EXTI1_SENSE_MODE_BITS);
    		MCUCR |= (A_EXTI_SENSE_MODE << EXTI1_SENSE_MODE_BITS);
    		break ;
    	case EXTI2:
    		switch(A_EXTI_SENSE_MODE){
    		case FALLING: CLR_BIT(MCUCSR, EXTI2_SENSE_MODE_BITS); break;
    		case RISING: SET_BIT(MCUCSR, EXTI2_SENSE_MODE_BITS); break;
    		}
    		break ;
    	}
    }
}

void MEXTI_VoidEnable(EXTI_ID A_EXTI_ID){
	if(A_EXTI_ID <= EXTI2){
		switch(A_EXTI_ID){
		case EXTI0: SET_BIT(GICR,EXTI0_ENABLE_BIT); break;
		case EXTI1: SET_BIT(GICR,EXTI1_ENABLE_BIT); break;
		case EXTI2: SET_BIT(GICR,EXTI2_ENABLE_BIT); break;
		}
	}
}

void MEXTI_VoidDisable(EXTI_ID A_EXTI_ID){
	if(A_EXTI_ID <= EXTI2){
		switch(A_EXTI_ID){
		case EXTI0: CLR_BIT(GICR,EXTI0_ENABLE_BIT); break;
		case EXTI1: CLR_BIT(GICR,EXTI1_ENABLE_BIT); break;
		case EXTI2: CLR_BIT(GICR,EXTI2_ENABLE_BIT); break;
		}
	}
}

void MEXTI_VoidClearFlag(EXTI_ID A_EXTI_ID){
	if(A_EXTI_ID <= EXTI2){
		switch(A_EXTI_ID){
		case EXTI0: SET_BIT(GIFR,EXTI0_FLAG_BIT); break;
		case EXTI1: SET_BIT(GIFR,EXTI1_FLAG_BIT); break;
		case EXTI2: SET_BIT(GIFR,EXTI2_FLAG_BIT); break;
		}
	}
}



void MEXTI_VoidSetCallBack(EXTI_ID A_EXTI_ID, void(*ptrToFunc)(void)){
	if(A_EXTI_ID <= EXTI2  && ptrToFunc != NULL){
			switch(A_EXTI_ID){
			case EXTI0:EXTI0_CallBack= ptrToFunc; break;
			case EXTI1:EXTI1_CallBack= ptrToFunc; break;
			case EXTI2:EXTI2_CallBack= ptrToFunc; break;
			}
		}


}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(EXTI0_CallBack != NULL)
    {
        EXTI0_CallBack();
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if(EXTI1_CallBack != NULL)
    {
        EXTI1_CallBack();
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if(EXTI2_CallBack != NULL)
    {
        EXTI2_CallBack();
    }
}
