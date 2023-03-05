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
# TODO
- pause and resume the timer


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
Timer t1 = Timer(0, 1, 30); 
// create an object of the Timer class and set the timer to 1 hour, 1 minute, 1 second, 1 millisecond and start to count down
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
- `Timer(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0, bool instantStart = false);` => constructor for the class 

TIMER
- `void start();` => starts the timer
- `void stop();` => stops the timer
- `bool isActive();` => returns false if the timer is still running, true if not or the timer is stopped

SETTINGS
- `void setMilliseconds(int milliseconds);` => sets the milliseconds of the timer (maximum: 999)
- `int getMilliseconds();` => returns the set milliseconds
- `void setSeconds(int seconds);` => sets the seconds of the timer (maximum: 59)
- `int getSeconds();` => returns the set seconds

- `void setMinutes(int minutes);` => sets the minutes of the timer (maximum: 59)
- `int getMinutes();` => returns the set minutes
- `void setHours(int hours);` => sets the hours of the timer (maximum: 1152)
- `int getHours();` => returns the set hours

ELAPSED TIME
- `unsigned long getTotalElapsedMilliseconds();` => returns the elapsed milliseconds since the start, if the timer is not active, it will return the set time 
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
DonutStudioTimer.h - Library for creating a timer with the millis()-function from the arduino.
Created by Donut Studio, March 05, 2023.
Released into the public domain.