// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

void setup() {
  MotorA.init(); // initialize our motor objects
  MotorB.init();
  
}

void loop() {
  int posA = analogRead(A1); // MotorA's sensor, range from 0-1023
  Serial.print("posA: ");
  Serial.println(posA);
  
  int torqueA = (512 - posA);
  Serial.print("torqueA: ");
  Serial.println(torqueA);
  
  MotorA.torque(torqueA);
  
  delay(1000);
  
  posA = analogRead(A1);
  Serial.print("new posA: ");
  Serial.println(posA);
  
  torqueA = (0 - posA);
  Serial.print("new torqueA: ");
  Serial.println(posA);
  
  MotorA.torque(torqueA);
  
  
  
}
