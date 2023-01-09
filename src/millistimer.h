/**
 * @file millistimer.h
 * @author Riccardo Iacob
 * @brief Library that allows users to create non-blocking timers utilizing the milliseconds library
 * @version 0.1
 * @date 2023-01-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MILLISTIMER_H
#define MILLISTIMER_H

#include <Arduino.h>

class MillisTimer
{
private:
    // millis() value at the start of the timer
    uint32_t startMillis;
    // millis() value at the end of the timer
    uint32_t endMillis;
    // delay used in begin() method, will not be modified
    uint32_t period;
    bool running = false;

public:
    /**
     * @brief Initializes the timer
     * @note Timer won't be re-initialized if it's running (use isRunning() to check its status)
     *
     * @param ms: The timer period, in milliseconds
     */
    void begin(uint32_t ms);
    /**
     * @brief Checks if the timer is expired or not
     *
     * @return true: If the timer is expired (the period is already past)
     * @return false: If the timer is not expired (the period is not past yet)
     */
    bool isExpired();
    /**
     * @brief Resets (stops and restarts) the timer with the period defined in the begin() method
     */
    void reset();
    /**
     * @brief Returns the elapsed time from the start of the timer
     *
     * @return uint32_t: The elapsed time, in milliseconds
     */
    uint32_t getElapsedTime();
    /**
     * @brief Returns the remaning time until the end of the timer
     *
     * @return uint32_t : The remaining time, in milliseconds
     */
    uint32_t getRemainingTime();
    /**
     * @brief Checks if the timer is running or not
     *
     * @return true: If the timer is running
     * @return false: If the timer is not running
     */
    bool isRunning();
    /**
     * @brief Prints timer information to Serial
     */
    void printInfo();
    /**
     * @brief Increments the period by ms
     *
     * @param ms: The increment of the period, in milliseconds
     */
    void incrementBy(uint32_t ms);
    /**
     * @brief Decrements the period by ms
     *
     * @param ms: The decrement of the period, in milliseconds
     */
    void decrementBy(uint32_t ms);
    /**
     * @brief Gets the millis() at the start of the timer
     *
     * @return uint32_t: millis() at the start of the timer, in milliseconds
     */
    uint32_t getStartMillis();
    /**
     * @brief Gets the millis() at the end of the timer, in milliseconds
     *
     * @return uint32_t: millis() at the end of the timer, in milliseconds
     */
    uint32_t getEndMillis();
    void stop();
};

#endif