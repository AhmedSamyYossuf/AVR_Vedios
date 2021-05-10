#include "../../LIB/Bit_Math.h"
#include "DIO.h"
#include "DIO_reg.h"

/* Function to set the direction of a port */
void DIO_SetPortDirection (DIO_PortType PortId, DIO_Direction PortDirection)
{
    /* Check if port direction is output */
    if( DIO_Output == PortDirection )
    {
        /* Set direction register for selected Port */
        switch(PortId)
        {
            /* DDR register = 0b 1111 1111 --> all pins in port are output */
            case    PORTA: DDRA_Reg = 0xFF; break;
            case    PORTB: DDRB_Reg = 0xFF; break;
            case    PORTC: DDRC_Reg = 0xFF; break;
            case    PORTD: DDRD_Reg = 0xFF; break;
            default: /* Wrong Port selected */ break;
        }
    }
    /* Check if port direction is input */
    else if (DIO_Input == PortDirection)
    {
        /* Set direction register for selected Port */
        switch(PortId)
        {
            /* DDR register = 0b 0000 0000 --> all pins in port are input */
            case PORTA: DDRA_Reg = 0x00;        break;
            case PORTC: DDRC_Reg = 0x00;        break;
            case PORTB: DDRB_Reg = 0x00;        break;
            case PORTD: DDRD_Reg = 0x00;        break;
            default: /* Wrong Port selected */  break;
        }
    }
}

/* Function to set the value of a port */
void DIO_SetPortValue (DIO_PortType PortId, uint8 PortValue)
{
    switch(PortId)
    {
        /* PORT register = portValue --> change value of port pins */
        case PORTA: PORTA_Reg = PortValue; break;
        case PORTB: PORTB_Reg = PortValue; break;
        case PORTC: PORTC_Reg = PortValue; break;
        case PORTD: PORTD_Reg = PortValue; break;
        default: /* Wrong Port selected */  break;
    }
}

/* Function to set direction of specific pin in a port */
void DIO_SetPinDirection (DIO_PortType PortId, DIO_PinNumber PinId, DIO_Direction PinDirection)
{
	if((PortId <= PORTD) && (PinId <= Pin7))
	{
		if(DIO_Output == PinDirection)
		{
			switch(PortId)
			{
				case PORTA: SET_BIT(DDRA_Reg, PinId); break;
				case PORTB: SET_BIT(DDRB_Reg, PinId); break;
				case PORTC: SET_BIT(DDRC_Reg, PinId); break;
				case PORTD: SET_BIT(DDRD_Reg, PinId); break;
			}
		}
		else if (DIO_Input == PinDirection)
		{
			switch(PortId)
			{
				case PORTA: CLEAR_BIT(DDRA_Reg, PinId); break;
				case PORTB: CLEAR_BIT(DDRB_Reg, PinId); break;
				case PORTC: CLEAR_BIT(DDRC_Reg, PinId); break;
				case PORTD: CLEAR_BIT(DDRD_Reg, PinId); break;
			}
		}
		else
		{
			/* Do nothing, wrong direction required */
		}
	}
	else
	{
		/* Do nothing, wrong port or pin selection */
	}
}

/* Function to set value of specific pin in a port */
void DIO_SetPinValue (DIO_PortType PortId, DIO_PinNumber PinId, STD_levelType PinValue)
{
	if((PortId <= PORTD) && (PinId <= Pin7))
	{
		if(STD_HIGH == PinValue)
		{
			switch(PortId)
			{
				case PORTA: SET_BIT(PORTA_Reg, PinId); break;
				case PORTB: SET_BIT(PORTB_Reg, PinId); break;
				case PORTC: SET_BIT(PORTC_Reg, PinId); break;
				case PORTD: SET_BIT(PORTD_Reg, PinId); break;
			}
		}
		else if (STD_LOW == PinValue)
		{
			switch(PortId)
			{
				case PORTA: CLEAR_BIT(PORTA_Reg, PinId); break;
				case PORTB: CLEAR_BIT(PORTB_Reg, PinId); break;
				case PORTC: CLEAR_BIT(PORTC_Reg, PinId); break;
				case PORTD: CLEAR_BIT(PORTD_Reg, PinId); break;
			}
		}
		else
		{
			/* Do nothing, wrong value required */
		}
	}
	else
	{
		/* Do nothing, wrong port or pin selection */
	}
}

/* Function to read value of specific pin in a port */
STD_levelType DIO_GetPinValue (DIO_PortType PortId, DIO_PinNumber PinId)
{
	uint8 PinValue = 0;
	if((PortId <= PORTD) && (PinId <= Pin7))
	{
		switch(PortId)
		{
			case PORTA: PinValue = GET_BIT(PINA_Reg, PinId); break;
			case PORTB: PinValue = GET_BIT(PINB_Reg, PinId); break;
			case PORTC: PinValue = GET_BIT(PINC_Reg, PinId); break;
			case PORTD: PinValue = GET_BIT(PIND_Reg, PinId); break;
		}
	}
	else
	{
		PinValue = 0xFF;
	}

	return PinValue;
}
