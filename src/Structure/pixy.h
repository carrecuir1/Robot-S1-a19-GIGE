#include <Arduino.h>
#include <LibRobus.h>
#include <Pixy2.h>

#ifndef MOTOR_H
#include <Structure/Motor.h>
#endif

Pixy2 pixy;

int pixyInit(){
    pixy.init();
    pixy.setLamp(1,0);
    return 0;
}

int get_x(int index){ //Le numero de l'objet à tracker
    pixy.ccc.getBlocks();
    int x = pixy.ccc.blocks[index].m_x;
    return x;
}

int track(int index){
    Motor motor;
    int x = get_x(index);
    if (x < 147){
        motor.move(-0.1);
    }
    else if(x > 167)
    {
        motor.move(0.1);
    }
    else
    {
        motor.move(0);
    }
    return 0;
}