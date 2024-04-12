// digital_keypad.c
#include "digital_keypad.h" // Header containing keypad constants and definitions
#include <xc.h>             // Header for your specific microcontroller

// Purpose: Configures the microcontroller pins connected to the keypad as inputs.
void init_digital_keypad(void)
{
  /* Configure Keypad Port for input */
  KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES; // Set input bits high in the direction register
}

// Purpose: Reads from the digital keypad, handling keypress detection, debouncing, and long press functionality.
unsigned char read_digital_keypad(unsigned char mode)
{
  static unsigned char once = 1;      // Flag to track if a key is currently pressed
  static unsigned char pre_key;       // Stores the code of the previously pressed key
  static unsigned char longpress;     // Counter for long press detection

  if (mode == LEVEL_DETECTION) 
  {
    // Returns raw keypad input (useful for debugging)
    return KEYPAD_PORT & INPUT_LINES; 
  }
  else // Mode for normal keypress detection
  {
    if (((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once) 
    {
      // A key press is detected
      once = 0;                         // Clear flag, indicating key is down
      longpress = 0;                    // Reset long press counter
      pre_key = KEYPAD_PORT & INPUT_LINES;  // Store the code of the pressed key  
    }
    else if (!once && (pre_key == (KEYPAD_PORT & INPUT_LINES)) && longpress < 50)
    {
      // Key is still held; increment long press counter
      longpress++;
    }
    else if (longpress == 50)
    {
      // Long press detected
      longpress++;                      // Increment for continuous long press 
      return 0x80 | pre_key;            // Return key code with long press indicator
    }
    else if((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED && !once)
    {
      // Key has been released
      once = 1;                         // Set flag, indicating key is up
      if(longpress < 50)
      {
        // Short press detected
        return pre_key;                  
      }
    }
  }
   
  return ALL_RELEASED; // No keypress detected
}