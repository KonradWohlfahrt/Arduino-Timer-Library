/*
  DonutStudioTimer.h - Library for creating a timer with the millis()-function from the arduino.
  Created by Donut Studio, March 05, 2023.
  Released into the public domain.
*/

// include the libraray
#include "DonutStudioTimer.h"

// create an object of the Timer class and set the timer to 00:01:30
Timer t = Timer(0, 0, 10); 

void setup() 
{
  // start the serial port
  Serial.begin(9600);

  // print timer values
  printTimer();

  Serial.println("starting timer...");

  // start the timer
  t.start();
}
void loop() 
{
  if (t.hasEnded())
  {
    t.stop(); // can also be removed if you restart the timer directly
    t.setMinutes((int)random(0, 3));
    t.setSeconds((int)random(0, 60));
    t.start();
  }
  else
    printTimer();
}

void printTimer()
{
  Serial.print("elapsed: ");
  Serial.print(t.getElapsedHours());
  Serial.print(":");
  Serial.print(t.getElapsedMinutes());
  Serial.print(":");
  Serial.print(t.getElapsedSeconds());
  Serial.print(":");
  Serial.print(t.getElapsedMilliseconds());

  Serial.print(" - ");
  
  Serial.print("remaining: ");
  Serial.print(t.getRemainingHours());
  Serial.print(":");
  Serial.print(t.getRemainingMinutes());
  Serial.print(":");
  Serial.print(t.getRemainingSeconds());
  Serial.print(":");
  Serial.print(t.getRemainingMilliseconds());
  
  Serial.println();
}