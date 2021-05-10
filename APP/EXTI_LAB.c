/*
 * EXTI_LAB.c
 *
 *  Created on: Feb 8, 2021
 *      Author: ahmed
 */

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/GIE/GIE.h"
#include <util/delay.h>

void EXTI0_ISR(void);

void EXTI_LAB(void){
	/* Initialization */
	/* Button 2 pin */
	DIO_SetPinDirection(PORTD,Pin2,DIO_Input);
	/* Buzzer pin */
	DIO_SetPinDirection(PORTA,Pin3,DIO_Output);
	/* Led2 pin */
	DIO_SetPinDirection(PORTD,Pin3,DIO_Output);

	EXTI_Initialization();
	EXTI_SetCallback(EXTI0_ISR);

	/* Enable PIE for INT0 */
	EXTI_EnableInt0();
	/* Enable global interrupt */
	GIE_Enable();



	while(1)
	{
		/* Toggle led */
		DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
		_delay_ms(100);
		DIO_SetPinValue(PORTD,Pin3,STD_LOW);
		_delay_ms(100);
	}
}

void EXTI0_ISR(void){
	DIO_SetPinValue(PORTA,Pin3,STD_HIGH);
	_delay_ms(500);
	DIO_SetPinValue(PORTA,Pin3,STD_LOW);
	_delay_ms(500);
}
