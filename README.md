# TIMER LIBRARY README
Welcome!
This is my solution for using the millis function to create a timer.
Keep in mind that the oscillator of the arduino is not very preciced and will differ after a few hours.
Feel free to use it anywere in your projects.
Cheers, Donut Studio!


***
# Features
- set the countdown time
- start and stop the timer
- get the remaining time
- check if the time is over


***
# Installation
1. download the `DonutStudioTimer` folder and extract it into the libraries folder of the Arduino Software
2. start your arduino ide and open the example sketch at `File/Examples/DonutStudioTimer/TimerTest.ino`
3. upload the sketch and watch


***
# Usage
To use the library you have to include it in your sketch and create one or multiple objects of the Timer class. 
Then you can call functions to start and stop counting or get the elapsed/remaining time.
Sample code:
```cpp
// include the libraray
#include "DonutStudioTimer.h"

// create an object of the Timer class and set the timer to 1 minute and 30 seconds
Timer t = Timer(0, 1, 30); 

// start the timer
t.startTimer();

// start the timer
int sec = t.getRemainingSeconds();
int min = t.getRemainingMinutes();
if (t.hasEnded())
    t.stopTimer();
```


***
# Documentation
CONSTRUCTOR
- `Timer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0, bool instantStart = false);` => constructor for the class 

TIMER
- `void startTimer();` => starts the timer
- `void stopTimer();` => stops the timer
- `bool hasEnded();` => returns false if the timer is still running, true if not or the timer is stopped

SET
- `void setMilliseconds(int milliseconds);` => sets the milliseconds of the timer (maximum: 999)
- `void setSeconds(int seconds);` => sets the seconds of the timer (maximum: 59)
- `void setMinutes(int minutes);` => sets the minutes of the timer (maximum: 59)
- `void setHours(int hours);` => sets the hours of the timer (maximum: 1152)

GET TOTAL ELAPSED
- `unsigned long getTotalElapsedMilliseconds();` => returns the elapsed milliseconds since the start 
- `unsigned long getTotalElapsedSeconds();` => returns the elapsed seconds since the start
- `unsigned long getTotalElapsedMinutes();` => returns the elapsed minutes since the start
- `int getElapsedHours();` => returns the elapsed hours

GET TOTAL REMAINING
- `unsigned long getTotalRemainingMilliseconds();` => returns the remaining milliseconds
- `unsigned long getTotalRemainingSeconds();` => returns the remaining seconds
- `unsigned long getTotalRemainingMinutes();` => returns the remaining minutes
- `int getRemainingHours();` => returns the remaining hours

GET ELAPSED
- `int getElapsedMilliseconds();` => returns the elapsed milliseconds (0-999)
- `int getElapsedSeconds();` => returns the elapsed seconds (0-59)
- `int getElapsedMinutes();` => returns the elapsed minutes (0-59)

GET REMAINING
- `int getRemainingMilliseconds();` => returns the remaining milliseconds (0-999)
- `int getRemainingSeconds();` => returns the remaining seconds (0-59)
- `int getRemainingMinutes();` => returns the remaining minutes (0-59)


***
# Credits
DonutStudioTimer.h - Library for creating a timer with the millis()-function from the arduino.
Created by Donut Studio, March 04, 2023.
Released into the public domain.