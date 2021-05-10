/*
 * ADC.c
 *
 *  Created on: Jan 20, 2021
 *      Author: ahmed
 */

#include "ADC.h"

static void(*ADC_CallBack)(void) = NULL ;

void ADC_Initialize(void){
/**************** Selecting voltage reference ******************/
	ADMUX_Reg &= ADC_VOLTAGE_REF_clr_msk ;
	ADMUX_Reg |= ADC_VOLTAGE_REF_SELECTOR_msk ;
/***************************************************************/

/******************** Selecting ADC Mode ***********************/
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
			SET_BIT(ADCSRA_Reg,5);
			SFIOR_Reg &= ADC_AUTO_TRIG_SRC_clr_msk ;
			SFIOR_Reg |= ADC_AUTO_TRIG_SRCE_SELECTOR;
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
			CLEAR_BIT(ADCSRA_Reg,5);
	#endif

/***************************************************************/

/******************* Selecting Adjustment **********************/
	#if  	ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED
			CLEAR_BIT(ADMUX_Reg,5);
	#elif  	ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTED
			SET_BIT(ADMUX_Reg,5);
	#endif
/***************************************************************/

/***************** Clearing Interrupt Flag *********************/
			SET_BIT(ADCSRA_Reg,4);
/***************************************************************/

/********************** Enabling ADC ***************************/
			SET_BIT(ADCSRA_Reg,7);
/***************************************************************/
}

void ADC_StartConversion(ADC_Channel_types ADC_channel){
	/***************** Select ADC Channel *******************/
	ADMUX_Reg &= ADC_CHANNEL_SELECTOR_clr_msk ;
	ADMUX_Reg |= ADC_channel ;
/***************************************************************/

	/***************** ADC Start Conversion *******************/
	SET_BIT(ADCSRA_Reg , 6);
}

uint16 ADC_GetResult(void){

	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
			return ADCLH_Reg;
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
			while( (GET_BIT(ADCSRA_Reg,6)) );
			return ADCLH_Reg;
	#endif
}


/* Function to Enable ISR */
void ADC_EnableInt(void){
	SET_BIT(ADCSRA_Reg , 3);
}

/* Function to disable ISR */
void ADC_DisableInt(void){
	CLEAR_BIT(ADCSRA_Reg , 3);
}

/* Call Back Function  */
void ADC_SetCallback( void (*CopyFuncPtr) (void)){
	ADC_CallBack = CopyFuncPtr ;
}

void __vector_16(void)  __attribute__((signal , used));
void __vector_16(void){
	if(ADC_CallBack != NULL){
		ADC_CallBack();
	}
}
