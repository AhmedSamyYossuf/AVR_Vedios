/*
 * EXTI.h
 *
 *  Created on: Jan 30, 2021
 *      Author: ahmed
 */

#ifndef REPO_MCAL_EXTI_EXTI_H_
#define REPO_MCAL_EXTI_EXTI_H_

#include "EXTI_Config.h"
#include "EXTI_reg.h"
#include "EXTI_types.h"
#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"

/* Function to initialize external interrupt */
void EXTI_Initialization(void);

/* Function to enable EXTI 0 ISR */
void EXTI_EnableInt0(void);

/* Function to disable EXTI 0 ISR */
void EXTI_DisableInt0(void);

/* Call Back Function  */
void EXTI_SetCallback( void (*CopyFuncPtr) (void));

#endif /* REPO_MCAL_EXTI_EXTI_H_ */
