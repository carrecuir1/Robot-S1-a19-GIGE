#include <main.h>

#define consigne 0.35
void setup() {
  BoardInit();
}

void loop() {

  Instruction instruction = Instruction(consigne);

  if(ROBUS_IsBumper(3)){
    instruction.warriorChallengeA();
  }
}

