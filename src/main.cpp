#include <main.h>

void setup() {
  BoardInit();
  SERVO_Disable(0);
}

void loop() {
 
  Instruction instruction = Instruction(consigne);

  /*if(ROBUS_IsBumper(3)){
    instruction.warriorChallengeA();

  }*/
  SERVO_Enable(0);
  delay(500);
  SERVO_SetAngle(0,0);
  delay(500);
  SERVO_SetAngle(0,0);
  /*if(ROBUS_IsBumper(3)){
    delay(60000);
    instruction.warriorChallengeB();

  }*/
  
}

