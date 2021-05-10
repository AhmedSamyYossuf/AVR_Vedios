/*
 * BCDSevenSeg.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Amr
 */
#include <avr/delay.h>
#include "../../LIB/Bit_Math.h"
#include "BCDSevenSeg.h"

/* Function to initialize 7Segment component */
void BCDSevenSegment_Initialization(void){
	/* Decoder inputs are set as output pins */
	DIO_SetPinDirection(PORTC,Pin7,DIO_Output); //D
	DIO_SetPinDirection(PORTC,Pin6,DIO_Output); //C
	DIO_SetPinDirection(PORTC,Pin5,DIO_Output); //B
	DIO_SetPinDirection(PORTC,Pin4,DIO_Output); //A

	/* Set direction for 7segment enable pins */
	DIO_SetPinDirection(PORTC,Pin3,DIO_Output); //DIP
	DIO_SetPinDirection(PORTC,Pin2,DIO_Output); //En 1
	DIO_SetPinDirection(PORTC,Pin1,DIO_Output); //En 2
}

/* Function to write a number on one of the 7 segments */
void BCDSevenSegment_WriteNumberAndSelect(uint8 Value, BCDSevenSegment_Pos Select7Seg)
{
	BCDSevenSegment_Disable1();
	BCDSevenSegment_Disable2();

	if(Value < 10)
	{
		/* Input Value to decoder (A, B, C, D) */
		/* Value of decoder input A */
		DIO_SetPinValue(PORTA, Pin4, GET_BIT(Value,0));
		/* Value of decoder input B */
		DIO_SetPinValue(PORTA, Pin5, GET_BIT(Value,1));
		/* Value of decoder input C */
		DIO_SetPinValue(PORTA, Pin6, GET_BIT(Value,2));
		/* Value of decoder input D */
		DIO_SetPinValue(PORTA, Pin7, GET_BIT(Value,3));

		switch(Select7Seg)
		{
		case Left7Seg:
			BCDSevenSegment_Enable1();
			break;
		case Right7Seg:
			BCDSevenSegment_Enable2();
		}
	}


}
/* Function to write a number on 7 segment */
void BCDSevenSegment_WriteNumber(uint8 Value , float delay_sec)
{
	uint8 SevenSegOne, SevenSegTwo;

	if (Value < 100){
		uint16 time = delay_sec*1000;

		/* 53 / 10 = 5 */
		SevenSegOne = Value / 10;
		/* 53 % 10 = 3*/
		SevenSegTwo = Value % 10;
		for (int x =0 ; x <= (time/20) ; x++){
			/* Disable seven segment 1 */
			BCDSevenSegment_Disable1();
			/* Disable seven segment 2 */
			BCDSevenSegment_Disable2();

			/* 5 --> 0b 0000 0101 (bit7 bit6 bit5  .. bit0) --> A = 1, B = 0, C = 1, D = 0 */
			/* Input Value to decoder (A, B, C, D) */
			/* Value of decoder input A */
			DIO_SetPinValue(PORTC, Pin4, GET_BIT(SevenSegOne,0));
			/* Value of decoder input B */
			DIO_SetPinValue(PORTC, Pin5, GET_BIT(SevenSegOne,1));
			/* Value of decoder input C */
			DIO_SetPinValue(PORTC, Pin6, GET_BIT(SevenSegOne,2));
			/* Value of decoder input D */
			DIO_SetPinValue(PORTC, Pin7, GET_BIT(SevenSegOne,3));

			/* Enable seven segment 1 */
			BCDSevenSegment_Enable1();

			/* 10 mSec delay */
			_delay_ms(10);

			/* Disable seven segment 1 */
			BCDSevenSegment_Disable1();

			/* 3 --> 0b 0000 0011 (bit7 bit6 bit5  .. bit0) --> A = 1, B = 1, C = 0, D = 0 */
			/* Input Value to decoder (A, B, C, D) */
			/* Value of decoder input A */
			DIO_SetPinValue(PORTC, Pin4, GET_BIT(SevenSegTwo,0));
			/* Value of decoder input B */
			DIO_SetPinValue(PORTC, Pin5, GET_BIT(SevenSegTwo,1));
			/* Value of decoder input C */
			DIO_SetPinValue(PORTC, Pin6, GET_BIT(SevenSegTwo,2));
			/* Value of decoder input D */
			DIO_SetPinValue(PORTC, Pin7, GET_BIT(SevenSegTwo,3));

			/* Enable seven segment 2 */
			BCDSevenSegment_Enable2();

			/* 10 mSec delay */
			_delay_ms(10);

		}

	}

}

/* Function to enable 7segment 1 */
void BCDSevenSegment_Enable1(void)
{
	/* PinB2 is High */
	DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
}

/* Function to disable 7segment 1 */
void BCDSevenSegment_Disable1(void)
{
	/* PinB2 is Low */
	DIO_SetPinValue(PORTC,Pin2,STD_LOW);
}
/* Function to enable 7segment 2 */
void BCDSevenSegment_Enable2(void)
{
	/* PinB1 is High */
	DIO_SetPinValue(PORTC,Pin1,STD_HIGH);
}

/* Function to disable 7segment 2 */
void BCDSevenSegment_Disable2(void)
{
	/* PinB1 is High */
	DIO_SetPinValue(PORTC,Pin1,STD_LOW);
}

