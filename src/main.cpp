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
  if(ROBUS_IsBumper(0)){
    motor.angleTurn(-360,consigne);
  }

  if(ROBUS_IsBumper(1)){
      motor.angleTurn(360,consigne);
  }


  if(ROBUS_IsBumper(2))
  {
    /*motor.angleTurn(90,consigne);
    delay(200);
    motor.angleTurn(-89,-1*consigne);    //-1 degre pour 180 bien fait
    */
    motor.demiTour(consigne);
  }
  
}

void execute(){

}