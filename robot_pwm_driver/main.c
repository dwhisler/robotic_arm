/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/******************************************************************************
 * MSP432 Empty Project
 *
 * Description: An empty project that uses DriverLib
 *
 *                MSP432P401
 *             ------------------
 *         /|\|                  |
 *          | |                  |
 *          --|RST               |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 * Author:
*******************************************************************************/
/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>


//*****************************************************************************
//
// Definitions
//
//*****************************************************************************
#define EUSCI_I2C_STATUS_SLAVE_NACK       1

/* EUSCI port and pin selection */
#define EUSCI_I2C_MODULE                  EUSCI_B0_BASE
#define EUSCI_I2C_PORT                    GPIO_PORT_P1
#define EUSCI_I2C_SCL_PIN                 GPIO_PIN7
#define EUSCI_I2C_SDA_PIN                 GPIO_PIN6

#define PCA9685_ADDR                      0x40

#define MODE1                             0x00
#define LED0_ON_L                         0x06

#define MODE1_RESET                       0x80
#define MODE1_TURN_ON                     0x01
#define MODE1_SLEEP                       0x11

#define PRESCALE                          0xFE
#define PRESCALE_50HZ                     0x79

//*****************************************************************************
//
// Global Data
//
//*****************************************************************************
/* I2C Master Configuration Parameter */
const eUSCI_I2C_MasterConfig i2cConfig =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        3000000,
        EUSCI_B_I2C_SET_DATA_RATE_100KBPS,      // Desired I2C Clock of 400khz
        0,                                      // No byte counter threshold
        EUSCI_B_I2C_NO_AUTO_STOP
};





//*****************************************************************************
//
// Imported Data
//
//*****************************************************************************

//*****************************************************************************
//
// Constants
//
//*****************************************************************************

const eUSCI_UART_Config uartConfig =
{
        EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        78,                                     // BRDIV = 78
        2,                                       // UCxBRF = 2
        0,                                       // UCxBRS = 0
        EUSCI_A_UART_NO_PARITY,                  // No Parity
        EUSCI_A_UART_LSB_FIRST,                  // LSB First
        EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
        EUSCI_A_UART_MODE,                       // UART mode
        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
};


static volatile uint8_t uart_data[10] = {0,0,0,0,0,0,0,0,0,0};
static volatile uint8_t uart_bytecount = 0;


//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************

/***********************************************************
  Function:
*/

void initUART(void)
{
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);
    MAP_UART_initModule(EUSCI_A0_BASE, &uartConfig);
    MAP_UART_enableModule(EUSCI_A0_BASE);

    /* Enabling interrupts */
    MAP_UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA0);
    MAP_Interrupt_enableSleepOnIsrExit();
    MAP_Interrupt_enableMaster();
}

void initI2C(void)
{
//    /* I2C Clock Source Speed */
//    i2cConfig.i2cClk = MAP_CS_getSMCLK();

    /* Select I2C function for I2C_SCL & I2C_SDA */
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(EUSCI_I2C_PORT, EUSCI_I2C_SCL_PIN, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(EUSCI_I2C_PORT, EUSCI_I2C_SDA_PIN, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Initializing I2C Master to SMCLK at 100kbs with no-autostop */
    MAP_I2C_initMaster(EUSCI_I2C_MODULE, &i2cConfig);

    /* Set slave address for I2C */
    MAP_I2C_setSlaveAddress(EUSCI_I2C_MODULE, PCA9685_ADDR);

    /* Enable I2C Module to start operations */
    MAP_I2C_enableModule(EUSCI_I2C_MODULE);
}

void writeI2C(uint8_t reg, uint8_t data)
{
    MAP_I2C_masterSendMultiByteStart(EUSCI_I2C_MODULE, reg);
    MAP_I2C_masterSendMultiByteNext(EUSCI_I2C_MODULE, data);
    MAP_I2C_masterSendMultiByteStop(EUSCI_I2C_MODULE);
}

void writePWM(uint8_t port, uint16_t on, uint16_t off)
{
//    if (off > 500)
//    {
//        off = 500;
//    }
//    if (off < 90)
//    {
//        off = 90;
//    }

    if (port <= 15)
    {
        writeI2C(LED0_ON_L + 4*port, (uint8_t) on);
        writeI2C(LED0_ON_L + 4*port + 1, (uint8_t) (on>>8) & 0x0F);
        writeI2C(LED0_ON_L + 4*port + 2, (uint8_t) off);
        writeI2C(LED0_ON_L + 4*port + 3, (uint8_t) (off>>8) & 0x0F);
    }
}


int main(void)
{
    uint8_t pwm_port = 0;
    uint16_t pwm_duty = 0;

    /* Halting WDT  */
    MAP_WDT_A_holdTimer();

    initI2C();

    writeI2C(MODE1, MODE1_SLEEP);
    writeI2C(PRESCALE, PRESCALE_50HZ);
    writeI2C(MODE1, MODE1_TURN_ON);
    writePWM(15, 0, 400);

    initUART();

    while(1)
    {
        pwm_port = (uart_data[0]-48)*10 + (uart_data[1]-48);
        pwm_duty = (uart_data[2]-48)*1000 + (uart_data[3]-48)*100 + (uart_data[4]-48)*10 + (uart_data[5]-48);

        writePWM(pwm_port, 0, pwm_duty);

        MAP_Interrupt_enableSleepOnIsrExit();
        MAP_PCM_gotoLPM0InterruptSafe();
    }
}

void EUSCIA0_IRQHandler(void)
{
    uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A0_BASE);

    MAP_UART_clearInterruptFlag(EUSCI_A0_BASE, status);

    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        if(uart_bytecount == 5)
        {
            uart_data[uart_bytecount] = MAP_UART_receiveData(EUSCI_A0_BASE);
            uart_bytecount = 0;
            MAP_Interrupt_disableSleepOnIsrExit();
        }
        else
        {
            uart_data[uart_bytecount++] = MAP_UART_receiveData(EUSCI_A0_BASE);
        }
    }
}

