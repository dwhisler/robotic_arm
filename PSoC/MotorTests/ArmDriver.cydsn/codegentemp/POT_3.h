/*******************************************************************************
* File Name: POT_3.h  
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

#if !defined(CY_PINS_POT_3_H) /* Pins POT_3_H */
#define CY_PINS_POT_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "POT_3_aliases.h"


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
} POT_3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   POT_3_Read(void);
void    POT_3_Write(uint8 value);
uint8   POT_3_ReadDataReg(void);
#if defined(POT_3__PC) || (CY_PSOC4_4200L) 
    void    POT_3_SetDriveMode(uint8 mode);
#endif
void    POT_3_SetInterruptMode(uint16 position, uint16 mode);
uint8   POT_3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void POT_3_Sleep(void); 
void POT_3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(POT_3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define POT_3_DRIVE_MODE_BITS        (3)
    #define POT_3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - POT_3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the POT_3_SetDriveMode() function.
         *  @{
         */
        #define POT_3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define POT_3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define POT_3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define POT_3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define POT_3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define POT_3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define POT_3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define POT_3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define POT_3_MASK               POT_3__MASK
#define POT_3_SHIFT              POT_3__SHIFT
#define POT_3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in POT_3_SetInterruptMode() function.
     *  @{
     */
        #define POT_3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define POT_3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define POT_3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define POT_3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(POT_3__SIO)
    #define POT_3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(POT_3__PC) && (CY_PSOC4_4200L)
    #define POT_3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define POT_3_USBIO_DISABLE              ((uint32)(~POT_3_USBIO_ENABLE))
    #define POT_3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define POT_3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define POT_3_USBIO_ENTER_SLEEP          ((uint32)((1u << POT_3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << POT_3_USBIO_SUSPEND_DEL_SHIFT)))
    #define POT_3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << POT_3_USBIO_SUSPEND_SHIFT)))
    #define POT_3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << POT_3_USBIO_SUSPEND_DEL_SHIFT)))
    #define POT_3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(POT_3__PC)
    /* Port Configuration */
    #define POT_3_PC                 (* (reg32 *) POT_3__PC)
#endif
/* Pin State */
#define POT_3_PS                     (* (reg32 *) POT_3__PS)
/* Data Register */
#define POT_3_DR                     (* (reg32 *) POT_3__DR)
/* Input Buffer Disable Override */
#define POT_3_INP_DIS                (* (reg32 *) POT_3__PC2)

/* Interrupt configuration Registers */
#define POT_3_INTCFG                 (* (reg32 *) POT_3__INTCFG)
#define POT_3_INTSTAT                (* (reg32 *) POT_3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define POT_3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(POT_3__SIO)
    #define POT_3_SIO_REG            (* (reg32 *) POT_3__SIO)
#endif /* (POT_3__SIO_CFG) */

/* USBIO registers */
#if !defined(POT_3__PC) && (CY_PSOC4_4200L)
    #define POT_3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define POT_3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define POT_3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define POT_3_DRIVE_MODE_SHIFT       (0x00u)
#define POT_3_DRIVE_MODE_MASK        (0x07u << POT_3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins POT_3_H */


/* [] END OF FILE */
