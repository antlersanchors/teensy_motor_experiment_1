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
  int torqueA = (512 - posA);
  
  if (p % 200 == 0) { 
    Serial.print("posA: ");
    Serial.println(posA);
    Serial.print("torqueA: ");
    Serial.println(torqueA);
  }
  
  MotorA.torque(torqueA);
  
  posA = analogRead(A1);
  torqueA = (0 - posA);
  
  if (p % 200 == 0) { 
    Serial.print("new posA: ");
    Serial.println(posA);
    Serial.print("new torqueA: ");
    Serial.println(torqueA);
  }
  
  MotorA.torque(torqueA);
   
}
