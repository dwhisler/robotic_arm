/*******************************************************************************
* File Name: servo.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_servo_H) /* Pins servo_H */
#define CY_PINS_servo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "servo_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} servo_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   servo_Read(void);
void    servo_Write(uint8 value);
uint8   servo_ReadDataReg(void);
#if defined(servo__PC) || (CY_PSOC4_4200L) 
    void    servo_SetDriveMode(uint8 mode);
#endif
void    servo_SetInterruptMode(uint16 position, uint16 mode);
uint8   servo_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void servo_Sleep(void); 
void servo_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(servo__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define servo_DRIVE_MODE_BITS        (3)
    #define servo_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - servo_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the servo_SetDriveMode() function.
         *  @{
         */
        #define servo_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define servo_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define servo_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define servo_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define servo_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define servo_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define servo_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define servo_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define servo_MASK               servo__MASK
#define servo_SHIFT              servo__SHIFT
#define servo_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in servo_SetInterruptMode() function.
     *  @{
     */
        #define servo_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define servo_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define servo_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define servo_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(servo__SIO)
    #define servo_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(servo__PC) && (CY_PSOC4_4200L)
    #define servo_USBIO_ENABLE               ((uint32)0x80000000u)
    #define servo_USBIO_DISABLE              ((uint32)(~servo_USBIO_ENABLE))
    #define servo_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define servo_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define servo_USBIO_ENTER_SLEEP          ((uint32)((1u << servo_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << servo_USBIO_SUSPEND_DEL_SHIFT)))
    #define servo_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << servo_USBIO_SUSPEND_SHIFT)))
    #define servo_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << servo_USBIO_SUSPEND_DEL_SHIFT)))
    #define servo_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(servo__PC)
    /* Port Configuration */
    #define servo_PC                 (* (reg32 *) servo__PC)
#endif
/* Pin State */
#define servo_PS                     (* (reg32 *) servo__PS)
/* Data Register */
#define servo_DR                     (* (reg32 *) servo__DR)
/* Input Buffer Disable Override */
#define servo_INP_DIS                (* (reg32 *) servo__PC2)

/* Interrupt configuration Registers */
#define servo_INTCFG                 (* (reg32 *) servo__INTCFG)
#define servo_INTSTAT                (* (reg32 *) servo__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define servo_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(servo__SIO)
    #define servo_SIO_REG            (* (reg32 *) servo__SIO)
#endif /* (servo__SIO_CFG) */

/* USBIO registers */
#if !defined(servo__PC) && (CY_PSOC4_4200L)
    #define servo_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define servo_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define servo_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define servo_DRIVE_MODE_SHIFT       (0x00u)
#define servo_DRIVE_MODE_MASK        (0x07u << servo_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins servo_H */


/* [] END OF FILE */
