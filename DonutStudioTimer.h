/*
  DonutStudioTimer.h - Library for creating a timer with the millis()-function from the arduino.
  Created by Donut Studio, March 05, 2023.
  Released into the public domain.
*/

#ifndef DonutStudioTimer.h
#define DonutStudioTimer.h

#include "Arduino.h"


class Timer
{
  /*
    --- PUBLIC ---
  */
  public:
    /*
      --- CONSTRUCTOR ---
    */

    // constructor for the class 
    Timer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0, bool instantStart = false);


    /*
      --- METHODS ---
    */

    /*-- MAIN --*/

    // starts the timer
    void start();
    // stops the timer
    void stop();
    // returns false if the timer is still running, true if not or the timer is stopped
    bool isActive();


    /*-- SETTINGS --*/

    // sets the milliseconds of the timer (maximum: 999)
    void setMilliseconds(int milliseconds);
    // returns the set milliseconds
    int getMilliseconds();
    // sets the seconds of the timer (maximum: 59)
    void setSeconds(int seconds);
    // returns the set seconds
    int getSeconds();
    // sets the minutes of the timer (maximum: 59)
    void setMinutes(int minutes);
    // returns the set minutes
    int getMinutes();
    // sets the hours of the timer (maximum: 1152)
    void setHours(int hours);
    // returns the set hours
    int getHours();


    /*-- ELAPSED TIME --*/

    // returns the elapsed milliseconds since the start, if the timer is not active, it will return the set time 
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


  /*
    --- PRIVATE ---
  */
  private:
    /*
      --- METHODS ---
    */

    // calculates the time of the timer in milliseconds
    void calculateTimerValue();


    /*
      --- VARIABLES ---
    */
    int _milliseconds = 0;
    int _seconds = 0;
    int _minutes = 0;
    int _hours = 0;

    bool _timerStarted = false;
    unsigned long _timerStartTimestamp;
    unsigned long _maxTimerValue;
};
#endif