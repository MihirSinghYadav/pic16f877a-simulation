// main.h
#ifndef MAIN_H  // Prevent multiple inclusions
#define	MAIN_H

#include <xc.h>     // Core microcontroller header
#include "clcd.h"     // Definitions for controlling the CLCD
#include "digital_keypad.h"  // Definitions for the digital keypad
#include "timers.h"    // Definitions for using timers 

// Symbolic Constants - Project States 
#define WASHING_PROGRAM_DISPLAY     0x01   
#define WATER_LEVEL           0x02
#define START_STOP_SCREEN        0x03
#define START_PROGRAM          0x04
#define PAUSE              0x05

// Symbolic Constants - Reset Flags 
#define WASHING_PROGRAM_DISPLAY_RESET  0x10 
#define WATER_LEVEL_RESET        0x11
#define START_PROGRAM_RESET       0x12
#define REST_NOTHING          0x00

// Physical Output Pin Definitions
#define FAN     RC2            
#define BUZZER   RC1          
#define BUZZER_DDR TRISC1   
#define FAN_DDR   TRISC2 
#define ON     1            
#define OFF     0            

// Function Prototypes
void power_on_screen(void);             // Display power-on message
void clear_screen(void);                // Clear CLCD display
void washing_program_display(unsigned char key);  // Display washing program options
void water_level_display(unsigned char key);     // Display water level options
void set_time_for_program(void);        // Allow user to set program duration
void run_program(unsigned char key);    // Start the selected program 

#endif	/* MAIN_H */