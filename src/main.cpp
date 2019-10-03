#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define consigne 0.5
bool stop = false;
void setup() {
  BoardInit();
}

void loop() {

 // PID pid = PID(consigne);
  Motor motor = Motor();
  if(ROBUS_IsBumper(3)){
    motor.straightRun(100, consigne);
    motor.angleTurn(45,consigne);
    motor.straightRun(100, consigne);
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
  //MOTOR_SetSpeed(1, 0);
  //MOTOR_SetSpeed(0, 0);
  
}

void execute(){

}