#include <Arduino.h>
#include <LibRobus.h>

struct Instruction {
    PID pid;
    Instruction(float consigne){
        pid = PID(consigne);
    }

    void defiCombattantA(){
        
    }

    void defiCombattantB(){

    }

};