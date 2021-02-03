/*
 *  standbyExternalInterruptSAMD21
 *
 *  Source: https://github.com/storbukas/LowPower
 *  Based on: https://github.com/rocketscream/Low-Power
 *
 *  Licensed under the MIT License
 *  https://opensource.org/licenses/MIT
 *
 */

// ---------------------------------------------------------------------
// INCLUDES
//
#include "LowPower.h"

// ---------------------------------------------------------------------
// CONSTANTS
//
// External interrupt on pin 0 (use pin 0 to 24, except pin 4 on Arduino Zero)
const int pin = 0;
unsigned char count = 10;

// ---------------------------------------------------------------------
// SETUP
//
void setup() {
  // Wait for serial USB port to open
  while (!SerialUSB)
    ;
  SerialUSB.println("***** ATSAMD21 Standby Mode Example *****");

  // ***** IMPORTANT *****
  // Delay is required to allow the USB interface to be active during
  // sketch upload process
  SerialUSB.println("Entering standby mode in:");
  for (count; count > 0; count--) {
    SerialUSB.print(count);
    SerialUSB.println(" s");
    delay(1000);
  }
  // *********************

  // External interrupt on pin (example: press of an active low button)
  // A pullup resistor is used to hold the signal high when no button press
  attachInterrupt(pin, blink, LOW);
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  SerialUSB.println("Entering standby mode.");
  SerialUSB.println("Apply low signal to wake the processor.");
  SerialUSB.println("Zzzz...");
  // Detach USB interface
  USBDevice.detach();
  // Enter standby mode
  LowPower.standby();
  // Attach USB interface
  USBDevice.attach();
  // Wait for serial USB port to open
  while (!SerialUSB)
    ;
  // Serial USB is blazing fast, you might miss the messages
  delay(1000);
  SerialUSB.println("Awake!");
  SerialUSB.println("Send any character to enter standby mode again");
  // Wait for user response
  while (!SerialUSB.available())
    ;
  while (SerialUSB.available() > 0) {
    SerialUSB.read();
  }
}

// ---------------------------------------------------------------------
// FUNCTIONS
//
void blink(void) {}