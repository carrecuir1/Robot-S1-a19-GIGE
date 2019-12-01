#include <main.h>


void setup() {
  BoardInit();
  Serial.begin(9600);
  SERVO_Disable(0);
  delay(500);
}

void loop() {
  struct Launcher launcher;
  int spinspeed = 255;

  if(ROBUS_IsBumper(1))
  
  
  //launcher.serveball();
  launcher.launch(spinspeed);
}
