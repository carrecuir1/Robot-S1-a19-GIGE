#include <main.h>

void setup() {
  BoardInit();
<<<<<<< HEAD
  Serial.begin(9600);
}

void loop() {
     suiveurLigne follow;
=======
     // suiveurLigne follow;
>>>>>>> a940e80692727bbf2fb2124a3c050a7ff6990608
     // follow.suivreLigneDroite();
     if(ROBUS_IsBumper(3))
     {
       follow.suivreLigneDroite();
       //Serial.println(analogRead(0)*5.0/1023.0);
       //Serial.println(analogRead(1)*5.0/1023.0);
       //Serial.println(analogRead(2)*5.0/1023.0);
     }
<<<<<<< HEAD
=======
}

void loop() {

  Instruction instruction = Instruction(consigne);

  if(ROBUS_IsBumper(3)){
    instruction.warriorChallengeA();
  }
>>>>>>> a940e80692727bbf2fb2124a3c050a7ff6990608
}

