/*******************************************************************************
* File Name: servo_4.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_servo_4_ALIASES_H) /* Pins servo_4_ALIASES_H */
#define CY_PINS_servo_4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define servo_4_0			(servo_4__0__PC)
#define servo_4_0_PS		(servo_4__0__PS)
#define servo_4_0_PC		(servo_4__0__PC)
#define servo_4_0_DR		(servo_4__0__DR)
#define servo_4_0_SHIFT	(servo_4__0__SHIFT)
#define servo_4_0_INTR	((uint16)((uint16)0x0003u << (servo_4__0__SHIFT*2u)))

#define servo_4_INTR_ALL	 ((uint16)(servo_4_0_INTR))


#endif /* End Pins servo_4_ALIASES_H */


/* [] END OF FILE */
