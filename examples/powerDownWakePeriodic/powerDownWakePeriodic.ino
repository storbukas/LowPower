/*
 *  powerDownWakePeriodic
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
// SETUP
//
void setup() {
  // No setup is required for this library
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() 
{
    // Enter power down state for 8 s with ADC and BOD module disabled
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  
    
    // Do something here
    // Example: Read sensor, data logging, data transmission.
}
ß