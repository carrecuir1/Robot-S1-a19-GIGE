#include <Main.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() 
{
  BoardInit();
}

void loop()
{
  Instruction instr = Instruction(2.0);
  instr.getBTInsctruction();
}