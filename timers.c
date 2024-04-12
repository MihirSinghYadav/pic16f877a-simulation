// timers.c
#include <xc.h>  // Include core microcontroller definitions

void init_timer2(void)
{
  /* Setting Timer 2 Pre-scaler (Clock Division) */
  T2CKPS0 = 1;  // These two lines set a prescaler of 1:16
  T2CKPS1 = 1;  // This slows down the timer's base clock

  /* Loading Pre-load Value for Timer Period */
  PR2 = 250;    // Timer will count from 0 to 250 repeatedly

  /* Enabling Interrupts */
  TMR2IE = 1;   // Allows Timer 2 to trigger an interrupt when it overflows

  /* Starting the Timer */  
  TMR2ON = 0;  // Turns Timer 2 on
}