#include <Arduino.h>
#include <LibGny.h>
#include <LibRobus.h>
float speed_G;
float speed_D;

void setup() {
  BoardInit();
  speed_G = 0.5;
  speed_D = 0.5;
}

void loop() {

  if(ROBUS_IsBumper(3))
  {
    Serial.println("test");
    avancerRobot(100);
    delay(100);
  }
}