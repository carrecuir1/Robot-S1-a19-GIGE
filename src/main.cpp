#include <main.h>

#define consigne 0.35
void setup() {
  BoardInit();
     // suiveurLigne follow;
     // follow.suivreLigneDroite();
     if(ROBUS_IsBumper(3))
     {
       Serial.println(analogRead(0)*5.0/1023.0);
       Serial.println(analogRead(1)*5.0/1023.0);
       Serial.println(analogRead(2)*5.0/1023.0);
     }
}

void loop() {

  Instruction instruction = Instruction(consigne);

  if(ROBUS_IsBumper(3)){
    instruction.warriorChallengeA();
  }
}

