#include <Arduino.h>
#include <LibRobus.h>
/*

//Va contenir les intrstuctions à effectuer pour le robot
struct Instruction {

    Motor motor;
    Bluetooth bt;
    float speed;
    Launcher launch;

    Instruction(float consigne){
        motor = Motor();
        speed = consigne;
        bt = Bluetooth();
    }

    void getBTInsctruction(){
        int state = bt.read();
        switch (state)
        {
        case 0:
            motor.turn(-1);//Tourne les moteurs à gauche
            delay(500);
            break;
        case 1:
            motor.turn(1);
            delay(500);
            break;
        case 2:
            launch.launch(255);
            break;
            
        default:
            motor.stopMotors();
            break;
        }
    }
};
*/