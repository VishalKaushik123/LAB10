/*
 * Project LAB10
 * Description:
 * Author:
 * Date:
 */
#include <Wire.h>

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

// output to led
void receiveEvent(int howMany) {
  char x = Wire.read();          
  if(x == '0'){
    digitalWrite(D7, LOW);
  }
  else if (x == '1'){
    digitalWrite(D7, HIGH);
  }
}

// send input from button
void requestEvent() {
  Wire.write(digitalRead(D6));
}



// setup() runs once, when the device is first turned on.

void setup()
{
  pinMode(D7, OUTPUT); // LED
  pinMode(D6, INPUT);  // BUTTON

  Wire.begin(0x2A); // Initialize as a slave with address 0x2A
  
  Wire.onReceive(receiveEvent);
  Serial.println(Wire.read());
  
  
  Wire.onRequest(requestEvent);
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{

}