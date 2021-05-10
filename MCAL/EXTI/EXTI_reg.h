/*
 * EXTI_reg.h
 *
 *  Created on: Jan 30, 2021
 *      Author: ahmed
 */

#ifndef REPO_MCAL_EXTI_EXTI_REG_H_
#define REPO_MCAL_EXTI_EXTI_REG_H_

/* Registers related to External Interrupt */
#define SREG_Reg	(*( (volatile uint8*) 0x5F) )
#define MCUCR_Reg	(*( (volatile uint8*) 0x55) )
#define MCUCSR_Reg	(*( (volatile uint8*) 0x54) )
#define GICR_Reg	(*( (volatile uint8*) 0x5B) )
#define GIFR_Reg	(*( (volatile uint8*) 0x5A) )


#endif /* REPO_MCAL_EXTI_EXTI_REG_H_ */
