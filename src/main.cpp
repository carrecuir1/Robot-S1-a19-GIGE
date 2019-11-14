#include <main.h>

void setup() {
  BoardInit();
  SERVO_Disable(0);
  pixyInit();
}

void loop() {
  track(0);
  delay(100);
 
  
}

