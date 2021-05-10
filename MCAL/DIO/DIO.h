#ifndef DIO_H
#define DIO_H

#include "../../LIB/std_types.h"
#include "DIO_types.h"

/* DIO Ports */

/* Function to set the direction of a port */
void DIO_SetPortDirection (DIO_PortType PortId , DIO_Direction PortDirection);

/* Function to set the value of a port */
void DIO_SetPortValue (DIO_PortType PortId, uint8 PortValue);

/** DIO Pins **/

/* Function to set direction of specific pin in a port */
void DIO_SetPinDirection (DIO_PortType PortId, DIO_PinNumber PinId, DIO_Direction PinDirection);

/* Function to set value of specific pin in a port */
void DIO_SetPinValue (DIO_PortType PortId, DIO_PinNumber PinId, STD_levelType PinValue);

/* Function to read value of specific pin in a port */
STD_levelType DIO_GetPinValue (DIO_PortType PortId, DIO_PinNumber PinId);




#endif
