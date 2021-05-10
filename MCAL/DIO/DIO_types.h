/*
 * DIO_reg.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Amr
 */

#ifndef NASR5_REPO_SRC_MCAL_DIO_DIO_TYPES_H_
#define NASR5_REPO_SRC_MCAL_DIO_DIO_TYPES_H_

typedef enum
{
    DIO_Input, /* 0 */
    DIO_Output /* 1 */
} DIO_Direction;


typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
} DIO_PortType;

typedef enum
{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
} DIO_PinNumber;

#endif /* NASR5_REPO_SRC_MCAL_DIO_DIO_TYPES_H_ */
