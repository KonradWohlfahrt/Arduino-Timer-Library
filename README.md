# TIMER LIBRARY README
Welcome!
This is my solution for the arduino to create a timer.
Keep in mind that the oscillator of the arduino is not very preciced and will differ after a few hours.
Feel free to use it anywere in your projects.
Cheers, Donut Studio!


***
# Features
- set the countdown time
- start/stop and pause/resume the timer
- get the remaining and elapsed time


***
# Installation
1. download the `DonutStudioTimer` folder and extract it into the libraries folder of the Arduino Software
2. start your arduino ide and open the example sketch at `File/Examples/DonutStudioTimer/TimerTest.ino`
3. upload the sketch and take a look at the serial monitor


***
# Usage
To use the library you have to include it in your sketch and create one or multiple objects of the Timer class. 
Then you can call functions to start and stop counting or get the elapsed/remaining time.
Sample code:
```cpp
// include the libraray
#include <DonutStudioTimer.h>

// 00h : 01m : 30s
Timer t1 = Timer(0, 1, 30); 
// 01h : 01m : 01s : 01ms + start counting
Timer t2 = Timer(1, 1, 1, 1, true); 

// start the timer
t1.start();
// stop the timer
t2.stop();

// get timer values
int sec = t2.getRemainingSeconds();
int min = t2.getRemainingMinutes();
bool val = t1.isActive();
```


***
# Documentation
CONSTRUCTOR
- `Timer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0, bool instantStart = false);` => constructs a timer object with given values

TIMER
- `void start();` => start the timer
- `void stop();` => stop the timer
- `bool isActive();` => returns true if the timer was started
- `bool hasEnded();` => returns true if the countdown has ended (or the timer is stopped)
- `void setPause();` => pause or resume the timer
- `bool isPaused();` => returns true if the timer is paused

SETTINGS
- `void setTimer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0);` => set the countdown time
- `void setMilliseconds(int milliseconds);` => set the milliseconds of the timer (maximum: 999)
- `int getMilliseconds();` => returns the milliseconds
- `void setSeconds(int seconds);` => set the seconds of the timer (maximum: 59)
- `int getSeconds();` => returns the seconds
- `void setMinutes(int minutes);` => set the minutes of the timer (maximum: 59)
- `int getMinutes();` => returns the minutes
- `void setHours(int hours);` => set the hours of the timer (maximum: 1151)
- `int getHours();` => returns the hours

ELAPSED TIME
- `unsigned long getTotalElapsedMilliseconds();` => returns the elapsed milliseconds since the start, or the countdown time if the timer wasn't started
- `int getElapsedMilliseconds();` => returns the elapsed milliseconds (0-999)
- `int getElapsedSeconds();` => returns the elapsed seconds (0-59)
- `int getElapsedMinutes();` => returns the elapsed minutes (0-59)
- `int getElapsedHours();` => returns the elapsed hours

REMAINING TIME
- `unsigned long getTotalRemainingMilliseconds();` => returns the remaining milliseconds
- `int getRemainingMilliseconds();` => returns the remaining milliseconds (0-999)
- `int getRemainingSeconds();` => returns the remaining seconds (0-59)
- `int getRemainingMinutes();` => returns the elapsed minutes (0-59)
- `int getRemainingHours();` => returns the remaining hours


***
# Credits
DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
Created by Donut Studio, January 30, 2024.
Released into the public domain.