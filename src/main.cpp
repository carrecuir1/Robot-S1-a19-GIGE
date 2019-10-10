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
        motor.straightRun(240, consigne);
        delay(10);
        motor.angleTurn(-90,consigne);
        delay(10);
        motor.straightRun(90, consigne);
        delay(10);
        motor.angleTurn(90,consigne);
        delay(10);
        motor.straightRun(45, consigne);
        delay(10);
        motor.angleTurn(90,consigne);
        delay(10);
        motor.straightRun(55, 0.5);
        delay(10);
        motor.angleTurn(-90,consigne);
        delay(10);
        motor.straightRun(110, consigne);
        delay(10);
        motor.angleTurn(90,consigne);
        delay(10);
        motor.straightRun(45, consigne);
        delay(10);
        motor.angleTurn(-90,consigne);
        delay(10);
        motor.straightRun(110, consigne);
        delay(10);
        //MILIEUX 
        /*
        motor.demiTour(consigne);
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
        */
       
        motor.demiTour(consigne);
        motor.demiTour(consigne);
        motor.demiTour(consigne);
        motor.demiTour(consigne);
        test = false;
    }
  }
}
