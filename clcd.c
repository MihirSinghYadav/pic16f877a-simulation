
#include "clcd.h" // Header file for custom CLCD definitions (pin mappings)
#include <xc.h>   // Header file for the specific microcontroller being used

// Purpose: Sends a byte of data or a command to the CLCD, handling the control
// lines (RS, EN) appropriately.
void clcd_write(unsigned char byte, unsigned char mode) {
  CLCD_RS = mode; // Set the CLCD register select (RS) line based on 'mode':
                  //   INST_MODE = Instruction mode (sending commands)
                  //   DATA_MODE = Data mode (sending character data)
  CLCD_DATA_PORT =
      byte; // Write the 'byte' of data or command to the CLCD data port

  CLCD_EN = HI;    // Pulse the CLCD enable (EN) line high
  __delay_us(100); // Brief delay
  CLCD_EN = LOW;   // Return EN line low

  __delay_us(4100); // Longer delay (required by some CLCDs)
}

// Purpose: Executes the specific initialization sequence required to correctly
// start up the CLCD controller.
static void init_display_controller(void) {
  __delay_ms(30); // Initial power-on delay for CLCD

  // Specific startup sequence for the CLCD controller:
  clcd_write(EIGHT_BIT_MODE, INST_MODE); // Set 8-bit mode
  __delay_us(4100);
  clcd_write(EIGHT_BIT_MODE, INST_MODE); // Repeat for some displays
  __delay_us(100);
  clcd_write(EIGHT_BIT_MODE, INST_MODE); // One more time...
  __delay_us(1);
  clcd_write(CLEAR_DISP_SCREEN, INST_MODE); // Clear the display
  __delay_us(100);
  clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE); // Display on, cursor off
  __delay_us(100);
}

// Purpose: Configures the microcontroller pins connected to the CLCD as outputs
// and calls the controller initialization routine.
void init_clcd(void) {
  // Set up CLCD control and data lines as outputs:
  CLCD_DATA_PORT_DDR = 0x00;
  CLCD_RS_DDR = 0;
  CLCD_EN_DDR = 0;

  init_display_controller(); // Call the initialization sequence
}

// Purpose: Sets the display address (position) and then sends a single
// character to be displayed on the CLCD.
void clcd_putch(const char data, unsigned char addr) {
  clcd_write(addr, INST_MODE); // Set display address
  clcd_write(data, DATA_MODE); // Write a single character
}

// Purpose: Sets the display address (position) and then sends an entire
// null-terminated string to be displayed on the CLCD.
void clcd_print(const char *str, unsigned char addr) {
  clcd_write(addr, INST_MODE); // Set display address

  while (*str != '\0') // Loop until the end of the string
  {
    clcd_write(*str, DATA_MODE); // Write the current character
    str++;                       // Move to the next character
  }
}