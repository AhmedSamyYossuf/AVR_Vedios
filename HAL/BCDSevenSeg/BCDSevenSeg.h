/*
 * BCDSevenSeg.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Amr
 */

#ifndef SRC_HAL_BCDSEVENSEG_BCDSEVENSEG_H_
#define SRC_HAL_BCDSEVENSEG_BCDSEVENSEG_H_

#include "../../MCAL/DIO/DIO.h"

typedef enum
{
	Left7Seg,
	Right7Seg
} BCDSevenSegment_Pos;

/* Function to initialize 7Segment component */
void BCDSevenSegment_Initialization(void);

/* Function to write a number on one of the 7 segments */
void BCDSevenSegment_WriteNumberAndSelect(uint8 Value, BCDSevenSegment_Pos Select7Seg);
/* Function to write a number on 7 segment */
void BCDSevenSegment_WriteNumber(uint8 Value , float delay_sec);
/* Function to enable 7segment 1 */
void BCDSevenSegment_Enable1(void);
/* Function to enable 7segment 2 */
void BCDSevenSegment_Enable2(void);
/* Function to disable 7segment 1 */
void BCDSevenSegment_Disable1(void);
/* Function to disable 7segment 2 */
void BCDSevenSegment_Disable2(void);

#endif /* SRC_HAL_BCDSEVENSEG_BCDSEVENSEG_H_ */
