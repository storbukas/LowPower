/*
 *  powerDownWakeExternalInterrupt
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
const int wakeUpPin = 2;

// ---------------------------------------------------------------------
// SETUP
//
void setup() {
  // Configure wake up pin as input.
  // This will consumes few uA of current.
  pinMode(wakeUpPin, INPUT);
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  // Allow wake up pin to trigger interrupt on low.
  attachInterrupt(0, wakeUp, LOW);

  // Enter power down state with ADC and BOD module disabled.
  // Wake up when wake up pin is low.
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  // Disable external pin interrupt on wake up pin.
  detachInterrupt(0);

  // Do something here
  // Example: Read sensor, data logging, data transmission.
}

// ---------------------------------------------------------------------
// FUNCTIONS
//
void wakeUp() {
  // Just a handler for the pin interrupt.
}
