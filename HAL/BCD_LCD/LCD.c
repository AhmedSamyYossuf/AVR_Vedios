/*
 * LCD.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Amr
 */
/* Inclusion list */
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD_Config.h"
#include "LCD.h"
#include <util/delay.h>

/* Flag to indicate state of initialization step */
static uint8 InitStepFinished = 0;

void LCD_Initialize(void)
{
	/**** Initialization sequence for 4-bit mode ****/

	/****** Voltage settle delay ******/
	_delay_ms(35);
	/**********************************/

	/*********** Function Set *********/
	LCD_WriteCmd(0x20);
	LCD_WriteCmd(0x20);

	#if (FONT == FiveTimesSeven)
	/* enable LCD with 5*7 pixels configuration */
	/* 0b1000 0000 == <No. of lines><Font (5*7/5*10)> x x x x x x */
	LCD_WriteCmd(0x80);

	#elif (FONT == FiveTimesTen)
	/* enable LCD with 5*10 pixels configuration */
	/* 0b1100 0000 == <No. of lines><Font (5*7/5*10)> x x x x x x */
	LCD_WriteCmd(0xC0);
	#endif
	/**********************************/

	/**** Delay after Function Set ****/
	_delay_ms(1);
	/**********************************/

	/******* Display Control **********/
	LCD_WriteCmd(0x00);
	/* 0b 1111 0000 == 1 <Display ON/OFF> <Cursor ON/OFF> <Cursor Blink> x x x x */
	LCD_WriteCmd(0xC0);
	/**********************************/

	/** Delay after Display Control ***/
	_delay_ms(1);
	/**********************************/

	/********* Display Clear **********/
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x10);
	/**********************************/

	/**** Delay after Display Clear ***/
	_delay_ms(2);
	/**********************************/

	/* Raise flag to indicate initialization step is finished */
	InitStepFinished = 1;

}

void LCD_WriteData(uint8 Data)
{
	/* Select type of Data (RS) = Data to be displayed (RS = 1) */
	DIO_SetPinValue(PORTB, Pin1, STD_HIGH);

	/* Select operation (R/W) --> write operation (R/W = 0) */
	DIO_SetPinValue(PORTB, Pin2, STD_LOW);


	/* Write on data pins (D0 --> D7 in 8-bit mode)
	 * Write on data pins (D4 --> D7 in 4-bit mode) */
	/* Write Most significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(Data, 4));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(Data, 5));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(Data, 6));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(Data, 7));


	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 usec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);

	/* Write least significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(Data, 0));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(Data, 1));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(Data, 2));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(Data, 3));

	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 usec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);
}


void LCD_WriteCmd(uint8 Cmd)
{
	/* Select type of Data (RS) = command to be executed (RS = 0) */
	DIO_SetPinValue(PORTB, Pin1, STD_LOW);

	/* Select operation (R/W) --> write operation (R/W = 0) */
	DIO_SetPinValue(PORTB, Pin2, STD_LOW);


	/* Write on data pins (D0 --> D7 in 8-bit mode)
	 * Write on data pins (D4 --> D7 in 4-bit mode) */
	/* Write Most significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(Cmd, 4));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(Cmd, 5));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(Cmd, 6));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(Cmd, 7));

if(InitStepFinished)
{
	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 usec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);

	/* Write least significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(Cmd, 0));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(Cmd, 1));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(Cmd, 2));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(Cmd, 3));
}
	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 usec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);

	/* 2 msec delay for instruction execution time - to avoid checking the busy flag */
	_delay_ms(2);
}

void LCD_GoToPos(uint8 Row, uint8 Col)
{
	/* Move AC to selected position in DDRAM */
	/* Use command "Set DDRAM Address" */
	if (Row < 2 && Col < 16 ) {
		uint8 Address;
		Address = ((Row*0x40)+Col);
		SET_BIT(Address , 7 );
		LCD_WriteCmd(Address);
	}

}

void LCD_WriteString(uint8* Str, uint8 Row, uint8 Col)
{
	/* Move AC to selected position in DDRAM */
	LCD_GoToPos(Row , Col);
	short int index = 0 ;
	/* Write string */
	if (((sizeof(Str)/sizeof(uint8))+ ( ( Row * 16) + Col ) ) <= 32){
		for (short int i = (( Row * 16) + Col ) ;  Str[index] !='\0'  ;i++ ){
			if ((i < 16) && (Str[index] !='\0') ){
				LCD_WriteData(Str[index]);
				index++;
				if (i == 15){
					LCD_GoToPos(1 , 0);
				}
			}else if ((i  <= 32 )&&( i > 15 )&& (Str[index] !='\0' )){
				LCD_WriteData(Str[index]);
				index++;
			}
		}
	}

}

void LCD_StoreCustomChr(uint8* Ptr2CustomChr, uint8 CGRAM_Index)
{
	uint8 index;
	if(CGRAM_Index < 8)
	{
		/* Make AC points to CGRAM address*/
		/* Use command "Set CGRAM Address" */
		LCD_WriteCmd( ( 0x40 ) | ( CGRAM_Index * 8 ) );
		for(index = 0 ; index < 8 ; index++){
			LCD_WriteData(Ptr2CustomChr[index]);
		}
		/* Return to DDRAM */
		LCD_WriteCmd(0x02);

	}
}

void LCD_DisplayCustomChr(uint8 CGRAM_Index, uint8 Row, uint8 Col)
{
	/* Go to selected position */
	LCD_GoToPos(Row , Col);
	/* Write selected character from CGRAM */
	LCD_WriteData(CGRAM_Index);
}
