#include "headerThingy.h"

void SwitchConTCB(void *vParameters)
{
   xOLEDMessage waitingTrainDisplay;
  waitingTrainDisplay.pcMessage = "TRAIN WAITING!!";
  waitingTrainDisplay.ulX = 10;
  waitingTrainDisplay.ulY = 40;
  waitingTrainDisplay.brightness = 15;
  
  int randd = 0;
  
  while(1)
  {
    //check if another train is trying get through that intersection bro!
    if(TrainState != 0) {
     TaskResume(vTrainCom); 
    }
    
    
    TrainState = 0;
    if (trainCount >= 1) {
     
    
    randd = 0;
  //CASE 1
  //train just generated, gridlock is false
  if((trainCount >= 1) && firstCycle) {
    //startTime is logged as whatever current globalCount value is
    firstCycle = FALSE;
    startTime = globalCount;
    /********************************************************
    *
    *
    * LEGACY GRIDLOCK CODE, DO NOT USE (FOR BACKUP PURPOSES ONLY)
    *
    *
    //generate a localPtr->random number between -2 and 2
    /*randd = randomInteger(-2, 2);
    
    //if random number is less than 0, we have GRIDLOCK!
    //note: TRAIN MUST RUN AFTER GRIDLOCK FINISHES
    if(randd < 0) {
      gridlock = TRUE;
      gridlockTime = globalCount + (-12*randd);
      traversalTime = 6*(trainSize) +  gridlockTime;
    }
    //if random number is greater than 0, we have a train passing through!*/
         
    traversalTime = 6*(trainSize) + globalCount;
    
  }
  //CASE 2
  //gridlock is true
  if(trainCount > 1) {
    
    if (globalCount % 2 == 0)
      brightness = 15; 
    
    if (globalCount % 2 == 1)
      brightness = 0;
    
    xQueueSend( xOLEDQueue, &waitingTrainDisplay, 0 ); 
    
  }
  
  //CASE 3
  //train is present
  if(trainCount > 0) {
    if(globalCount >= traversalTime) {
      trainCount--;
      switchConComplete = TRUE;
      fromDirection = 'X';
      
      firstCycle = TRUE;
      
      PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, FALSE); //turn off sound
    }
  }
   
  
    }
    vTaskDelay(500);
}
}
