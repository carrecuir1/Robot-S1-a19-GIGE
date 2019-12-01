#include <Main.h>



void setup() 
{
  BoardInit();
}

void loop()
{
  Instruction instr = Instruction(2.0);
  instr.getBTInsctruction();
}