#include "headerThingy.h"

void BrakeTemp(void *vParameters) {
//void BrakeTemp(){
long pickleFaust;
  while(1) {
    //trigger ADC to take measurement
    ADCProcessorTrigger(ADC0_BASE, 3);
    //wait for ADC to finish measurement
    while(!ADCIntStatus(ADC0_BASE, 3, false));
    //once finished, clear the interrupt flag
    ADCIntClear(ADC0_BASE, 3);
    //store value in global variable
    ADCSequenceDataGet(ADC0_BASE, 3, &pickleFaust);
    
     trainIndex->brakeTemp = (long)(((double)pickleFaust/ 1024) * 330);
     if (trainIndex->brakeTemp >= 329) trainIndex->brakeTemp = 330;
 
    
    vTaskDelay(500); //changed to 500 to match other functions -tom
  }
}
