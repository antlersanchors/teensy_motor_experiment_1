// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

int p;

void setup() {
  MotorA.init(); // initialize our motor objects
  MotorB.init();
  
}

void loop() {
  
  p++; 
  
  int posA = analogRead(A1); // MotorA's sensor, range from 0-1023
  int posB = analogRead(A9);
  
  int torqueA = (posB - posA);
  int torqueB = (posA - posB);
  
  if (p % 200 == 0) { 
    Serial.print("posA: ");
    Serial.println(posA);
    Serial.print("torqueA: ");
    Serial.println(torqueA);
  }
  
  if (p % 200 == 0) { 
    Serial.print("posB: ");
    Serial.println(posB);
    Serial.print("torqueB: ");
    Serial.println(torqueB);
  }
  
  MotorA.torque(torqueA);
  
  MotorB.torque(torqueB);
   
}
