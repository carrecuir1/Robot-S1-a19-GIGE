#include <main.h>

void setup() {
  BoardInit();
  Serial.begin(9600);
}

void loop() {
     suiveurLigne follow;
     // follow.suivreLigneDroite();
     if(ROBUS_IsBumper(3))
     {
       follow.suivreLigneDroite();
       //Serial.println(analogRead(0)*5.0/1023.0);
       //Serial.println(analogRead(1)*5.0/1023.0);
       //Serial.println(analogRead(2)*5.0/1023.0);
     }
}

