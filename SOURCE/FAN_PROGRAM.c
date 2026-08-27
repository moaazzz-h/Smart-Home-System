/*
 * FAN_PROGRAM.c
 *
 *  Created on: Aug 27, 2026
 *      Author: DELL
 */

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/FAN/FAN_INTERFACE.h"
#include "../INCLUDE/HAL/FAN/FAN_PRIVATE.h"
#include "../INCLUDE/HAL/FAN/FAN_CFG.h"

void HFAN_voidInit(void)
{
    MDIO_voidSetPinDirection(FAN_PORT, FAN_PIN, DIO_OUTPUT);
    MDIO_voidSetPinValue(FAN_PORT, FAN_PIN, DIO_LOW);
}

void HFAN_voidOn(void)
{
    MDIO_voidSetPinValue(FAN_PORT, FAN_PIN, DIO_HIGH);
}

void HFAN_voidOff(void)
{
    MDIO_voidSetPinValue(FAN_PORT, FAN_PIN, DIO_LOW);
}
