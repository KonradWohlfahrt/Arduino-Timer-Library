/*
  DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
  Created by Donut Studio, January 30, 2024.
  Released into the public domain.
*/

// include the libraray
#include <DonutStudioTimer.h>

// connect GND and pin 2 to toggle pausing
#define BUTTON 2

// create an object of the Timer class and set the timer to 00h:01m:30s
Timer t = Timer(0, 1, 30); 


void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);

  printTimer();

  Serial.println("starting timer...");

  t.start();
}
void loop() 
{
  if (t.hasEnded())
  {
    t.setMinutes(0);
    t.setSeconds((int)random(0, 60));
    t.start();
  }
  else
    printTimer();

  if (digitalRead(BUTTON) == 0)
  {
    while (digitalRead(BUTTON) == 0);
    t.setPause(!t.isPaused());
    Serial.println("toggled pause...");
  }
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