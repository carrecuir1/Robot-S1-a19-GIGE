#include <main.h>

void setup() {
  BoardInit();
  SERVO_Disable(0);
}

void loop() {
  
  Instruction instruction = Instruction(consigne);

  if(ROBUS_IsBumper(3)){
    instruction.warriorChallengeA();
  }
  if(ROBUS_IsBumper(1)){
    instruction.warriorChallengeB();
  }
}

