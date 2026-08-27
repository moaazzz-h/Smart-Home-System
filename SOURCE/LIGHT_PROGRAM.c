/*
 * LIGHT_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: DELL
 */

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/LIGHT/LIGHT_INTERFACE.h"
#include "../INCLUDE/HAL/LIGHT/LIGHT_PRIVATE.h"
#include "../INCLUDE/HAL/LIGHT/LIGHT_CFG.h"

void HLIGHT_voidInit(void)
{
    MDIO_voidSetPinDirection(LIGHT_PORT, LIGHT_PIN, DIO_OUTPUT);
    MDIO_voidSetPinValue(LIGHT_PORT, LIGHT_PIN, DIO_LOW);
}

void HLIGHT_voidOn(void)
{
    MDIO_voidSetPinValue(LIGHT_PORT, LIGHT_PIN, DIO_HIGH);
}

void HLIGHT_voidOff(void)
{
    MDIO_voidSetPinValue(LIGHT_PORT, LIGHT_PIN, DIO_LOW);
}
