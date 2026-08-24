/*
 * DIO_PROGRAM.c
 *
 *  Created on: Aug 18, 2026
 *      Author: HP
 */

//library Directives

#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// DIO Directives

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"

void MDIO_voidInit(void)
{
    DDRA_REG = CONC_BIT( PORTA_PIN7_DIRECTION,PORTA_PIN6_DIRECTION,
                         PORTA_PIN5_DIRECTION,PORTA_PIN4_DIRECTION,
                         PORTA_PIN3_DIRECTION,PORTA_PIN2_DIRECTION,
                         PORTA_PIN1_DIRECTION,PORTA_PIN0_DIRECTION);

    DDRB_REG = CONC_BIT( PORTB_PIN7_DIRECTION,PORTB_PIN6_DIRECTION,
                         PORTB_PIN5_DIRECTION,PORTB_PIN4_DIRECTION,
                         PORTB_PIN3_DIRECTION,PORTB_PIN2_DIRECTION,
                         PORTB_PIN1_DIRECTION,PORTB_PIN0_DIRECTION);

    DDRC_REG = CONC_BIT( PORTC_PIN7_DIRECTION,PORTC_PIN6_DIRECTION,
                         PORTC_PIN5_DIRECTION,PORTC_PIN4_DIRECTION,
                         PORTC_PIN3_DIRECTION,PORTC_PIN2_DIRECTION,
                         PORTC_PIN1_DIRECTION,PORTC_PIN0_DIRECTION);

    DDRD_REG = CONC_BIT( PORTD_PIN7_DIRECTION,PORTD_PIN6_DIRECTION,
                         PORTD_PIN5_DIRECTION,PORTD_PIN4_DIRECTION,
                         PORTD_PIN3_DIRECTION,PORTD_PIN2_DIRECTION,
                         PORTD_PIN1_DIRECTION,PORTD_PIN0_DIRECTION);

    PORTA_REG = CONC_BIT( PORTA_PIN7_VALUE, PORTA_PIN6_VALUE,
                          PORTA_PIN5_VALUE, PORTA_PIN4_VALUE,
                          PORTA_PIN3_VALUE, PORTA_PIN2_VALUE,
                          PORTA_PIN1_VALUE, PORTA_PIN0_VALUE );

    PORTB_REG = CONC_BIT( PORTB_PIN7_VALUE, PORTB_PIN6_VALUE,
                          PORTB_PIN5_VALUE, PORTB_PIN4_VALUE,
                          PORTB_PIN3_VALUE, PORTB_PIN2_VALUE,
                          PORTB_PIN1_VALUE, PORTB_PIN0_VALUE );

    PORTC_REG = CONC_BIT( PORTC_PIN7_VALUE, PORTC_PIN6_VALUE,
                          PORTC_PIN5_VALUE, PORTC_PIN4_VALUE,
                          PORTC_PIN3_VALUE, PORTC_PIN2_VALUE,
                          PORTC_PIN1_VALUE, PORTC_PIN0_VALUE );

    PORTD_REG = CONC_BIT( PORTD_PIN7_VALUE, PORTD_PIN6_VALUE,
                          PORTD_PIN5_VALUE, PORTD_PIN4_VALUE,
                          PORTD_PIN3_VALUE, PORTD_PIN2_VALUE,
                          PORTD_PIN1_VALUE, PORTD_PIN0_VALUE );


}

void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN,PIN_DIRECTION A_PinDirection){
    if((A_DIOPORT <= PORTD) && (A_DIOPIN <= PIN7) && (A_PinDirection <= DIO_OUTPUT))
    {
        switch(A_DIOPORT)
        {
            case PORTA:
            	switch(A_PinDirection){
            	case DIO_OUTPUT: SET_BIT(DDRA_REG,A_DIOPIN); break ;
            	case DIO_INPUT: CLR_BIT(DDRA_REG,A_DIOPIN); break ;
            	}

            break;

            case PORTB:
            	switch(A_PinDirection){
            	case DIO_OUTPUT: SET_BIT(DDRB_REG,A_DIOPIN); break ;
            	case DIO_INPUT: CLR_BIT(DDRB_REG,A_DIOPIN); break ;
            	}
            break;

            case PORTC:
            	switch(A_PinDirection){
            	case DIO_OUTPUT: SET_BIT(DDRC_REG,A_DIOPIN); break ;
            	case DIO_INPUT: CLR_BIT(DDRC_REG,A_DIOPIN); break ;
            	}
            break;

            case PORTD:
            	switch(A_PinDirection){
            	case DIO_OUTPUT: SET_BIT(DDRD_REG,A_DIOPIN); break ;
            	case DIO_INPUT: CLR_BIT(DDRD_REG,A_DIOPIN); break ;
            	}
            break;

            default: break ;

        }
    }
}

