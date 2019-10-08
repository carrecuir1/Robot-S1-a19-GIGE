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

  PID pid = PID(consigne);
  Motor motor = Motor(consigne);
  /*if(ROBUS_IsBumper(0)){
    motor.demiTour(consigne);
  }*/

  if(ROBUS_IsBumper(3)){
    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0) and test == true){
        //MOTOR_SetSpeed(1, pid.get(vitesseMoteur, 0 , 100));
        motor.straightRun(122);
        delay(100);
        motor.angleTurn(-90);
        delay(100);
        motor.straightRun(70);
        delay(100);
        motor.angleTurn(90);
        delay(100);
        motor.straightRun(70);
        delay(100);
        motor.angleTurn(45);
        delay(100);
        motor.straightRun(175);
        delay(100);
        motor.angleTurn(-90);
        delay(100);
        motor.straightRun(50);
        delay(100);
        motor.angleTurn(45);
        delay(100);
        motor.straightRun(120);
        delay(100);
        //MILIEUX 
        motor.uTurn();
        delay(100);
        motor.straightRun(120);
        delay(100);
        motor.angleTurn(-45);
        delay(100);
        motor.straightRun(50);
        delay(100);
        motor.angleTurn(90);
        delay(100);
        motor.straightRun(175);
        delay(100);
        motor.angleTurn(-45);
        delay(100);
        motor.straightRun(70);
        delay(100);
        motor.angleTurn(-90);
        delay(100);
        motor.straightRun(70);
        delay(100);
        motor.angleTurn(90);
        delay(100);
        motor.straightRun(122);
        delay(100);
        motor.uTurn();
        motor.uTurn();
        motor.uTurn();
        motor.uTurn();
        test = false;
    }
  }
}
