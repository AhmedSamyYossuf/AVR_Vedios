/*
 * GIE.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */


#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"


#include "GIE.h"



/* Function to enable global interrupt */
void GIE_Enable(void)
{
	SET_BIT(SREG_Reg,GIE_ENABLE_BIT);
}

/* Function to disable global interrupt */
void GIE_Disable(void)
{
	CLEAR_BIT(SREG_Reg,GIE_ENABLE_BIT);
}
