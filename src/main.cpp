#include <Arduino.h>
#include <STM32FreeRTOS.h>
#include "segment.h"

void TaskAMP_Read( void *pvParameters );
void TaskV5_Read( void *pvParameters );
void TaskV12_Read( void *pvParameters );



int AMP_Pins[] = {AMP_A, AMP_B, AMP_C, AMP_D, AMP_DP};
int AMP_digit[] = {AMP_D1, AMP_D2, AMP_D3};     
int V5_Pins[] = {V5_A, V5_B, V5_C, V5_D, V5_DP}; 
int V5_digit[] = {V5_D1, V5_D2, V5_D3};      
int V12_Pins[] = {V12_A, V12_B, V12_C, V12_D, V12_DP};
int V12_digit[] = {V12_D1, V12_D2, V12_D3};         

SevenSegmentDisplay displayAMP(AMP_Pins, AMP_digit);
SevenSegmentDisplay displayV5(V5_Pins, V5_digit);
SevenSegmentDisplay displayV12(V12_Pins, V12_digit);

void setup() {
   displayAMP.begin();
   displayV5.begin();
   displayV12.begin();
    xTaskCreate(TaskAMP_Read, "TaskAMP_Read", 128, NULL, 1, NULL);
    xTaskCreate(TaskV5_Read, "TaskV5_Read", 128, NULL, 1, NULL);
    xTaskCreate(TaskV12_Read, "TaskV12_Read", 128, NULL, 1, NULL);
    vTaskStartScheduler();
}

void loop() {
}

void TaskAMP_Read( void *pvParameters ) {
  (void) pvParameters;
  for (;;) {
    int adcValue = analogRead(AMP_SNS);
    float voltage = (adcValue * 125) / 1023.0f;
    int milliVolts = round(voltage);
    displayAMP.displayNumber(milliVolts, false, false, false);
    vTaskDelay(5);
  }
}
void TaskV5_Read( void *pvParameters ) {
  (void) pvParameters;
  for (;;) {
    int adcValue = analogRead(V5_SNS);
    float voltage = (adcValue * 5) / 1023.0f;
    int milliVolts = round(voltage * 10);
    displayV12.displayNumber(milliVolts, false, true, false);
    vTaskDelay(5);
  }
}
void TaskV12_Read( void *pvParameters ) {
  (void) pvParameters;
  for (;;) {
    int adcValue = analogRead(V12_SNS);
    float voltage = (adcValue * 12) / 1023.0f;
    int milliVolts = round(voltage * 10);
    displayV12.displayNumber(milliVolts, false, true, false);
    vTaskDelay(5);
  }
}


