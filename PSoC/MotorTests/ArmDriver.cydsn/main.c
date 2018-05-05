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

int potVal[4];
int rawPotVal[4];
int servoDuty[4];
int servoHighLimit[4] = {4700, 4670, 4900, 4900};
int servoLowLimit[4] = {4300,4250,4100,4100};
float servoDutyPer[4];
//int potVal;
//int rawPotVal;
//int servoDuty;
//int potVal_1;
//int rawPotVal_1;
//int servoDuty_1;
//float servoHighLimit = 4700;
//float servoLowLimit = 4300;
//float servoHighLimit_1 = 4670;
//float servoLowLimit_1 = 4250;
float potHighLimit = 1300;
float potLowLimit = 0;
int first = 0;
int i = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    
    // Start ADC    
    ADC_Start();
    ADC_StartConvert(); //always poll ADC continuously
    
    // Start PWM for J1
    PWM_1_Start();
    // Start PWM for J2
    PWM_2_Start();
    // Start PWM for J3
    PWM_3_Start();
    // Start PWM for J4
    PWM_4_Start();
    //PWM_WritePeriod(65300u);
    //PWM_WriteCompare(32650u);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyDelay(500);
    UART_UartPutString("Arm Test v1.0\r\n");
    UART_UartPutString("Author: Amar Bhatt\r\n\r\n");
    
    for(;;)
    {
        /* Place your application code here. */
        if(first == 1) {
            UART_UartPutString("\r\033[A\33[2K \r\033[A\33[2K \r\033[A\33[2K \r\033[A\33[2K \r");// \033[A\33[2K\r
        }
        // Read pot values for J1, J2, J3, J4
        rawPotVal[0] = ADC_GetResult16(0);
        rawPotVal[1] = ADC_GetResult16(1);  
        rawPotVal[2] = ADC_GetResult16(2);  
        rawPotVal[3] = ADC_GetResult16(3); 
        
        // Adjust based on min and max
        for(i = 0; i<4;i++){
            if (rawPotVal[i] < potLowLimit) {
                potVal[i] = potLowLimit;
            } else if (rawPotVal[i] > potHighLimit){
                potVal[i] = potHighLimit;
            } else {
                potVal[i] = rawPotVal[i];
            }       
        
        }
        
        //Find Servo Duty Count
        
        for (i=0;i<4;i++){
            servoDuty[i] = (potVal[i]-potLowLimit)*((servoHighLimit[i]-servoLowLimit[i])/(potHighLimit-potLowLimit)) + servoLowLimit[i];        
        }       
        
        //Find Servo Duty Percentage
        for (i=0;i<4;i++){
            servoDutyPer[i] = 100-(((float)servoDuty[i]/(float)servoHighLimit[i])*100.0);
        }
       
        // clear line
        
        sprintf(str,"\33[2K\rRaw POT Values: %d, %d, %d, %d\r\n\33[2K\rPOT Values: %d, %d, %d, %d\r\n\33[2K\rServo Duty Counts: %d, %d, %d, %d\r\n\33[2K\rServo Duty Values: %f%%, %f%%, %f%%, %f%%\r\n",\
            rawPotVal[0],rawPotVal[1],rawPotVal[2],rawPotVal[3],\
            potVal[0],potVal[1],potVal[2],potVal[3],\
            servoDuty[0],servoDuty[1],servoDuty[2],servoDuty[3],\
            servoDutyPer[0],servoDutyPer[1],servoDutyPer[2],servoDutyPer[3]);

        UART_UartPutString(str);
        
        PWM_1_WriteCompare(servoDuty[0]);
        PWM_2_WriteCompare(servoDuty[1]);
        PWM_3_WriteCompare(servoDuty[2]);
        PWM_4_WriteCompare(servoDuty[3]);
        first = 1;
        CyDelay(100);
    }
}

/* [] END OF FILE */
