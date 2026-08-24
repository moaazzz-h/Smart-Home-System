/*
 * EXTI_PROGRM.c
 *
 *  Created on: Aug 23, 2026
 *      Author: HP
 */


//library Directives
#include <util/delay.h>
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// MCAL Directives
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/EXTI/EXTI_INTERFACE.h"
#include "../INCLUDE/MCAL/EXTI/EXTI_PRIVATE.h"
#include "../INCLUDE/MCAL/EXTI/EXTI_CFG.h"

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
