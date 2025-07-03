# TIMER LIBRARY README
Welcome!
This is my solution for the arduino to create a timer.
Keep in mind that the oscillator of the arduino is not very preciced and will differ after a few hours.
Feel free to use it anywere in your projects.
Cheers, Donut Studio!


***
# Features
- set the countdown time
- pause/resume the timer
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
Timer t(0, 1, 30);

void setup() {
    // start the timer
    t.start();

    // get timer values
    int sec = t.getElapsedMilliseconds();
    int min = t.getRemainingMinutes();
    bool val = t.isPaused();
}
```
After you have changed the timer values, a call of `start()` will update the changes and restart the timer.


***
# Documentation
CONSTRUCTOR
- `Timer(uint16_t hours = 0, uint8_t minutes = 0, uint8_t seconds = 0, uint16_t milliseconds = 0);` => Constructs a timer object and sets the countdown time.

TIMER
- `void begin();` => Starts the countdown from this timestamp.
- `bool isOver();` => Returns true if the current timestamp exceeds the countdown, false otherwise.
- `void setPause(bool value);` => Pause or resume the countdown.
- `bool isPaused();` => Returns true if the countdown is paused, false otherwise.

SETTINGS
- `void setTimer(uint16_t hours = 0, uint8_t minutes = 0, uint8_t seconds = 0, uint16_t milliseconds = 0);` => Sets the countdown time.
- `uint32_t getTotalMilliseconds();` => Returns the total countdown time in milliseconds.
- `void setMilliseconds(uint16_t milliseconds);` => Sets the milliseconds (0 - 999).
- `uint16_t getMilliseconds();` => Returns the milliseconds.
- `void setSeconds(uint8_t seconds);` => Sets the seconds (0 - 59).
- `uint8_t getSeconds();` => Returns the seconds.
- `void setMinutes(uint8_t minutes);` => Sets the minutes of the timer (0 - 59).
- `uint8_t getMinutes();` => Returns the minutes.
- `void setHours(uint16_t hours);` => Sets the hours of the timer (0 - 1193).
- `uint16_t getHours();` => Returns the hours.

ELAPSED TIME
- `uint32_t getTotalElapsedMilliseconds();` => Returns the total elapsed milliseconds since the start.
- `uint16_t getElapsedMilliseconds();` => Returns the elapsed milliseconds.
- `uint8_t getElapsedSeconds();` => Returns the elapsed seconds.
- `uint8_t getElapsedMinutes();` => Returns the elapsed minutes.
- `uint16_t getElapsedHours();` => Returns the elapsed hours.

REMAINING TIME
- `uint32_t getTotalRemainingMilliseconds();` => Returns the total remaining milliseconds since the start.
- `uint16_t getRemainingMilliseconds();` => Returns the remaining milliseconds.
- `uint8_t getRemainingSeconds();` => Returns the remaining seconds.
- `uint8_t getRemainingMinutes();` => Returns the elapsed minutes.
- `uint16_t getRemainingHours();` => Returns the remaining hours.


***
# Credits
DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
Created by Konrad Wohlfahrt, July 03, 2025.
Released into the public domain.