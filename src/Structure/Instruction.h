#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>

struct Instruction {

    typedef enum {
        red,
        yellow,
        green,
        blue
    } color;

    Motor motor;
    float speed;
    Instruction(float consigne){
        motor = Motor();
        speed = consigne;
    }

    //Fonction qui va contenir les instructions du robot A
    void warriorChallengeA(){
        color valide = red;

        switch (valide)
        {
        case red:
            /* code */
            break;
        case yellow:
            /* code */
            break;
        case green:
            /* code */
            break;
        case blue:
            /* code */
            break;
        default:
            //Thomas Labbé estS le Martino
            break;
        }
    }

    //Fonction qui va contenir les instructions du robot B
    void warriorChallengeB(){

    }

    //Fonction qui va faire avancer le robot
    void moveRobot(int8_t direction){
        float speedWithDirection = speed*direction;
        motor.resetPIDAndEncoder(speedWithDirection);
        while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0)){
            motor.move(speedWithDirection);
            delay(10);
        }
        motor.stopMotors();
    }

    void redA(){
        motor.angleTurn(-45);
        motor.moveDistance(90,0.2);
        motor.angleTurn(45);
    }

    void yellowA(){

    }

    void greenA(){

    }
    
    void blueA(){

        
    }


};
