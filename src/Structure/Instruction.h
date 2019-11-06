#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>
#include <Structure/Servo.h>
#include <Structure/suiveurLigne.h>
#include <Structure/capteurIR.h>

struct Instruction {

    typedef enum {
        red,
        yellow,
        green,
        blue
    } color;

    Motor motor;
    Servo servo;
    suiveurLigne suiveurligne;
    //
    capteurIR capteurir;
    //
    float speed;
    Instruction(float consigne){
        motor = Motor();
        speed = consigne;
    }

    void testIR(){
        float dist;
        dist = capteurir.getDistance();
        Serial.println(dist);
    }
    //Fonction qui va contenir les instructions du robot A
    void warriorChallengeA(){
        color valide = yellow;

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
        //suiveurligne.suivreLigneDroite();        
        servo.catchBall();
        motor.uTurn(0.2);
        motor.moveDistance(88,0.2);
        servo.openPliers();
        motor.moveDistance(10,-0.2);
        motor.angleTurn(90);
        motor.moveDistance(60,0.3);

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
        //motor.moveDistance(30, 0.3);
        servo.catchBall();
    }

    void redA(){
        motor.moveDistance(15, 0.4);
        motor.moveOverCircle(17);
        motor.angleTurn(-45);
        motor.moveOverCircle(17);
    }

    void yellowA(){
        motor.angleTurn(-45);

        motor.moveDistance(11, 0.4);
        //motor.moveDistance(12, 0.4);
        motor.angleTurn(-97);
        //motor.moveDistance(10, 0.4); //mettre suiveurligne
        
    }

    void greenA(){
        motor.moveDistance(15, 0.4);
        motor.moveOverCircle(17);
        motor.angleTurn(45);
        motor.moveOverCircle(17);
    }
    
    void blueA(){
        motor.angleTurn(45);
        motor.moveDistance(12, 0.4);
        motor.angleTurn(95);
        motor.moveDistance(10, 0.4);
        motor.angleTurn(-95);
    }

    void redB(){
        motor.angleTurn(-90);
        motor.moveDistance(15, 0.4);
        motor.angleTurn(90);
        motor.moveDistance(31, 0.4);
        motor.angleTurn(135);
        motor.moveOverCircle(31);
    }

    void yellowB(){
        motor.angleTurn(-45);
        motor.moveDistance(12, 0.4);
        motor.angleTurn(90);
        motor.moveOverCircle(31);
    }

    void greenB(){
        motor.angleTurn(90);
        motor.moveDistance(15, 0.4);
        motor.angleTurn(-90);
        motor.moveDistance(31, 0.4);
        motor.moveOverCircle(31);
    }
    
    void blueB(){
        motor.angleTurn(45);
        motor.moveDistance(12, 0.4);
        motor.angleTurn(-90);  
        motor.moveOverCircle(31);
        
    }


};
