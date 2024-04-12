// isr.c
#include <xc.h>   // Core microcontroller definitions
#include "main.h"  // Likely includes definitions for 'sec' and 'min' variables

extern unsigned char sec, min; // 'sec' and 'min' likely represent seconds and minutes

void __interrupt() isr(void) 
{
  static unsigned int count = 0;  // Internal counter for timing within the interrupt

  if (TMR2IF == 1)  // Check if the interrupt was triggered by Timer 2 
  {
    if (++count == 1250)  // Check if a specific time interval has passed
    {
      count = 0;           // Reset the counter
      
      if(sec > 0)         
      {
        sec--;             // Decrement seconds
      }
      else if(sec == 0 && min > 0) 
      {
        min--;             // Decrement minutes if seconds reach 0
        sec = 59;          
      }
    }     
    TMR2IF = 0; // Clear Timer 2's interrupt flag
  }
}