#include <main.h>

void setup() {
  BoardInit();
  SERVO_Disable(0);
}

void loop() {
<<<<<<< HEAD
  
  Instruction instruction = Instruction(consigne);

  if(ROBUS_IsBumper(3)){
    instruction.warriorChallengeA();
  }
  if(ROBUS_IsBumper(1)){
    instruction.warriorChallengeB();
  }
=======
     suiveurLigne follow;
     // follow.suivreLigneDroite();
     if(ROBUS_IsBumper(3))
     {
       follow.suivreLigneDroite();
     }
>>>>>>> master
}

