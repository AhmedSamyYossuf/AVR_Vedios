/*
 * EXTI_Config.h
 *
 *  Created on: Jan 30, 2021
 *      Author: ahmed
 */

#ifndef REPO_MCAL_EXTI_EXTI_CONFIG_H_
#define REPO_MCAL_EXTI_EXTI_CONFIG_H_

/* Configure the External interrupt 0 mode
 * Range:
 *
 * EXTI_Low_Level
 * EXTI_Any_logical_change
 * EXTI_Falling_Edge
 * EXTI_Rising_Edge
 *
 * */

#define EXTI0_MODE	EXTI_Falling_Edge

/* Configure the external interrupt 1 mode
 * Range:
 *
 * EXTI_Low_Level
 * EXTI_Any_logical_change
 * EXTI_Falling_Edge
 * EXTI_Rising_Edge
 *
 * */

#define EXTI1_MODE	EXTI_Falling_Edge

/* Configure the external interrupt 2 mode
 * Range:
 *
 * EXTI_INT2_Falling_Edge
 * EXTI_INT2_Rising_Edge
 *
 * */
#define EXTI2_MODE	EXTI_INT2_Falling_Edge

/* Configure the external interrupt initial state
 * Range:
 *
 * EXTI_Disable_State
 * EXTI_Enable_State
 *
 * */

#define EXTI_INT0_INIT_STATE	EXTI_Disable_State
#define EXTI_INT1_INIT_STATE	EXTI_Disable_State
#define EXTI_INT2_INIT_STATE	EXTI_Disable_State

#endif /* REPO_MCAL_EXTI_EXTI_CONFIG_H_ */
