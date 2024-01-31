/*
  DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
  Created by Donut Studio, January 30, 2024.
  Released into the public domain.
*/

#ifndef DonutStudioTimer.h
#define DonutStudioTimer.h

#include "Arduino.h"


class Timer
{
  /* --- PUBLIC --- */
  public:
    /* --- CONSTRUCTOR --- */

    // constructs a timer object with given values
    Timer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0, bool instantStart = false);


    /* --- METHODS --- */

    /* MAIN */

    // start the timer
    void start();
    // stop the timer
    void stop();
    // returns true if the timer was started
    bool isActive();
    // returns true if the countdown has ended (or the timer is stopped)
    bool hasEnded();
    // pause or resume the timer
    void setPause(bool value);
    // returns true if the timer is paused
    bool isPaused();


    /* SETTINGS */

    // set the countdown time
    void setTimer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0);
    // set the milliseconds of the timer (maximum: 999)
    void setMilliseconds(int milliseconds);
    // returns the milliseconds
    int getMilliseconds();
    // set the seconds of the timer (maximum: 59)
    void setSeconds(int seconds);
    // returns the seconds
    int getSeconds();
    // set the minutes of the timer (maximum: 59)
    void setMinutes(int minutes);
    // returns the minutes
    int getMinutes();
    // set the hours of the timer (maximum: 1151)
    void setHours(int hours);
    // returns the hours
    int getHours();


    /* ELAPSED TIME */

    // returns the elapsed milliseconds since the start, or the countdown time if the timer wasn't started
    unsigned long getTotalElapsedMilliseconds();
    // returns the elapsed milliseconds (0-999)
    int getElapsedMilliseconds();
    // returns the elapsed seconds (0-59)
    int getElapsedSeconds();
    // returns the elapsed minutes (0-59)
    int getElapsedMinutes();
    // returns the elapsed hours
    int getElapsedHours();


    /*-- REMAINING TIME --*/

    // returns the remaining milliseconds
    unsigned long getTotalRemainingMilliseconds();
    // returns the remaining milliseconds (0-999)
    int getRemainingMilliseconds();
    // returns the remaining seconds (0-59)
    int getRemainingSeconds();
    // returns the elapsed minutes (0-59)
    int getRemainingMinutes();
    // returns the remaining hours
    int getRemainingHours();


  /* --- PRIVATE --- */
  private:
    /* --- METHODS --- */

    // calculates the time of the timer in milliseconds
    void calculateTimerValue();


    /* --- VARIABLES --- */

    int _milliseconds = 0;
    int _seconds = 0;
    int _minutes = 0;
    int _hours = 0;

    bool _timerStarted = false;
    unsigned long _startTimestamp;
    unsigned long _maxTimerValue;

    bool _timerPaused = false;
    unsigned long _pauseTimestamp;
    unsigned long _pauseTime;
};
#endif