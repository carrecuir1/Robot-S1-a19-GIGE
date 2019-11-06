#include <main.h>

void setup() {
  BoardInit();
}

void loop() {
     suiveurLigne follow;
     // follow.suivreLigneDroite();
     if(ROBUS_IsBumper(3))
     {
       follow.suivreLigneDroite();
     }
}

