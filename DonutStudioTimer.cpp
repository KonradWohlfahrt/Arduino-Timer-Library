/*
  DonutStudioTimer.h - Library for creating a timer with the millis()-function from the arduino.
  Created by Donut Studio, March 05, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DonutStudioTimer.h"

/*
  --- --- CONSTRUCTOR --- ---
*/

Timer::Timer(int hours, int minutes, int seconds, int milliseconds, bool instantStart)
{
  // set the hours of the timer
  setHours(hours);
  // set the minutes of the timer
  setMinutes(minutes);
  // set the seconds of the timer
  setSeconds(seconds);
  // set the milliseconds of the timer
  setMilliseconds(milliseconds);

  // start the timer if instantStart is set to true
  if (instantStart)
    start();
}


/*
  --- --- METHODS --- ---
*/

/*
  --- MAIN ---
*/

void Timer::start()
{
  // recalculate the time
  calculateTimerValue();
  // set the timestamp
  _timerStartTimestamp = millis();
  // set the boolean
  _timerStarted = true;
}
void Timer::stop()
{
  // set the boolean
  _timerStarted = false;
}
bool Timer::isActive()
{
  // return the started boolean
  return _timerStarted;
}
bool Timer::hasEnded()
{
  // check if the timer was started and return if it has ended yet
  if (_timerStarted)
    return getTotalElapsedMilliseconds() >= _maxTimerValue;
  // return true if the timer is not active
  return true;
}

/*
  --- SETTINGS ---
*/

void Timer::setMilliseconds(int milliseconds)
{
  // check if the milliseconds are below zero
  if (milliseconds < 0)
    return;
  // set the milliseconds
  _milliseconds = milliseconds % 1000;
  // recalculate the time
  calculateTimerValue();
}
int Timer::getMilliseconds()
{
  return _milliseconds;
}
void Timer::setSeconds(int seconds)
{
  // check if the seconds are below zero
  if (seconds < 0)
    return;
  // set the seconds
  _seconds = seconds % 60;
  // recalculate the time
  calculateTimerValue();
}
int Timer::getSeconds()
{
  return _seconds;
}
void Timer::setMinutes(int minutes)
{
  // check if the minutes are below zero
  if (minutes < 0)
    return;
  // set the minutes
  _minutes = minutes % 60;
  // recalculate the time
  calculateTimerValue();
}
int Timer::getMinutes()
{
  return _minutes;
}
void Timer::setHours(int hours)
{
  // check if the hours are below zero or greater than 1152 (48 days)
  if (hours < 0 || hours >= 1152)
    return;
  // set the hours
  _hours = hours;
  // recalculate the time
  calculateTimerValue();
}
int Timer::getHours()
{
  return _hours;
}


/*
  --- ELAPSED TIME ---
*/

unsigned long Timer::getTotalElapsedMilliseconds()
{
  // check if the timer is not active => return the maximal value
  if (!isActive())
    return _maxTimerValue;
  // calculate a duration to prevent the millis overflow
  return millis() - _timerStartTimestamp;
}
int Timer::getElapsedMilliseconds()
{
  // calculate the elapsed milliseconds
  return (int)(getTotalElapsedMilliseconds() % 1000);
}
int Timer::getElapsedSeconds()
{
  // calculate the elapsed seconds
  return (int)((getTotalElapsedMilliseconds() / 1000) % 60);
}
int Timer::getElapsedMinutes()
{
  // calculate the elapsed minutes
  return (int)((getTotalElapsedMilliseconds() / 1000 / 60) % 60);
}
int Timer::getElapsedHours()
{
  // calculate the elapsed hours
  return (int)(getTotalElapsedMilliseconds() / 1000 / 3600);
}


/*
  --- ELAPSED TIME ---
*/
unsigned long Timer::getTotalRemainingMilliseconds()
{
  // get the elapsed milliseconds
  unsigned long elapsed = getTotalElapsedMilliseconds();
  // check if the elapsed time is over or equal to the maximal time => time over, return 0
  if (elapsed >= _maxTimerValue)
    return 0;
  // calculate the remaining time
  return _maxTimerValue - elapsed;
}
int Timer::getRemainingMilliseconds()
{
  // calculate the remaining milliseconds
  return (int)(getTotalRemainingMilliseconds() % 1000);
}
int Timer::getRemainingSeconds()
{
  // calculate the remaining seconds
  return (int)((getTotalRemainingMilliseconds() / 1000) % 60);
}
int Timer::getRemainingMinutes()
{
  // calculate the remaining minutes
  return (int)((getTotalRemainingMilliseconds() / 1000 / 60) % 60);
}
int Timer::getRemainingHours()
{
  // calculate the remaining hours
  return (int)(getTotalRemainingMilliseconds() / 1000 / 3600);
}


/*
  --- --- PRIVATE --- ---
*/

void Timer::calculateTimerValue()
{
  // calculate the milliseconds from the seconds
  unsigned long sec = (unsigned long)_seconds * 1000;
  // calculate the milliseconds from the minutes
  unsigned long min = (unsigned long)_minutes * 60 * 1000;
  // calculate the milliseconds from the hours
  unsigned long hrs = (unsigned long)_hours * 3600 * 1000;
  // add the milliseconds, seconds, minutes and hours together
  _maxTimerValue = sec + min + hrs + _milliseconds;
}