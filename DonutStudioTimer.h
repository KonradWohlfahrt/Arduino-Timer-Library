/*
  DonutStudioTimer.h - Library for creating a timer with the millis()-function from the arduino.
  Created by Donut Studio, March 04, 2023.
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

    /*-- timer --*/

    // starts the timer
    void startTimer();
    // stops the timer
    void stopTimer();
    // returns false if the timer is still running, true if not or the timer is stopped
    bool hasEnded();


    /*-- set --*/

    // sets the milliseconds of the timer (maximum: 999)
    void setMilliseconds(int milliseconds);
    // sets the seconds of the timer (maximum: 59)
    void setSeconds(int seconds);
    // sets the minutes of the timer (maximum: 59)
    void setMinutes(int minutes);
    // sets the hours of the timer (maximum: 1152)
    void setHours(int hours);


    /*-- get total elapsed --*/

    // returns the elapsed milliseconds since the start 
    unsigned long getTotalElapsedMilliseconds();
    // returns the elapsed seconds since the start
    unsigned long getTotalElapsedSeconds();
    // returns the elapsed minutes since the start
    unsigned long getTotalElapsedMinutes();

    // returns the elapsed hours
    int getElapsedHours();


    /*-- get total remaining --*/

    // returns the remaining milliseconds
    unsigned long getTotalRemainingMilliseconds();
    // returns the remaining seconds
    unsigned long getTotalRemainingSeconds();
    // returns the remaining minutes
    unsigned long getTotalRemainingMinutes();

    // returns the remaining hours
    int getRemainingHours();


    /*-- get elapsed --*/

    // returns the elapsed milliseconds (0-999)
    int getElapsedMilliseconds();
    // returns the elapsed seconds (0-59)
    int getElapsedSeconds();
    // returns the elapsed minutes (0-59)
    int getElapsedMinutes();


    /*-- get remaining --*/

    // returns the remaining milliseconds (0-999)
    int getRemainingMilliseconds();
    // returns the remaining seconds (0-59)
    int getRemainingSeconds();
    // returns the remaining minutes (0-59)
    int getRemainingMinutes();


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