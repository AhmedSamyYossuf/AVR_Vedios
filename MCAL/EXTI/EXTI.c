/*
 * EXTI.c
 *
 *  Created on: Jan 30, 2021
 *      Author: ahmed
 */

#include "EXTI.h"

void (*CallBackPtr) (void) = NULL ;

/* Function to initialize external interrupt */
void EXTI_Initialization(void){
/**************** Clearing all source modes ********************/
/***************************************************************/
	/* Clear ISC bits for External Interrupt 0 in register MCUCR */
	/* Clear bit ISC00 */
	CLEAR_BIT(MCUCR_Reg,0);
	/* Clear bit ISC01 */
	CLEAR_BIT(MCUCR_Reg,1);
	/* Clear ISC bits for External Interrupt 1 in register MCUCR */
	/* Clear bit ISC10 */
	CLEAR_BIT(MCUCR_Reg,2);
	/* Clear bit ISC11 */
	CLEAR_BIT(MCUCR_Reg,3);
	/* Clear ISC bits for External Interrupt 2 in register MCUCSR */
	/* Clear bit ISC2 */
	CLEAR_BIT(MCUCSR_Reg,6);

/***************************************************************/

/************* Initializing Interrupt source mode **************/
/***************************************************************/
	/**** Setting EXTI INT0 Mode ****/
	#if 	EXTI0_MODE	== EXTI_Low_Level
		MCUCR_Reg |= EXTI_Low_Level ;
	#elif 	EXTI0_MODE	== EXTI_Any_logical_change
		MCUCR_Reg |= EXTI_Any_logical_change ;
	#elif 	EXTI0_MODE	== EXTI_Falling_Edge
		MCUCR_Reg |= EXTI_Falling_Edge ;
	#elif 	EXTI0_MODE	== EXTI_Rising_Edge
		MCUCR_Reg |= EXTI_Rising_Edge ;
	#endif

	/**** Setting EXTI INT1 Mode ****/
	#if 	EXTI1_MODE	== EXTI_Low_Level
		MCUCR_Reg |= (EXTI_Low_Level << 2 ) ;
	#elif 	EXTI1_MODE	== EXTI_Any_logical_change
		MCUCR_Reg |= (EXTI_Any_logical_change << 2 ) ;
	#elif 	EXTI1_MODE	== EXTI_Falling_Edge
		MCUCR_Reg |= ( EXTI_Falling_Edge << 2) ;
	#elif 	EXTI1_MODE	== EXTI_Rising_Edge
		MCUCR_Reg |= ( EXTI_Rising_Edge << 2 ) ;
	#endif

	/**** Setting EXTI INT2 Mode ****/
	#if 	EXTI2_MODE	== EXTI_INT2_Falling_Edge
		MCUCSR_Reg |= EXTI_INT2_Falling_Edge ;
		/* CLEAR_BIT(MCUCSR_Reg , 6 ); */
	#elif 	EXTI2_MODE	== EXTI_INT2_Rising_Edge
		MCUCSR_Reg |= EXTI_INT2_Rising_Edge ;
		/* SET_BIT(MCUCSR_Reg , 6 );*/
	#endif
/***************************************************************/

/*********** Initializing External Interrupts State ************/
/***************************************************************/
	/* Initialize the state of EXTI_INT0 */
	#if 	EXTI_INT0_INIT_STATE	== EXTI_Disable_State
		CLEAR_BIT(GICR_Reg , 6 );
	#elif 	EXTI_INT0_INIT_STATE	== EXTI_Enable_State
		 SET_BIT(GICR_Reg , 6 );
	#endif

	/* Initialize the state of EXTI_INT1 */
	#if 	EXTI_INT1_INIT_STATE	== EXTI_Disable_State
		CLEAR_BIT(GICR_Reg , 7 );
	#elif 	EXTI_INT1_INIT_STATE	== EXTI_Enable_State
		SET_BIT(GICR_Reg , 7 );
	#endif

	/* Initialize the state of EXTI_INT2 */
	#if 	EXTI_INT2_INIT_STATE	== EXTI_Disable_State
		CLEAR_BIT(GICR_Reg , 5 );
	#elif 	EXTI_INT2_INIT_STATE	== EXTI_Enable_State
		MCUCSR_Reg |= EXTI_INT2_Rising_Edge ;
		SET_BIT(GICR_Reg , 5 );*/
	#endif
/***************************************************************/

/**************** Clear Interrupt Flags ************************/
/***************************************************************/
	/* clear the interrupt flag for INT2 */
	SET_BIT(GIFR_Reg , 5);
	/* clear the interrupt flag for INT0 */
	SET_BIT(GIFR_Reg , 6);
	/* clear the interrupt flag for INT1 */
	SET_BIT(GIFR_Reg , 7);

}


/* Function to enable EXTI 0 ISR */
void EXTI_EnableInt0(void){
	SET_BIT(GICR_Reg,6);
}

/* Function to disable EXTI 0 ISR */
void EXTI_DisableInt0(void){
	CLEAR_BIT(GICR_Reg,6);
}

/* Call Back Function  */
void EXTI_SetCallback( void (*CopyFuncPtr) (void)){
	CallBackPtr = CopyFuncPtr;
}

void __vector_1(void) __attribute__((signal, used));
void __vector_1(void){
	if(CallBackPtr != NULL){
		CallBackPtr();
	}
}
/*12644 bytes*/
