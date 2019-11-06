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
            redA();
            break;
        case yellow:
            yellowA();
            break;
        case green:
            greenA();
            break;
        case blue:
            blueA();
            break;
        }
    }

    //Fonction qui va contenir les instructions du robot B
    void warriorChallengeB(){
        color valide = red;
        
        switch (valide)
        {
        case red:
            redB();
            break;
        case yellow:
            yellowB();
            break;
        case green:
            greenB();
            break;
        case blue:
            blueB();
            break;
        }
    }
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
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }

    void yellowA(){
        //TODO LIST
        //Turn 90° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }

    void greenA(){
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }
    
    void blueA(){
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }

    void redB(){
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }

    void yellowB(){
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }

    void greenB(){
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
    }
    
    void blueB(){
        //TODO LIST
        //Move center
        //Turn 45° vers la gauche
        //Bouge en ligne droite en sortant du cercle
        //Rendu au but, il prend le balon
        //UTurn
        //Va le porter au cercle
        
    }

};
