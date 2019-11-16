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
    int x = -500;
    if (pixy.ccc.getBlocks() > 0)
    {
        x = pixy.ccc.blocks[index].m_x;
    }
    return x;
}

float get_largeur(int index){
    float largeur = -1;
    if (pixy.ccc.getBlocks() > 0)
    {
        largeur = pixy.ccc.blocks[index].m_width;
        largeur = largeur/10.0;
    }
    return largeur;
}

void track(int index){
    Motor motor;
    int x = get_x(index); 
    float largeur = get_largeur(index);
    switch (x/25)
    {
    case 0://0 a 24
        motor.move(-0.30*largeur);
        break;
    
    case 1:// 25 a 49
        motor.move(-0.25*largeur);
        break;
    
    case 2://50 a 74
        motor.move(-0.2 *largeur);
        break;
    
    case 3:// 75 a 99
        motor.move(-0.15 *largeur);
        break;
    
    case 4://100 a 124
        motor.move(-0.1 *largeur);
        break;
    case 5://125 a 149
        motor.move(-0.05 *largeur);
        break;
    
    case 6://150 a 174
        motor.move(0);
        break;
    
    case 7://175 a 199
        motor.move(0.05*largeur);
        break;
    
    case 8://200 a 224
        motor.move(0.10 *largeur);
        break;
    
    case 9://225 a 249
        motor.move(0.15 *largeur);
        break;
    
    case 10://250 a 274
        motor.move(0.20 *largeur);
        break;
    
    case 11://275 a 299
        motor.move(0.25 *largeur);
        break;
    
    case 12://300 a 324
        motor.move(0.30 *largeur);
        break;
    
    default:
        motor.move(0);
        break;
    }
}