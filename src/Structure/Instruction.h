#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>
#include <Structure/Servo.h>


struct Instruction {

    Motor motor;
    Servo servo;
    float speed;
    Instruction(float consigne){
        motor = Motor();
        speed = consigne;
    }

    //Fonction qui va contenir les instructions du robot A
    void warriorChallengeA(){
       servo.catchBall();
       motor.uTurn(0.2);
       motor.moveDistance(30, 0.2);
    }

    //Fonction qui va contenir les instructions du robot B
    void warriorChallengeB(){
        servo.closePliers();
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
};
