/**
 * @file millistimer.cpp
 * @author Riccardo Iacob
 * @brief "millistimer.h" implementation
 * @version 0.1
 * @date 2023-01-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "millistimer.h"

void MillisTimer::begin(uint32_t ms)
{
    if (!running)
    {
        period = ms;
        startMillis = millis();
        endMillis = startMillis + ms;
        running = true;
    }
}

bool MillisTimer::isExpired()
{
    // If the set time has passed, reset timer and return true, else return false
    if (millis() >= endMillis)
    {
        reset();
        return true;
    }
    return false;
}

void MillisTimer::reset()
{
    // Restart the timer with the initial value
    stop();
    begin(period);
}

uint32_t MillisTimer::getElapsedTime()
{
    // Return time passed since beginning of timer
    return (millis() - startMillis);
}

uint32_t MillisTimer::getRemainingTime()
{
    // Return time remaining to end of timer
    return (endMillis - millis());
}

bool MillisTimer::isRunning()
{
    // Return the running status of the timer
    return running;
}

void MillisTimer::printInfo()
{
    // Print debug info about the timer
    Serial.print("period: ");
    Serial.println(period);
    Serial.print("startMillis: ");
    Serial.println(startMillis);
    Serial.print("endMillis: ");
    Serial.println(endMillis);
    Serial.print("isRunning: ");
    Serial.println(running);
    Serial.print("elapsedTime: ");
    Serial.println(getElapsedTime());
    Serial.print("remainingTime: ");
    Serial.println(getRemainingTime());
}

void MillisTimer::incrementBy(uint32_t ms)
{
    // Increment the end of timer by ms
    endMillis += ms;
}

void MillisTimer::decrementBy(uint32_t ms)
{
    // If the result would be lesser than the start millis, set the timer period to zero instaead
    if (ms > endMillis)
    {
        endMillis = startMillis;
        return;
    }
    // Decrement the end of timer by ms
    endMillis -= ms;
}

uint32_t MillisTimer::getStartMillis()
{
    // Return the millis() value at the start of the timer
    return startMillis;
}

uint32_t MillisTimer::getEndMillis()
{
    // Return the millis() value at the end of the timer
    return endMillis;
}

void MillisTimer::stop()
{
    // Stop the timer and allow the user to use begin() again
    running = false;
}