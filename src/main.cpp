#include <Main.h>

Instruction instr = Instruction(2.0);
void setup() {
  BoardInit();
  Serial.begin(9600);
  SERVO_Disable(0);
  delay(500);
}

void loop() {
  instr.getBTInsctruction();
}
