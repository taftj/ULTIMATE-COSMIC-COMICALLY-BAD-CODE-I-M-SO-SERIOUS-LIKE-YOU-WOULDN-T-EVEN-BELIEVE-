#include "headerThingy.h"

void Display(void *vParameters) {
  
  xOLEDMessage flair1;
  xOLEDMessage flair2;
  
  xOLEDMessage fromTitle;
  xOLEDMessage fromInfo1;
  xOLEDMessage fromInfo2;
  
  xOLEDMessage toTitle;
  xOLEDMessage toInfo1;
  xOLEDMessage toInfo2;
  
  xOLEDMessage sizeTitle;
  xOLEDMessage sizeInfo1;
  xOLEDMessage sizeInfo2;
  
  xOLEDMessage passTitle;
  xOLEDMessage passInfo1;
  xOLEDMessage passInfo2;
  
  xOLEDMessage tempTitle;
  xOLEDMessage tempInfo1;
  xOLEDMessage tempInfo2;
  
  xOLEDMessage travTitle;
  xOLEDMessage travInfo1;
  xOLEDMessage travInfo2;
  
  xOLEDMessage timeTitle;
  xOLEDMessage timeInfo;
  
  xOLEDMessage trainOne;
  xOLEDMessage trainTwo;
  xOLEDMessage ionWaffleStoat;
  xOLEDMessage yea1;
  xOLEDMessage yea2;
  
  static unsigned int contrast1, contrast2;
  static unsigned int fromInfoContrast1, fromInfoContrast2;
  static unsigned int flashDuration;
  
  static  char sizeString1[10];
  static  char sizeString2[10];
  
  unsigned char passString1[10];
  unsigned char passString2[10];
  
  unsigned char tempString1[10];
  unsigned char tempString2[10];
  
  static char travString1[10];
  static char travString2[10];
  
  static char timeString[10];
  
  while(1) {
    contrast1 = 8;
    contrast2 = 8;
    
    if(trainIndex == &train1)
      contrast1 = 15;
    
    if(trainIndex == &train2)
      contrast2 = 15;
    
    //TITLES
    flair1.pcMessage = "Applehansontaft";
    flair1.ulX = 10;
    flair1.ulY = 0;
    flair1.brightness = 10;
    
    flair2.pcMessage = "Win Freight";
    flair2.ulX = 10;
    flair2.ulY = 10;
    flair2.brightness = 7;
    
    //TRAIN LABELS
    trainOne.pcMessage = "1";
    trainOne.ulX = 80;
    trainOne.ulY = 10;
    trainOne.brightness = contrast1;
    
    trainTwo.pcMessage = "2";
    trainTwo.ulX = 100;
    trainTwo.ulY = 10;
    trainTwo.brightness = contrast2;
    
    //FROM DIRECTION INFORMATION  
    fromTitle.pcMessage = "From: ";
    fromTitle.ulX = 10;
    fromTitle.ulY = 20;
    fromTitle.brightness = 15;
    
    if(trainIndex->fromDirection == NORTH)
      flashDuration = 3000;
    if(trainIndex->fromDirection == EAST)
      flashDuration = 4000;
    if(trainIndex->fromDirection == SOUTH)
      flashDuration = 2000;
    if(trainIndex->fromDirection == WEST)
      flashDuration = 2000;
    
    if(trainIndex == &train1) {
      fromInfoContrast2 = contrast2;
      
      if(globalCount % flashDuration == 0)
        fromInfoContrast1 = 15;
      else if(globalCount % (flashDuration / 2) == 0)
        fromInfoContrast1 = 0;  
    }    
    else if(trainIndex == &train2) {
      fromInfoContrast1 = contrast1;
      
      if(globalCount % flashDuration == 0)
        fromInfoContrast2 = 15;
      else if(globalCount % (flashDuration / 2) == 0)
        fromInfoContrast2 = 0;  
    }
    else {      
      fromInfoContrast1 = contrast1;
      fromInfoContrast2 = contrast2;
    }
    
    if(train1.fromDirection == NORTH)
      fromInfo1.pcMessage = "N";
    else if(train1.fromDirection == EAST)
      fromInfo1.pcMessage = "E";
    else if(train1.fromDirection == SOUTH)
      fromInfo1.pcMessage = "S";
    else if(train1.fromDirection == WEST)
      fromInfo1.pcMessage = "W";
    else
      fromInfo1.pcMessage = "-";
    
    fromInfo1.ulX = 80;
    fromInfo1.ulY = 20;    
    fromInfo1.brightness = fromInfoContrast1;
    
    if(train2.fromDirection == NORTH)
      fromInfo2.pcMessage = "N";
    else if(train2.fromDirection == EAST)
      fromInfo2.pcMessage = "E";
    else if(train2.fromDirection == SOUTH)
      fromInfo2.pcMessage = "S";
    else if(train2.fromDirection == WEST)
      fromInfo2.pcMessage = "W";
    else
      fromInfo2.pcMessage = "-";
    
    fromInfo2.ulX = 100;
    fromInfo2.ulY = 20;
    fromInfo2.brightness = fromInfoContrast2;
    
    //TO DIRECTION INFORMATION
    toTitle.pcMessage = "To: ";
    toTitle.ulX = 10;
    toTitle.ulY = 30;
    toTitle.brightness = 15;
    
    if(train1.toDirection == NORTH)
      toInfo1.pcMessage = "N";
    else if(train1.toDirection == EAST)
      toInfo1.pcMessage = "E";
    else if(train1.toDirection == SOUTH)
      toInfo1.pcMessage = "S";
    else if(train1.toDirection == WEST)
      toInfo1.pcMessage = "W";
    else
      toInfo1.pcMessage = "-";
    
    toInfo1.ulX = 80;
    toInfo1.ulY = 30;
    toInfo1.brightness = contrast1;
    
    if(train2.toDirection == NORTH)
      toInfo2.pcMessage = "N";
    else if(train2.toDirection == EAST)
      toInfo2.pcMessage = "E";
    else if(train2.toDirection == SOUTH)
      toInfo2.pcMessage = "S";
    else if(train2.toDirection == WEST)
      toInfo2.pcMessage = "W";
    else
      toInfo2.pcMessage = "-";
    
    toInfo2.ulX = 100;
    toInfo2.ulY = 30;
    toInfo2.brightness = contrast2;
    
    //SIZE INFORMATION
    sizeTitle.pcMessage = "Size: ";
    sizeTitle.ulX = 10;
    sizeTitle.ulY = 40;
    sizeTitle.brightness = 15;
    
    sprintf(sizeString1, "%d", train1.size);
    sprintf(sizeString2, "%d", train2.size);
    
    if(train1.size == NONE)
      sizeInfo1.pcMessage = "-";
    else
      sizeInfo1.pcMessage = sizeString1;
    
    sizeInfo1.ulX = 80;
    sizeInfo1.ulY = 40;
    sizeInfo1.brightness = contrast1;
    
    if(train2.size == NONE)
      sizeInfo2.pcMessage = "-";
    else
      sizeInfo2.pcMessage = sizeString2;
    
    sizeInfo2.ulX = 100;
    sizeInfo2.ulY = 40;
    sizeInfo2.brightness = contrast2;
    
    //PASSENGER INFORMATION
    passTitle.pcMessage = "Passengers: ";
    passTitle.ulX = 10;
    passTitle.ulY = 50;
    passTitle.brightness = 15;
    
    sprintf(passString1, "%d", train1.passengerCount);
    sprintf(passString2, "%d", train2.passengerCount);
    
    
    if(train1.passengerCount == NONE)
      passInfo1.pcMessage = "-  ";
    else
      passInfo1.pcMessage = &passString1;
    
    passInfo1.ulX = 80;
    passInfo1.ulY = 50;
    passInfo1.brightness = contrast1;
    
    if(train2.passengerCount == NONE)
      passInfo2.pcMessage = "-";
    else
      passInfo2.pcMessage = &passString2;
    
    passInfo2.ulX = 100;
    passInfo2.ulY = 50;
    passInfo2.brightness = contrast2;
    
    //TEMPERATURE INFORMATION
    tempTitle.pcMessage = "Temp(C): ";
    tempTitle.ulX = 10;
    tempTitle.ulY = 60;
    tempTitle.brightness = 12;
    
    /* sprintf fucks it up, using the following messy block of code */
    char brakeTempArray[4] = "    ";
    int justinCrazy = (unsigned int)trainIndex->brakeTemp;
    int i = 2;
    while(justinCrazy > 0) {
      brakeTempArray[i] = (justinCrazy%10) + 48;
      justinCrazy = justinCrazy/10;
      i--;     
    }
    brakeTempArray[3] = 0;
   // sprintf(tempString1, "%d", train1.brakeTemp);
   // sprintf(tempString2, "%d", train2.brakeTemp);
    
    if((train1.brakeTemp == NONE)||(!train1.present))
      tempInfo1.pcMessage = "-  ";
    else
      tempInfo1.pcMessage = brakeTempArray;
    
    tempInfo1.ulX = 80;
    tempInfo1.ulY = 60;
    tempInfo1.brightness = contrast1;
    
    if((train2.brakeTemp == NONE)||(!train2.present))
      tempInfo2.pcMessage = "-  ";
    else
      tempInfo2.pcMessage = brakeTempArray;
    
    tempInfo2.ulX = 100;
    tempInfo2.ulY = 60;
    tempInfo2.brightness = contrast2;
    
    //TRAVERSAL TIME INFORMATION
    travTitle.pcMessage = "Traversal: ";
    travTitle.ulX = 10;
    travTitle.ulY = 70;
    travTitle.brightness = 12;
    
    sprintf(travString1, "%d", train1.traversalTime / 1000);
    sprintf(travString2, "%d", train2.traversalTime / 1000);
    
    if(train1.traversalTime == NONE)
      travInfo1.pcMessage = "-   ";
    else
      travInfo1.pcMessage = &travString1;
    
    travInfo1.ulX = 80;
    travInfo1.ulY = 70;
    travInfo1.brightness = contrast1;
    
    if(train2.traversalTime == NONE)
      travInfo2.pcMessage = "-   ";
    else
      travInfo2.pcMessage = &travString2;
    
    travInfo2.ulX = 100;
    travInfo2.ulY = 70;
    travInfo2.brightness = contrast2;
    
    
    //TRAIN SIZE INFO
    
    ionWaffleStoat.pcMessage = "Long?";
    ionWaffleStoat.ulY = 80;
    ionWaffleStoat.ulX = 10;
    ionWaffleStoat.brightness = 15;
    
    
  
    yea1.ulY = 80;
    yea1.ulX = 80;
    yea1.brightness = 15;
    
  
    yea2.ulY = 80;
    yea2.ulX = 100;
    yea2.brightness = 15;
    
    if (train1.size >= 6)yea1.pcMessage = "YES";
    else  yea1.pcMessage = "-  ";
    
    if (train2.size >= 6) yea2.pcMessage = "YES";
    else yea2.pcMessage = "-  ";
    
    
    
    
    //TIME INFORMATION
    timeTitle.pcMessage = "Time: ";
    timeTitle.ulX = 10;
    timeTitle.ulY = 89;
    timeTitle.brightness = 10;
    
    sprintf(timeString, "%d", globalCount / 1000);
    
    timeInfo.pcMessage = &timeString;
    timeInfo.ulX = 80;
    timeInfo.ulY = 89;
    timeInfo.brightness = 10;
    
    xQueueSend( xOLEDQueue, &yea1, 0 );
    xQueueSend( xOLEDQueue, &yea2, 0 );
    xQueueSend( xOLEDQueue, &flair1, 0 );
    xQueueSend( xOLEDQueue, &flair2, 0 );  
    xQueueSend( xOLEDQueue, &fromTitle, 0 );
    xQueueSend( xOLEDQueue, &fromInfo1, 0 );
    xQueueSend( xOLEDQueue, &fromInfo2, 0 );
    xQueueSend( xOLEDQueue, &toTitle, 0 );
    xQueueSend( xOLEDQueue, &toInfo1, 0 );
    xQueueSend( xOLEDQueue, &toInfo2, 0 );
    xQueueSend( xOLEDQueue, &sizeTitle, 0 );
    xQueueSend( xOLEDQueue, &sizeInfo1, 0 );
    xQueueSend( xOLEDQueue, &sizeInfo2, 0 );
    xQueueSend( xOLEDQueue, &passTitle, 0 );
    xQueueSend( xOLEDQueue, &passInfo1, 0 ); 
    xQueueSend( xOLEDQueue, &passInfo2, 0 );  
    xQueueSend( xOLEDQueue, &tempTitle, 0 );
    xQueueSend( xOLEDQueue, &tempInfo1, 0 ); 
    xQueueSend( xOLEDQueue, &tempInfo2, 0 );     
    xQueueSend( xOLEDQueue, &travTitle, 0 );
    xQueueSend( xOLEDQueue, &travInfo1, 0 ); 
    xQueueSend( xOLEDQueue, &travInfo2, 0 ); 
    xQueueSend( xOLEDQueue, &timeTitle, 0 ); 
    xQueueSend( xOLEDQueue, &timeInfo, 0 ); 
    
    xQueueSend( xOLEDQueue, &trainOne,0);
    xQueueSend( xOLEDQueue, &trainTwo,0);
    xQueueSend( xOLEDQueue, &ionWaffleStoat,0);
    
    
    vTaskDelay(500);
  }
}
