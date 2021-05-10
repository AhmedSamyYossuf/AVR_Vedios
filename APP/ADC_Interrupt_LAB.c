/*
 * ADC_Interrupt_LAB.c
 *
 *  Created on: Feb 21, 2021
 *      Author: ahmed
 */

#include "../LIB/Bit_Math.h"
#include "../LIB/std_types.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCD_LCD/LCD.h"
#include "../MCAL/GIE/GIE.h"
#include <stdlib.h>
#include <util/delay.h>

void ADC_Convcomplete_ISR(void){
	uint16 value = ADC_GetResult();
	uint8 value_Str[10];
	itoa(value , value_Str , 10);
	LCD_WriteString("     " , 0 , 5);
	LCD_WriteString(value_Str , 0 , 5);
}

void ADC_interrupt_Lab(void){

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
	ADC_EnableInt();
	GIE_Enable();

	ADC_SetCallback(ADC_Convcomplete_ISR);

	ADC_StartConversion(ADC_Channel_1);

	while(1){

	}
}




