#ifndef HEADERTHINGY_H
#define HEADERTHINGY_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#include "C:\StellarisWare\inc\hw_ints.h"
#include "C:\StellarisWare\inc\hw_memmap.h"
#include "C:\StellarisWare\inc\hw_types.h"

//#include "C:\StellarisWare\inc\lm3s8962.h"
#include "C:\StellarisWare\driverlib\debug.h"
#include "C:\StellarisWare\driverlib\sysctl.h"
#include "C:\StellarisWare\boards\ek-lm3s8962\drivers\rit128x96x4.h"
#include "C:\StellarisWare\driverlib\timer.h"
#include "C:\StellarisWare\driverlib\gpio.h"
#include "C:\StellarisWare\driverlib\pwm.h"
#include "C:\StellarisWare\driverlib\interrupt.h"
#include "C:\StellarisWare\driverlib\uart.h"
#include "C:\StellarisWare\driverlib\adc.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "lcd_message.h"

#include "hw_sysctl.h"

#include "grlib.h"

#include "osram128x64x4.h"
#include "formike128x128x16.h"

//#include "bitmap.h"

#define MAX_QUEUE_LENGTH        6
#define TASK_SELECT             4
#define HIGH                    TRUE
#define LOW                     FALSE
#define SOUND_ENABLE            0

#define PORT_DATA               (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)  // full 8 bits of port used
#define PITCH                   100
#define END                     -1

//NOTES - http://processors.wiki.ti.com/index.php/Playing_The_Imperial_March

#define c                       261
#define d                       294
#define e                       329
#define f                       349
#define g                       391
#define gS                      415
#define a                       440
#define aS                      455
#define b                       466
#define cH                      523
#define cSH                     554
#define dH                      587
#define dSH                     622
#define eH                      659
#define fH                      698
#define fSH                     740
#define gH                      784
#define gSH                     830
#define aH                      880

//DIRECTIONS
#define NONE                    -1
#define NORTH                   0
#define EAST                    1
#define SOUTH                   2
#define WEST                    3

//PRIMITIVE TYPE DEFINITION
typedef enum {FALSE = 0, TRUE = 1} bool;

//STRUCT DEFINITIONS
typedef struct {
  bool present;
  int fromDirection;
  int toDirection;
  int size;
  int traversalTime;
  unsigned int passengerCount;
  long brakeTemp;
} train;

//SEMAPHORE FUN LAND

//GLOBAL VARIABLE DECLARATIONS
extern unsigned int tempCount;
extern unsigned int frequencyCount;
extern unsigned int TrainState;
extern int seed;
extern unsigned long *soundScriptTiming, *soundScriptPitch;
extern unsigned long lifeIsTooHard;
extern xQueueHandle xOLEDQueue;

extern train *trainIndex;
extern bool trackOverload;

extern unsigned int globalCount;
  
extern bool outputSetup;
extern bool playScript;

extern int randd;

extern train nullTrain;
extern train train1;
extern train train2;

extern unsigned int tempEmergency;


//FUNCTION PROTOTYPES
extern void Startup(void);

//we'll need these TaskHandles to suspend/resume tasks later

extern  xTaskHandle vTrainCom;
extern  xTaskHandle vSwitchCon;
extern  xTaskHandle vCurrentTrain;
extern  xTaskHandle vSerialCom;
extern  xTaskHandle vSchedule;
extern xTaskHandle vBrakeTemp;

extern void TrainCom(void *vParameters);
extern void CurrentTrain(void *vParameters);
extern void SwitchControl(void *vParameters);
extern void SerialCom(void *vParameters);
extern void songTrial(void);

extern void IntTimer0(void);
extern int randomInteger(int lowNum, int highNum);
extern void IntGPIOe(void);
extern void IntGPIOf(void);

extern void UARTIntHandler(void);
extern void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount);

extern void BrakeTemp(void *vParameters);
extern void pin(bool);
extern void Sound(void *vParameters);
extern void Display(void *vParameters);
//END FUNCTION PROTOTYPES

#endif
