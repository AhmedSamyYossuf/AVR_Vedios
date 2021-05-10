/*
 * GIE.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_GIE_GIE_H_
#define SRC_MCAL_GIE_GIE_H_

#include "GIE_reg.h"
#include "GIE_types.h"

/* Function to enable global interrupt */
void GIE_Enable(void);

/* Function to disable global interrupt */
void GIE_Disable(void);

#endif /* SRC_MCAL_GIE_GIE_H_ */
