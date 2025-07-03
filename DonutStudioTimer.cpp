/*
  DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
  Created by Konrad Wohlfahrt, July 03, 2025.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DonutStudioTimer.h"

Timer::Timer(uint16_t hours, uint8_t minutes, uint8_t seconds, uint16_t milliseconds)
{
  setTimer(hours, minutes, seconds, milliseconds);
  calculateTotalMilliseconds();
}


void Timer::begin()
{
  calculateTotalMilliseconds();
  _startTimestamp = millis();
  _timerPaused = false;
  _pauseTime = 0;
}
bool Timer::isOver()
{
  return getTotalElapsedMilliseconds() >= _totalTimerMilliseconds;
}
void Timer::setPause(bool value)
{
  if (_timerPaused == value)
    return;

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


void Timer::setTimer(uint16_t hours, uint8_t minutes, uint8_t seconds, uint16_t milliseconds)
{
  setMilliseconds(milliseconds);
  setSeconds(seconds);
  setMinutes(minutes);
  setHours(hours);
}
uint32_t Timer::getTotalMilliseconds() 
{
  calculateTotalMilliseconds();
  return _totalTimerMilliseconds;
}
void Timer::setMilliseconds(uint16_t milliseconds)
{
  _milliseconds = milliseconds % 1000;
}
uint16_t Timer::getMilliseconds()
{
  return _milliseconds;
}
void Timer::setSeconds(uint8_t seconds)
{
  _seconds = seconds % 60;
}
uint8_t Timer::getSeconds()
{
  return _seconds;
}
void Timer::setMinutes(uint8_t minutes)
{
  _minutes = minutes % 60;
}
uint8_t Timer::getMinutes()
{
  return _minutes;
}
void Timer::setHours(uint16_t hours)
{
  if (hours > 1193)
    return;
  _hours = hours;
}
uint16_t Timer::getHours()
{
  return _hours;
}


uint32_t Timer::getTotalElapsedMilliseconds()
{
  uint32_t mil = millis();
  uint32_t elapsed = mil - _startTimestamp - _pauseTime;
  if (_timerPaused)
    return elapsed - mil + _pauseTimestamp;
  return elapsed;
}
uint16_t Timer::getElapsedMilliseconds()
{
  return (uint16_t)(getTotalElapsedMilliseconds() % 1000);
}
uint8_t Timer::getElapsedSeconds()
{
  return (uint8_t)((getTotalElapsedMilliseconds() / 1000) % 60);
}
uint8_t Timer::getElapsedMinutes()
{
  return (uint8_t)((getTotalElapsedMilliseconds() / 1000 / 60) % 60);
}
uint16_t Timer::getElapsedHours()
{
  return (uint16_t)(getTotalElapsedMilliseconds() / 1000 / 3600);
}


uint32_t Timer::getTotalRemainingMilliseconds()
{
  uint32_t elapsed = getTotalElapsedMilliseconds();
  if (elapsed >= _totalTimerMilliseconds)
    return 0;
  return _totalTimerMilliseconds - elapsed;
}
uint16_t Timer::getRemainingMilliseconds()
{
  return (uint16_t)(getTotalRemainingMilliseconds() % 1000);
}
uint8_t Timer::getRemainingSeconds()
{
  return (uint8_t)((getTotalRemainingMilliseconds() / 1000) % 60);
}
uint8_t Timer::getRemainingMinutes()
{
  return (uint8_t)((getTotalRemainingMilliseconds() / 1000 / 60) % 60);
}
uint16_t Timer::getRemainingHours()
{
  return (uint16_t)(getTotalRemainingMilliseconds() / 1000 / 3600);
}


void Timer::calculateTotalMilliseconds()
{
  uint32_t sec = (uint32_t)_seconds * 1000;
  uint32_t min = (uint32_t)_minutes * 60 * 1000;
  uint32_t hrs = (uint32_t)_hours * 3600 * 1000;

  _totalTimerMilliseconds = sec + min + hrs + _milliseconds;
}