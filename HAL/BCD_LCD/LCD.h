/*
 * LCD.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Amr
 */

#ifndef SRC_HAL_LCD_LCD_H_
#define SRC_HAL_LCD_LCD_H_

#include "../../LIB/std_types.h"

void LCD_Initialize(void);
void LCD_WriteData(uint8 Data);
void LCD_WriteCmd(uint8 Cmd);
void LCD_GoToPos(uint8 Row, uint8 Col);
void LCD_WriteString(uint8* Str, uint8 Row, uint8 Col);
void LCD_StoreCustomChr(uint8* Ptr2CustomChr, uint8 CGRAM_Index);
void LCD_DisplayCustomChr(uint8 CGRAM_Index, uint8 Row, uint8 Col);


#endif /* SRC_HAL_LCD_LCD_H_ */
