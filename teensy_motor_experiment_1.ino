// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

void setup() {
  MotorA.init(); // initialize our motor objects
  MotorB.init();
  
}

void loop() {
  MotorA.torque(195); // takes a value from -512 to 512 (< 195 to overcome inertia)
  delay(1000);
  MotorA.torque(0);
  delay(2000);
  MotorA.torque(-512);
  delay(1000);
}
