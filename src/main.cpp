#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define consigne 0.3
bool stop = false;
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
        delay(100);
        motor.angleTurn(-85,consigne);
        delay(100);
        motor.straightRun(80, consigne);
        delay(100);
        motor.angleTurn(90,consigne);
        delay(100);
        motor.straightRun(70, consigne);
        delay(100);
        motor.angleTurn(45,consigne);
        delay(100);
        motor.straightRun(169, consigne);
        delay(100);
        motor.angleTurn(-90,consigne);
        delay(100);
        motor.straightRun(50, consigne);
        delay(100);
        motor.angleTurn(45,consigne);
        delay(100);
        motor.straightRun(110, consigne);
        delay(100);
        //MILIEUX 
        motor.angleTurn(-180,consigne);
        delay(100);
        motor.straightRun(110, consigne);
        delay(100);
        motor.angleTurn(-45, consigne);
        delay(100);
        motor.straightRun(50, consigne);
        delay(100);
        motor.angleTurn(90,consigne);
        delay(100);
        motor.straightRun(169, 0.5);
        delay(100);
        motor.angleTurn(-45, consigne);
        delay(100);
        motor.straightRun(70, consigne);
        delay(100);
        motor.angleTurn(-90,consigne);
        delay(100);
        motor.straightRun(90, consigne);
        delay(100);
        motor.angleTurn(90,consigne);
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