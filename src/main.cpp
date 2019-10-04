#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define consigne 0.3

void setup() {
  BoardInit();
}

void loop() {

  PID pid = PID(consigne);
  Motor motor = Motor();
  bool test = true;
  if(ROBUS_IsBumper(3)){


    //ENCODER_Reset(0);
    //ENCODER_Reset(1);

    //MOTOR_SetSpeed(0, consigne);
    //delay(100);
    //MOTOR_SetSpeed(1, consigne);

    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0) and test == true){
        //MOTOR_SetSpeed(1, pid.get(vitesseMoteur, 0 , 100));
        motor.straightRun(115, consigne);
        delay(10);
        motor.angleTurn(-85,consigne);
        delay(10);
        motor.straightRun(75, consigne);
        delay(10);
        motor.angleTurn(90,consigne);
        delay(10);
        motor.straightRun(65, consigne);
        delay(10);
        motor.angleTurn(42,consigne);
        delay(10);
        motor.straightRun(185, 0.5);
        delay(10);
        motor.angleTurn(-95,consigne);
        delay(10);
        motor.straightRun(60, consigne);
        delay(10);
        motor.angleTurn(40,consigne);
        delay(10);
        motor.straightRun(120, consigne);
        delay(10);
        //MILIEUX 
        motor.angleTurn(-180,consigne);
        delay(100);
        motor.straightRun(120, consigne);
        delay(100);
        motor.angleTurn(-40, consigne);
        delay(100);
        motor.straightRun(60, consigne);
        delay(100);
        motor.angleTurn(95,consigne);
        delay(100);
        motor.straightRun(185, 0.5);
        delay(100);
        motor.angleTurn(-42, consigne);
        delay(100);
        motor.straightRun(65, consigne);
        delay(100);
        motor.angleTurn(-90,consigne);
        delay(100);
        motor.straightRun(75, consigne);
        delay(100);
        motor.angleTurn(85,consigne);
        delay(100);
        motor.straightRun(115, consigne);
        delay(100);
        motor.angleTurn(360, consigne);
        test = false;
      }
  }
  MOTOR_SetSpeed(1, 0);
  MOTOR_SetSpeed(0, 0);
  
}

void execute(){

}