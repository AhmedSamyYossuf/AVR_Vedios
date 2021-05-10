/*
 * std_types.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Amr
 */

#ifndef NASR5_REPO_SRC_LIB_STD_TYPES_H_
#define NASR5_REPO_SRC_LIB_STD_TYPES_H_

typedef unsigned char	uint8;
typedef unsigned short 	uint16;
typedef unsigned int 	uint32;
typedef unsigned long 	uint64;

typedef signed char	 sint8;
typedef signed short sint16;
typedef signed int 	 sint32;
typedef signed long  sint64;

typedef enum
{
	STD_LOW, /* 0 */
	STD_HIGH /* 1 */
} STD_levelType;

#define NULL    0




#endif /* NASR5_REPO_SRC_LIB_STD_TYPES_H_ */
