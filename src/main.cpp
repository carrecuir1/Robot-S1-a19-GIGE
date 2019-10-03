#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define consigne 0.25
bool stop = false;
void setup() {
  BoardInit();
}

void loop() {

  PID pid = PID(consigne);
  Motor motor = Motor();
  if(ROBUS_IsBumper(3)){
    motor.angleTurn(45,consigne);
    /*MOTOR_SetSpeed(0, consigne);
    delay(100);
    MOTOR_SetSpeed(1, consigne);

    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0)){
        //MOTOR_SetSpeed(1, pid.get(vitesseMoteur, 0 , 100));
        float patate = pid.getPID();
        MOTOR_SetSpeed(1,patate);
        delay(100);
      }*/
  }
  MOTOR_SetSpeed(1, 0);
  MOTOR_SetSpeed(0, 0);

  if(ROBUS_IsBumper(2))
  {
    motor.demiTour();
  }
  
}

void execute(){

}