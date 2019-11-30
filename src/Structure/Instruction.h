#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>
#include <Structure/Servo.h>
#include <Structure/Bluetooth.h>
//#include <Structure/suiveurLigne.h>
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
    Bluetooth bt;
   // suiveurLigne suiveurligne;
    ////
    //capteurIR capteurir;
    //
    float speed;
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
            bt.sendMessage("Inactive"); // Send back, to the phone, the String "LED: ON"
            //desactivation des moteurs DC
            break;
        case 1:
            bt.sendMessage("Active"); // Send back, to the phone, the String "LED: ON"
            //activation des moteurs DC
            break;
        case 2:
            bt.sendMessage("Left"); //Tourne les moteurs à gauche
            motor.turn(-1);
            delay(500);
            break;
        case 3:
            bt.sendMessage("Right");
            motor.turn(1);
            delay(500);
            break;
        default:
            motor.stopMotors();
            break;
        }
    }
    /*void testIR(){
        float dist;
        dist = capteurir.getDistance();
        Serial.println(dist);
    }*/
    //Fonction qui va contenir les instructions du robot A
    
    void warriorChallengeA(){
        color valide = blue;

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
        servo.catchBall();
        motor.moveDistance(10, -0.2);
        motor.uTurn(0.2);
        motor.angleTurn(5);
        motor.moveDistance(86, 0.3);
        servo.openPliers();
        motor.moveDistance(100, -0.2);
        motor.angleTurn(45);
        motor.moveDistance(60, 0.3);
        motor.angleTurn(-90);
        motor.moveDistance(20, -0.3);
    }

    //Fonction qui va contenir les instructions du robot B
    void warriorChallengeB(){
        color valide = green;
        
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
        motor.moveDistance(100, 0.8);
    }

    void redA(){
        motor.angleTurn(-90);
        motor.moveDistance(45, 0.3);
        motor.angleTurn(90);
        motor.moveDistance(80, 0.3);
        motor.angleTurn(-45);
    }

    void yellowA(){
        motor.angleTurn(-45);
        motor.moveDistance(11, 0.4);
        motor.angleTurn(-97);
    }

    void greenA(){
        motor.angleTurn(90);
        motor.moveDistance(45, 0.3);
        motor.angleTurn(-90);
        motor.moveDistance(80, 0.3);
        motor.angleTurn(45);
    }
    
    void blueA(){
        motor.moveDistance(10, -0.3);
        /*motor.angleTurn(90);
        motor.moveDistance(12, 0.4);
        motor.angleTurn(95);
        motor.moveDistance(10, 0.4);
        motor.angleTurn(-95);*/
        motor.angleTurn(45);
        motor.moveDistance(11, 0.4);
        motor.angleTurn(97);
    }

    void redB(){
        motor.moveDistance(10, -0.3);
        motor.angleTurn(-90);
        motor.moveDistance(15, 0.3);
        motor.angleTurn(90);
        motor.moveDistance(31, 0.3);
        motor.angleTurn(135);
        motor.moveOverCircle(31);
    }

    void yellowB(){
        /*motor.angleTurn(-45);
        motor.moveDistance(12, 0.3);
        motor.angleTurn(90);
        motor.moveOverCircle(31);*/
        motor.moveDistance(10, -0.3);
        motor.angleTurn(-90);
        motor.moveDistance(10, 0.3);
        motor.angleTurn(135); 
        motor.moveDistance(10, 0.3); 
        motor.moveOverCircle(31);
    }

    void greenB(){
        motor.moveDistance(10, -0.3);
        motor.angleTurn(90);
        motor.moveDistance(17, 0.3);
        motor.angleTurn(-90);
        motor.moveDistance(31, 0.3);
        motor.angleTurn(-140);
        motor.moveOverCircle(31);
        /*motor.moveDistance(10, -0.3);
        motor.angleTurn(-90);
        motor.moveDistance(10, 0.3);
        motor.angleTurn(135); 
        motor.moveDistance(10, 0.3); 
        motor.moveOverCircle(31);*/
    }
    
    void blueB(){
        motor.moveDistance(10, -0.3);
        motor.angleTurn(90);
        motor.moveDistance(10, 0.3);
        motor.angleTurn(-135); 
        motor.moveDistance(10, 0.3); 
        motor.moveOverCircle(31);
        
    }


};
