/*
 * ADC_LAB.c
 *
 *  Created on: Jan 24, 2021
 *      Author: ahmed
 */

/*
 * ADC => Channel
 * LCD
 * Button
 * DIO
 * */

#include "../LIB/Bit_Math.h"
#include "../LIB/std_types.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCD_LCD/LCD.h"
#include <stdlib.h>
#include <util/delay.h>

void ADC_Lab(void){

	uint16 value ;
	uint8 stringValue[8];
	/* LCD Pin*/
	DIO_SetPortDirection(PORTA , DIO_Output);
	DIO_SetPortDirection(PORTB , DIO_Output);
	/*resistance*/
	DIO_SetPinDirection(PORTA,Pin1,DIO_Input);
	/* Push button*/
	DIO_SetPinDirection(PORTD,Pin2,DIO_Input);

	ADC_Initialize();
	LCD_Initialize();

	STD_levelType CurrentState = STD_LOW;
	STD_levelType PreviousState= STD_LOW;

	while(1){
		CurrentState = DIO_GetPinValue(PORTD, Pin2);

		/*  button was just pressed */
		if(STD_HIGH == CurrentState && STD_LOW == PreviousState)
		{
			ADC_StartConversion(ADC_Channel_1);
			value = ADC_GetResult();
			itoa(value ,stringValue,10);
			LCD_WriteString(stringValue , 0 , 5);
		}
		/*  button was just released */
		else if(STD_LOW == CurrentState && STD_HIGH == PreviousState)
		{
			LCD_WriteString("     " , 0 , 5);
		}

		PreviousState = CurrentState;
	}
}

