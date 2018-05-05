/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

char str[200];
int potVal;
int rawPotVal;
int servoDuty;
int potVal_1;
int rawPotVal_1;
int servoDuty_1;
float servoHighLimit = 4700;
float servoLowLimit = 4300;
float servoHighLimit_1 = 4670;
float servoLowLimit_1 = 4250;
float potHighLimit = 1300;
float potLowLimit = 0;
int first = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    
    // Start ADC for J1    
    ADC_Start();
    ADC_StartConvert(); //always poll ADC continuously
    
    // Start PWM for J1
    PWM_Start();
    // Start PWM for J2
    PWM_1_Start();
    //PWM_WritePeriod(65300u);
    //PWM_WriteCompare(32650u);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyDelay(500);
    UART_UartPutString("Servo Motor Test v1.0\r\n");
    UART_UartPutString("Author: Amar Bhatt\r\n\r\n");
    
    for(;;)
    {
        /* Place your application code here. */
        if(first == 1) {
            UART_UartPutString("\r\033[A\33[2K \r\033[A\33[2K \r\033[A\33[2K \r\033[A\33[2K \r");// \033[A\33[2K\r
        }
        rawPotVal = ADC_GetResult16(0);        
        if (rawPotVal < potLowLimit) {
            potVal = potLowLimit;
        } else if (rawPotVal > potHighLimit){
            potVal = potHighLimit;
        } else {
            potVal = rawPotVal;
        }      
        rawPotVal_1 = ADC_GetResult16(1);
        if (rawPotVal_1 < potLowLimit) {
            potVal_1 = potLowLimit;
        } else if (rawPotVal_1 > potHighLimit){
            potVal_1 = potHighLimit;
        } else {
            potVal_1 = rawPotVal_1;
        }  
        servoDuty = (potVal-potLowLimit)*((servoHighLimit-servoLowLimit)/(potHighLimit-potLowLimit)) + servoLowLimit;
        servoDuty_1 = (potVal_1-potLowLimit)*((servoHighLimit_1-servoLowLimit_1)/(potHighLimit-potLowLimit)) + servoLowLimit_1;
        // clear line
        
        sprintf(str,"\33[2K\rRaw POT Values: %d, %d\r\n\33[2K\rPOT Values: %d, %d\r\n\33[2K\rServo Duty Counts: %d, %d\r\n\33[2K\rServo Duty Values: %f%%, %f%%\r\n",rawPotVal,rawPotVal_1,potVal,potVal_1,servoDuty,servoDuty_1,100-(((float)servoDuty/(float)servoHighLimit)*100.0),100-(((float)servoDuty_1/(float)servoHighLimit_1)*100.0));
        //UART_UartPutString(str);
        //sprintf(str,"\33[2K\r POT Value: %d\r\n",potVal);
        //UART_UartPutString(str);
        //sprintf(str,"\33[2K\r Servo Duty Value: %d\r\n",servoDuty);
        //UART_UartPutString(str);
        //sprintf(str,"\33[2K\r Servo Duty Value: %f%%\r\n",100-(((float)servoDuty/(float)servoHighLimit)*100.0));
        UART_UartPutString(str);
        
        PWM_WriteCompare(servoDuty);
        PWM_1_WriteCompare(servoDuty_1);
        first = 1;
        CyDelay(100);
    }
}

/* [] END OF FILE */
