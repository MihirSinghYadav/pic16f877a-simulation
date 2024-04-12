// digital_keypad.h
#ifndef DIGITAL_KEYPAD_H  // Prevent multiple inclusions 
#define	DIGITAL_KEYPAD_H 

// Keypad Operation Modes
#define LEVEL_DETECTION     0  // Mode for raw keypad state reading 
#define LEVEL          0       // Placeholder (likely for custom use)

#define STATE_DETECTION     1  // Mode for normal key press detection
#define STATE          1       // Placeholder (likely for custom use)

// Port and Pin Assignments (Adjust based on your hardware)
#define KEYPAD_PORT       PORTB    // Keypad data port
#define KEYPAD_PORT_DDR     TRISB   // Keypad data port direction register

// Input Definitions
#define INPUT_LINES       0x3F     // Mask to read the relevant input pins  

// Keypad Button Definitions
#define SW1           0x3E 
#define SW2           0x3D
#define SW3           0x3B
#define SW4           0x37
#define SW5           0x2F
#define SW6           0x1F
#define LSW4          0xB7     // Likely a long-press variant of SW4
#define LSW5          0xAF     // Likely a long-press variant of SW5

// Constant Definitions
#define ALL_RELEASED      INPUT_LINES // Indicates all keys are released

// Function Prototypes
unsigned char read_digital_keypad(unsigned char mode); // Read the keypad state
void init_digital_keypad(void);      // Initialize the keypad

#endif	/* DIGITAL_KEYPAD_H */

