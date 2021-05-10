/*
 * SevenSeg_Lab.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Amr
 */

#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"

void SevenSeg(int x ,uint8 time_sec)
{
	/** Initialization */
	BCDSevenSegment_Initialization();

	/* Write 8 on 7segement*/


	BCDSevenSegment_WriteNumber( x , time_sec);


}

