// clcd.h
#ifndef CLCD_H // Prevent multiple inclusions
#define	CLCD_H 

// Crystal Oscillator Frequency (Adjust based on your microcontroller)
#define _XTAL_FREQ         20000000

// Pin Mapping (These need to be adjusted for your specific CLCD connections)
#define CLCD_DATA_PORT_DDR     TRISD  // Data port direction register
#define CLCD_RS_DDR         TRISE2     // Register Select (RS) line direction register
#define CLCD_EN_DDR         TRISE1     // Enable (EN) line direction register

#define CLCD_DATA_PORT       PORTD    // Data port
#define CLCD_RS           RE2         // Register Select (RS) line
#define CLCD_EN           RE1         // Enable (EN) line

// Mode and State Constants
#define INST_MODE          0  // Instruction mode for sending commands
#define DATA_MODE          1  // Data mode for sending characters

#define HI             1  // Logic HIGH
#define LOW            0  // Logic LOW

// Display Addressing Macros (Adjust based on your CLCD size)
#define LINE1(x)          (0x80 + x) // Set Display Address for Line 1 (x is character position)
#define LINE2(x)          (0xC0 + x) // Set Display Address for Line 2 (x is character position)
#define LINE3(x)          (0x90 + x) // Set Display Address for Line 3 (x is character position)
#define LINE4(x)          (0xD0 + x) // Set Display Address for Line 4 (x is character position)

// Common CLCD Commands
#define EIGHT_BIT_MODE       0x33       // Command to configure 8-bit mode
#define CLEAR_DISP_SCREEN      0x01     // Command to clear the display
#define DISP_ON_AND_CURSOR_OFF   0x0C   // Command to turn on the display and turn off cursor

// Placeholder definition (may be used for custom commands)
#define BLOCK            0xFF

// Function Prototypes for CLCD Control
void init_clcd(void);            // Initialize the CLCD
void clcd_putch(const char data, unsigned char addr); // Write a character to a specific display address
void clcd_print(const char *str, unsigned char addr); // Write a string to a specific display address
void clcd_write(unsigned char byte, unsigned char mode); // Low-level function to send a byte as either instruction or data

#endif	/* CLCD_H */