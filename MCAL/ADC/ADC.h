/*
 * ADC.h
 *
 *  Created on: Jan 20, 2021
 *      Author: ahmed
 */

#ifndef REPO_MCAL_ADC_ADC_H_
#define REPO_MCAL_ADC_ADC_H_

#include  "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"
#include "ADC_reg.h"
#include "ADC_types.h"
#include "ADC_config.h"

typedef enum {
	ADC_Channel_0, // 0 => 0b00000000
	ADC_Channel_1, // 1 => 0b00000001
	ADC_Channel_2, // 2 => 0b00000010
	ADC_Channel_3, // 3 => 0b00000011
	ADC_Channel_4, // 4
	ADC_Channel_5, // 5
	ADC_Channel_6, // 6
	ADC_Channel_7  // 7 => 0b00000111
}ADC_Channel_types;

void ADC_Initialize(void);

void ADC_StartConversion(ADC_Channel_types ADC_channel);

uint16 ADC_GetResult(void);

/* Function to Enable ISR */
void ADC_EnableInt(void);

/* Function to disable ISR */
void ADC_DisableInt(void);

/* Call Back Function  */
void ADC_SetCallback( void (*CopyFuncPtr) (void));


#endif /* REPO_MCAL_ADC_ADC_H_ */
