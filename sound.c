#include "headerThingy.h"

void Sound(void *vParameters) {
  while(1) {  
    static int i;
    i = 0;
# if SOUND_ENABLE  
    while(soundScriptTiming[i] != END && playScript) {
      unsigned int ulPeriod;
      ulPeriod = SysCtlClockGet() / soundScriptPitch[i];
      PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ulPeriod);
      PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, ulPeriod / 16);
      
      PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, TRUE);
      
      vTaskDelay(soundScriptTiming[i]);
      
      PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, FALSE);
      
      i++;
    }

    playScript = FALSE;
# endif    
    vTaskDelay(1);
  }
}
