/*
 * LCD_LAB.c
 *
 *  Created on: Aug 23, 2019
 *      Author: ahmed
 */
#include "../MCAL/DIO/DIO_types.h"
#include "../HAL/BCD_LCD/LCD.h"
#include <avr/delay.h>

//#include "../MCAL/DIO/DIO.h"
void lablcd(void){

	DIO_SetPortDirection(PORTA , DIO_Output);
	DIO_SetPortDirection(PORTB , DIO_Output);
	LCD_Initialize();

	uint8 pattern[8]  = {0x06, 0x04, 0x0E, 0x00, 0x04, 0x04, 0x04, 0x04}; // A
	uint8 pattern1[8] = {0x0F, 0x09, 0x01, 0x1F, 0x00, 0x00, 0x00, 0x00};//h
	uint8 pattern2[8] = {0x00, 0x00, 0x00, 0x1F, 0x0A, 0x0E, 0x00, 0x00};//m
	uint8 pattern3[8] = {0x02, 0x02, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00};//d
	LCD_StoreCustomChr(pattern  , 0 );
	LCD_StoreCustomChr(pattern1 , 1 );
	LCD_StoreCustomChr(pattern2 , 2 );
	LCD_StoreCustomChr(pattern3 , 3 );
	/*LCD_WriteString("ahmed Samy" , 0 , 10);
	LCD_WriteData('S');
	LCD_WriteData('A');
	LCD_WriteData('M');
	LCD_WriteData('Y');
	LCD_WriteData(' ');
	LCD_WriteData('9');
	LCD_WriteData('7');
	LCD_WriteData(' ');*/
	uint8 index = 0;
	uint8 row = 0;
	while (1){
		LCD_WriteCmd(0x01);
		LCD_DisplayCustomChr(3 , row , index++);
		LCD_DisplayCustomChr(2 , row , index++);
		LCD_DisplayCustomChr(1 , row , index++);
		LCD_DisplayCustomChr(0 , row , index++);
		if (row == 0){
			row =1;
			if (index ==16){
				index = 0 ;
			}
		}else if(row == 1){
			row = 0 ;
			if (index ==16){
				index = 0 ;
			}
		}
		_delay_ms(1000);
	}
}

