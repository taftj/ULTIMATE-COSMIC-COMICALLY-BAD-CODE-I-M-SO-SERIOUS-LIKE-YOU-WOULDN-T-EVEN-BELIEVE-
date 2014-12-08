#include "headerThingy.h"
void TrainCom(void *vParameters)
{     
  static unsigned int direction;
  static unsigned int priority;
  double crapes = 0.0;
  unsigned int bullshit = 0;
  priority = 0;
  
  while(1)
  {       
    //if train is added,
    if ((TrainState == 1 || TrainState == 2 || TrainState == 4 || TrainState == 8)) {
      //if train1 is not present,
      if(!train1.present) {
        //point to train1
        trainIndex = &train1;
      
        if(train2.present)
          priority = 2;
        else
          priority = 1;
      }
      //otherwise, if train2 is not present,
      else if(!train2.present) {
        //point to train2
        trainIndex = &train2;
      
        if(train1.present)
          priority = 1;
        else
          priority = 2;
      }
      //otherwise, if BOTH trains are present,
      else
        //throw a "track overload" flag
        trackOverload = TRUE;
      
      //if the tracks are not overloaded,
      if(!trackOverload && trainIndex != &nullTrain) {   
        //step 1: set the train currently being pointed to as present
        trainIndex->present = TRUE;
        
        //step 2: set the "from" direction
        if (TrainState == 1) {
          trainIndex->fromDirection = NORTH;
        } else if (TrainState == 2) {
          trainIndex->fromDirection = SOUTH;
        } else if (TrainState == 4) {
          trainIndex->fromDirection = WEST;
        } else {
          trainIndex->fromDirection = EAST;
        }
               
        //step 3: generate and set "to" train direction
        direction = randomInteger(0, 3);
        
        if(direction == 0)
          trainIndex->toDirection = NORTH;
        else if(direction == 1)
          trainIndex->toDirection = EAST;
        else if(direction == 2)
          trainIndex->toDirection = SOUTH;
        else
          trainIndex->toDirection = WEST;
        
        //step 4: determine train size
        trainIndex->size = randomInteger(2,9);
        
        //step 5: determine traversal time
        trainIndex->traversalTime = 6000*(trainIndex->size) + globalCount;
        
        //step 6: determine passenger count      
       
        trainIndex->passengerCount = (unsigned int)  ((double) (300.0*((frequencyCount-1000.0)/1000.0)));
        //tempCount = 0;
       // crapes = 0;
        //step 7: 
        //trainIndex->brakeTemp = lifeIsTooHard;
        
        if(priority == 1)
          trainIndex = &train1;
        else if(priority == 2)
          trainIndex = &train2;
        
        TrainState = 0;
      }
    } //ebd of if statement block semantics 
    vTaskDelay(500);
  } //end of mosnter while(1) loop  
}
