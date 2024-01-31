/*
  DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
  Created by Donut Studio, January 30, 2024.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DonutStudioTimer.h"

/* --- CONSTRUCTOR --- */

Timer::Timer(int hours, int minutes, int seconds, int milliseconds, bool instantStart)
{
  setTimer(hours, minutes, seconds, milliseconds);

  if (instantStart)
    start();
}


/* --- METHODS --- */
/* MAIN */

void Timer::start()
{
  calculateTimerValue();
  _startTimestamp = millis();
  _timerStarted = true;

  _timerPaused = false;
  _pauseTime = 0;
}
void Timer::stop()
{
  _timerStarted = false;
  _timerPaused = false;
}
bool Timer::isActive()
{
  return _timerStarted;
}
bool Timer::hasEnded()
{
  if (_timerStarted)
    return getTotalElapsedMilliseconds() >= _maxTimerValue;
  return true;
}
void Timer::setPause(bool value)
{
  _timerPaused = value;
  if (value)
    _pauseTimestamp = millis();
  else
    _pauseTime += millis() - _pauseTimestamp;
}
bool Timer::isPaused()
{
  return _timerPaused;
}


/* SETTINGS */

void Timer::setTimer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0)
{
  if (milliseconds >= 0)
    _milliseconds = milliseconds % 1000;
  if (seconds >= 0)
    _seconds = seconds % 60;
  if (minutes >= 0)
    _minutes = minutes % 60;
  if (hours >= 0 && hours < 1152)
    _hours = hours;

  calculateTimerValue();
}
void Timer::setMilliseconds(int milliseconds)
{
  if (milliseconds < 0)
    return;
  _milliseconds = milliseconds % 1000;
  calculateTimerValue();
}
int Timer::getMilliseconds()
{
  return _milliseconds;
}
void Timer::setSeconds(int seconds)
{
  if (seconds < 0)
    return;
  _seconds = seconds % 60;
  calculateTimerValue();
}
int Timer::getSeconds()
{
  return _seconds;
}
void Timer::setMinutes(int minutes)
{
  if (minutes < 0)
    return;
  _minutes = minutes % 60;
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
  _hours = hours;
  calculateTimerValue();
}
int Timer::getHours()
{
  return _hours;
}


/* ELAPSED TIME */

unsigned long Timer::getTotalElapsedMilliseconds()
{
  // timer is not started => return the maximal value
  if (!_timerStarted)
    return _maxTimerValue;

  unsigned long mil = millis();
  unsigned long elapsed = mil - _startTimestamp - _pauseTime;
  if (_timerPaused)
    return elapsed - mil + _pauseTimestamp;
  return elapsed;
}
int Timer::getElapsedMilliseconds()
{
  return (int)(getTotalElapsedMilliseconds() % 1000);
}
int Timer::getElapsedSeconds()
{
  return (int)((getTotalElapsedMilliseconds() / 1000) % 60);
}
int Timer::getElapsedMinutes()
{
  return (int)((getTotalElapsedMilliseconds() / 1000 / 60) % 60);
}
int Timer::getElapsedHours()
{
  return (int)(getTotalElapsedMilliseconds() / 1000 / 3600);
}


/* REMAINING TIME */

unsigned long Timer::getTotalRemainingMilliseconds()
{
  unsigned long elapsed = getTotalElapsedMilliseconds();
  if (elapsed >= _maxTimerValue)
    return 0;
  return _maxTimerValue - elapsed;
}
int Timer::getRemainingMilliseconds()
{
  return (int)(getTotalRemainingMilliseconds() % 1000);
}
int Timer::getRemainingSeconds()
{
  return (int)((getTotalRemainingMilliseconds() / 1000) % 60);
}
int Timer::getRemainingMinutes()
{
  return (int)((getTotalRemainingMilliseconds() / 1000 / 60) % 60);
}
int Timer::getRemainingHours()
{
  return (int)(getTotalRemainingMilliseconds() / 1000 / 3600);
}


/* --- PRIVATE --- */

void Timer::calculateTimerValue()
{
  unsigned long sec = (unsigned long)_seconds * 1000;
  unsigned long min = (unsigned long)_minutes * 60 * 1000;
  unsigned long hrs = (unsigned long)_hours * 3600 * 1000;

  _maxTimerValue = sec + min + hrs + _milliseconds;
}