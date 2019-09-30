#include <Arduino.h>
#include <../lib/LibRobUS/src/LibRobus.h>
#include <Structure/PID.h>

#define consigne 0.25
bool stop = false;
void setup() {
  BoardInit();
}

void loop() {

  PID pid = PID(consigne);
  if(ROBUS_IsBumper(3)){
    MOTOR_SetSpeed(0, consigne);
    MOTOR_SetSpeed(1, consigne);

    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0)){
        //MOTOR_SetSpeed(1, pid.get(vitesseMoteur, 0 , 100));
        delay(100);
      }
  }
  MOTOR_SetSpeed(1, 0);
  MOTOR_SetSpeed(0, 0);
}

void execute(){

}