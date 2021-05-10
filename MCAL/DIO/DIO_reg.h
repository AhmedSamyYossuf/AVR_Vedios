/*
 * DIO_reg.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Amr
 */

#ifndef NASR5_REPO_SRC_MCAL_DIO_DIO_REG_H_
#define NASR5_REPO_SRC_MCAL_DIO_DIO_REG_H_

#include "../../LIB/std_types.h"

// Define registers for portA
#define DDRA_Reg 		(*( (volatile uint8*) 0x3A) )
#define PORTA_Reg 		(*( (volatile uint8*) 0x3B) )
#define PINA_Reg		(*( (volatile uint8*) 0x39) )

// Define registers for portB
#define DDRB_Reg 		(*( (volatile uint8*) 0x37) )
#define PORTB_Reg 		(*( (volatile uint8*) 0x38) )
#define PINB_Reg		(*( (volatile uint8*) 0x36) )

// Define registers for portC
#define DDRC_Reg 		(*( (volatile uint8*) 0x34) )
#define PORTC_Reg 		(*( (volatile uint8*) 0x35) )
#define PINC_Reg		(*( (volatile uint8*) 0x33) )

// Define register for portD
#define DDRD_Reg 		(*( (volatile uint8*) 0x31) )
#define PORTD_Reg 		(*( (volatile uint8*) 0x32) )
#define PIND_Reg		(*( (volatile uint8*) 0x30) )

#endif /* NASR5_REPO_SRC_MCAL_DIO_DIO_REG_H_ */
