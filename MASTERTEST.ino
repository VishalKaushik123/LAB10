/*
 * Project LAB10
 * Description:
 * Author:
 * Date:
 */
#include <Wire.h>

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.

void setup()
{
  Serial.begin(9600);

  Wire.begin(); // Initialize as a master
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  while (!Serial.isConnected());
  if (Serial.available())
  {
    char value = Serial.read(); //Reads a single value

    // if user wants to get input from button
    if (value == '?')
    {
      Wire.requestFrom(0x2A, 1);
      while (Wire.available() == 0);
      Serial.println(Wire.read());
    }
    // if user wants to turn the led on/off
    else if(value == '0' || value == '1')
    {
      Wire.beginTransmission(0x2A);
      Wire.write(value);
      Wire.endTransmission();
    }
  }
}