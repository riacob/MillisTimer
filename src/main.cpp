/**
 * @file main.cpp
 * @author Riccardo Iacob
 * @brief Example sketch for MillisTimer library
 * @version 0.1
 * @date 2023-01-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <Arduino.h>
#include "millistimer.h"

// Create two new timers
// This could be declared globally or as static
MillisTimer timer0;
MillisTimer timer1;

void setup()
{
  // Set the LED pin to output
  pinMode(LED_BUILTIN, OUTPUT);
  // Begin serial port
  Serial.begin(9600);
}

void loop()
{
  // If timer is already running, the begin() function won't reset it
  timer0.begin(5000);  // 5 second timer, for LED toggling
  timer1.begin(1000); // 1 second timer, for serial print
  if (timer0.isExpired())
  {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  if (timer1.isExpired())
  {
    Serial.println("******** TIMER0 INFO ********");
    timer0.printInfo();
    Serial.println("******** TIMER1 INFO ********");
    timer1.printInfo();
  }
}