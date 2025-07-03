/*
  DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
  Created by Konrad Wohlfahrt, July 03, 2025.
  Released into the public domain.
*/

#ifndef DonutStudioTimer_h
#define DonutStudioTimer_h

#include "Arduino.h"


class Timer
{
  public:
    /* --- CONSTRUCTOR --- */
    // Constructs a timer object and sets the countdown time.
    Timer(uint16_t hours = 0, uint8_t minutes = 0, uint8_t seconds = 0, uint16_t milliseconds = 0);


    /* --- METHODS --- */

    /* MAIN */

    // Starts the countdown from this timestamp.
    void begin();
    // Returns true if the current timestamp exceeds the countdown, false otherwise.
    bool isOver();
    // Pause or resume the countdown.
    void setPause(bool value);
    // Returns true if the countdown is paused, false otherwise.
    bool isPaused();


    /* SETTINGS */

    // Sets the countdown time.
    void setTimer(uint16_t hours = 0, uint8_t minutes = 0, uint8_t seconds = 0, uint16_t milliseconds = 0);
    // Returns the total countdown time in milliseconds.
    uint32_t getTotalMilliseconds();
    // Sets the milliseconds (0 - 999).
    void setMilliseconds(uint16_t milliseconds);
    // Returns the milliseconds.
    uint16_t getMilliseconds();
    // Sets the seconds (0 - 59).
    void setSeconds(uint8_t seconds);
    // Returns the seconds.
    uint8_t getSeconds();
    // Sets the minutes of the timer (0 - 59).
    void setMinutes(uint8_t minutes);
    // Returns the minutes.
    uint8_t getMinutes();
    // Sets the hours of the timer (0 - 1193).
    void setHours(uint16_t hours);
    // Returns the hours.
    uint16_t getHours();


    /* ELAPSED TIME */

    // Returns the total elapsed milliseconds since the start.
    uint32_t getTotalElapsedMilliseconds();
    // Returns the elapsed milliseconds.
    uint16_t getElapsedMilliseconds();
    // Returns the elapsed seconds.
    uint8_t getElapsedSeconds();
    // Returns the elapsed minutes.
    uint8_t getElapsedMinutes();
    // Returns the elapsed hours.
    uint16_t getElapsedHours();


    /*-- REMAINING TIME --*/

    // Returns the total remaining milliseconds since the start.
    uint32_t getTotalRemainingMilliseconds();
    // Returns the remaining milliseconds.
    uint16_t getRemainingMilliseconds();
    // Returns the remaining seconds.
    uint8_t getRemainingSeconds();
    // Returns the elapsed minutes.
    uint8_t getRemainingMinutes();
    // Returns the remaining hours.
    uint16_t getRemainingHours();


  private:
    /* --- METHODS --- */

    // calculates the time of the timer in milliseconds
    void calculateTotalMilliseconds();


    /* --- VARIABLES --- */

    uint16_t _milliseconds = 0;   // 0 - 999
    uint8_t _seconds = 0;         // 0 - 59
    uint8_t _minutes = 0;         // 0 - 59
    uint16_t _hours = 0;          // 0 - 1193

    uint32_t _startTimestamp = 0;
    uint32_t _totalTimerMilliseconds = 0;

    bool _timerPaused = false;
    uint32_t _pauseTimestamp = 0;
    uint32_t _pauseTime = 0;
};
#endif