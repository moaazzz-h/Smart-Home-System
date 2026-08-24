/*
 * EXTI_INTERFACE.h
 *
 *  Created on: Aug 23, 2026
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum {
	EXTI0 = 0 ,
	EXTI1,
	EXTI2
} EXTI_ID ;

typedef enum {
	LOW_LEVEL = 0 ,
	ON_CHANGE,
	FALLING,
	RISING
} EXTI_SENSE_MODE ;

void MEXTI_VoidEnable(EXTI_ID A_EXTI_ID);
void MEXTI_VoidDisable(EXTI_ID A_EXTI_ID);

void MEXTI_VoidClearFlag(EXTI_ID A_EXTI_ID);
void MEXTI_VoidConfig(EXTI_ID A_EXTI_ID,EXTI_SENSE_MODE A_EXTI_SENSE_MODE);

void MEXTI_VoidSetCallBack(EXTI_ID A_EXTI_ID, void(*ptrToFunc)(void));

#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
