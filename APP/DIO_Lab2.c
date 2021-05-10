/*
 * DIO_LAP2.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Amr
 */
/*
#include "../MCAL/DIO/DIO.h"

void DIO_LAP2(void)
{
	/* Check the switch (button2)[PIND2] if pressed --> turn on led0[PINC2]

	/* Initialization
	DIO_SetPortDirection(PORTA, DIO_Output);
	DIO_SetPortDirection(PORTB, DIO_Output);
	DIO_SetPortDirection(PORTC, DIO_Output);
	DIO_SetPortDirection(PORTD, DIO_Output);

	DIO_SetPinDirection(PORTD, Pin2, DIO_Input);
	DIO_SetPinDirection(PORTC, Pin2, DIO_Output);

	/** Logic

	STD_levelType CurrentState = STD_LOW;
	STD_levelType PreviousState= STD_LOW;

	while(1)
	{
		CurrentState = DIO_GetPinValue(PORTD, Pin2);

		/* Turn on led if button was just pressed
		if(STD_HIGH == CurrentState /*&& STD_LOW == PreviousState)
		{
			DIO_SetPinValue(PORTC, Pin2, STD_HIGH);
		}
		/* Turn off led if button was just released
		else if(STD_LOW == CurrentState/* && STD_HIGH == PreviousState)
		{
			DIO_SetPinValue(PORTC, Pin2, STD_LOW);
		}

		PreviousState = CurrentState;
	}
}
*/
