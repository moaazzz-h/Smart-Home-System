/*
 * GIE_PROGRAM.c
 *
 *  Created on: Aug 24, 2026
 *      Author: DELL
 */

#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// GIE Directives

#include "../INCLUDE/MCAL/GIE/GIE_INTERFACE.h"
#include "../INCLUDE/MCAL/GIE/GIE_PRIVATE.h"
#include "../INCLUDE/MCAL/GIE/GIE_CFG.h"

void MGIE_voidEnable (void){
	SET_BIT(SREG,GIE_IBIT_PIN);
}
void MGIE_voidDisable (void){
	CLR_BIT(SREG,GIE_IBIT_PIN);

}
