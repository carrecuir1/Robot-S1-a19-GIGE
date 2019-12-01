#include <main.h>

void setup() {
  BoardInit();
  SERVO_Disable(0);
}

void loop() {
  struct Launcher launcher;
  int spinspeed = 200;
  launcher.launch(spinspeed);
}
