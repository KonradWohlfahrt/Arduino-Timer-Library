/*
  DonutStudioTimer.h - Arduino library for creating a timer with the millis()-function.
  Created by Konrad Wohlfahrt, July 03, 2025.
  Released into the public domain.
*/

// include the libraray
#include <DonutStudioTimer.h>

// connect a push button to digital pin 2
#define BUTTON 2

// create an object of the Timer class and set the timer to 00h:01m:30s
Timer t = Timer(0, 1, 30);


void setup() 
{
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);

  printTimer();

  Serial.println("starting timer...");
  t.begin();
}
void loop() 
{
  if (t.isOver())
  {
    t.setMinutes(0);
    t.setSeconds((int)random(0, 60));
    t.begin();
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
  Serial.print(t.getTotalElapsedMilliseconds());
  Serial.print(" - ");
  Serial.print(t.getElapsedHours());
  Serial.print(":");
  Serial.print(t.getElapsedMinutes());
  Serial.print(":");
  Serial.print(t.getElapsedSeconds());
  Serial.print(":");
  Serial.print(t.getElapsedMilliseconds());

  Serial.print("  ");
  
  Serial.print("remaining: ");
  Serial.print(t.getTotalRemainingMilliseconds());
  Serial.print(" - ");
  Serial.print(t.getRemainingHours());
  Serial.print(":");
  Serial.print(t.getRemainingMinutes());
  Serial.print(":");
  Serial.print(t.getRemainingSeconds());
  Serial.print(":");
  Serial.print(t.getRemainingMilliseconds());


  Serial.println();
}