void MDIO_voidSetPinValue(DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN,PIN_STATUS A_PinValue){
    if((A_DIOPORT <= PORTD) && (A_DIOPIN <= PIN7) && (A_PinValue <= DIO_HIGH))
    {
        switch(A_DIOPORT)
        {
            case PORTA:
            	switch(A_PinValue){
            	case DIO_HIGH: SET_BIT(PORTA_REG,A_DIOPIN); break ;
            	case DIO_LOW: CLR_BIT(PORTA_REG,A_DIOPIN); break ;
            	}

            break;

            case PORTB:
            	switch(A_PinValue){
            	case DIO_HIGH: SET_BIT(PORTB_REG,A_DIOPIN); break ;
            	case DIO_LOW: CLR_BIT(PORTB_REG,A_DIOPIN); break ;
            	}
            break;

            case PORTC:
            	switch(A_PinValue){
            	case DIO_HIGH: SET_BIT(PORTC_REG,A_DIOPIN); break ;
            	case DIO_LOW: CLR_BIT(PORTC_REG,A_DIOPIN); break ;
            	}
            break;

            case PORTD:
            	switch(A_PinValue){
            	case DIO_HIGH: SET_BIT(PORTD_REG,A_DIOPIN); break ;
            	case DIO_LOW: CLR_BIT(PORTD_REG,A_DIOPIN); break ;
            	}
            break;

            default: break ;

        }
    }
}


void MDIO_voidTogglePinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN){
    if((A_DIOPORT <= PORTD) && (A_DIOPIN <= PIN7))
    {
        switch(A_DIOPORT)
        {
            case PORTA:
            TOGGLE_BIT(PORTA_REG,A_DIOPIN);
            break;

            case PORTB:
            TOGGLE_BIT(PORTB_REG,A_DIOPIN);
            break;

            case PORTC:
            TOGGLE_BIT(PORTC_REG,A_DIOPIN);
            break;

            case PORTD:
            TOGGLE_BIT(PORTD_REG,A_DIOPIN);
            break;

            default: break ;

        }
    }
}


void MDIO_voidSetPortDirection(DIO_PORTS A_DIOPORT, u8 A_u8PortDirection){
	if((A_DIOPORT <= PORTD) && (A_u8PortDirection <= DIO_OUTPUT)){
		switch(A_DIOPORT){
		case PORTA:
			SET_BYTE(PORTA_REG,A_u8PortDirection);
			break ;
		case PORTB:
			SET_BYTE(PORTB_REG,A_u8PortDirection);
			break ;
		case PORTC:
			SET_BYTE(PORTC_REG,A_u8PortDirection);
			break ;
		case PORTD:
			SET_BYTE(PORTD_REG,A_u8PortDirection);
			break ;
		default:
			break ;
		}}
}


void MDIO_voidSetPortValue(DIO_PORTS A_DIOPORT, u8 A_u8PortValue){
	if(A_DIOPORT <= PORTD){
		switch(A_DIOPORT){
		case PORTA:
			SET_BYTE(PORTA_REG,A_u8PortValue);
			break ;
		case PORTB:
			SET_BYTE(PORTB_REG,A_u8PortValue);
			break ;
		case PORTC:
			SET_BYTE(PORTC_REG,A_u8PortValue);
			break ;
		case PORTD:
			SET_BYTE(PORTD_REG,A_u8PortValue);
			break ;
		default:
			break ;
		}
	}
}

PIN_STATUS MDIO_PinstatusGetPinValue(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPIN)
{
    PIN_STATUS PIN_VALUE;
    if((A_DIOPort <= PORTD) && (A_DIOPIN <= PIN7) )
    {
        switch(A_DIOPort)
        {
            case PORTA: PIN_VALUE = GET_BIT(PINA_REG,A_DIOPIN);break;

            case PORTB: PIN_VALUE = GET_BIT(PINB_REG,A_DIOPIN);break;

            case PORTC: PIN_VALUE = GET_BIT(PINC_REG,A_DIOPIN);break;

            case PORTD: PIN_VALUE = GET_BIT(PIND_REG,A_DIOPIN);break;

            default: break;
        }
    }
    return PIN_VALUE;
}
