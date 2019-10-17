#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define consigne 0.35
bool test;
void setup() {
  BoardInit();
  test = true;
}

void loop() {

  Motor motor = Motor(consigne);

  if(ROBUS_IsBumper(3)){
    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0) and test == true){

        test = false;
    }
  }
}
