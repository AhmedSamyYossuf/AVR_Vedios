/*
 * Bit_Math.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Amr
 */

#ifndef NASR5_REPO_SRC_LIB_BIT_MATH_H_
#define NASR5_REPO_SRC_LIB_BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO) 		(VAR) |=  (1 << (BIT_NO))
#define CLEAR_BIT(VAR,BIT_NO) 		(VAR) &= ~(1 << (BIT_NO))
#define TOGGLE_BIT(VAR,BIT_NO) 		(VAR) ^=  (1 << (BIT_NO))
#define GET_BIT(VAR,BIT_NO) 		(((VAR) >> (BIT_NO)) & 0x01)

#endif /* NASR5_REPO_SRC_LIB_BIT_MATH_H_ */
