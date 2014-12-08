#include "headerThingy.h"

void SwitchControl(void *vParameters)
{  
  xOLEDMessage clearScreen;
  clearScreen.pcMessage = "                ";
  clearScreen.ulX = 10;
  clearScreen.ulY = 40;
  clearScreen.brightness = 15;
 
  while(1) {
    TrainState = 0;
    
    if(trainIndex != &nullTrain) {
      if(globalCount >= trainIndex->traversalTime) {
        trainIndex->present = FALSE;
        trainIndex->fromDirection = NONE;
        trainIndex->toDirection = NONE;
        trainIndex->size = NONE;
        trainIndex->traversalTime = NONE;
        trainIndex->passengerCount = NONE;
        
        trackOverload = FALSE;
        
        if(trainIndex == &train1) {
          if(train2.present) {
            trainIndex = &train2;
            trainIndex->traversalTime = 6000*(trainIndex->size) + globalCount;
          }
          else {
            trainIndex = &nullTrain;
          }
        }        
        else if(trainIndex == &train2) {
          if(train1.present) {
            trainIndex = &train1;
            trainIndex->traversalTime = 6000*(trainIndex->size) + globalCount;
          }
          else {
            trainIndex = &nullTrain;
          }
        }
        
        outputSetup = FALSE;
      }      
    }
    vTaskDelay(500);
  }  
}
