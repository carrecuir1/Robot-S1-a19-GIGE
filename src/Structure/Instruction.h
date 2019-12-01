#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>
#include <Structure/Servo.h>
#include <Structure/Bluetooth.h>
#include <Structure/capteurIR.h>
#include <Structure/launcher.h>


//Va contenir les intrstuctions à effectuer pour le robot
struct Instruction {

    Motor motor;
    Servo servo;
    Bluetooth bt;
    float speed;
    bool motorActive;
    Launcher launch;

    Instruction(float consigne){
        motor = Motor();
        speed = consigne;
        bt = Bluetooth();
        motorActive = false;
    }

    void getBTInsctruction(){
        int state = bt.read();
        switch (state)
        {
        case 0:
            //bt.sendMessage("Inactive"); // Send back, to the phone, the String "LED: ON"
            launch.stop();
            break;
        case 1:
            //bt.sendMessage("Active"); // Send back, to the phone, the String "LED: ON"
            launch.spin(255);
            break;
        case 2:
            motor.turn(-1);//Tourne les moteurs à gauche
            delay(500);
            break;
        case 3:
            motor.turn(1);
            delay(500);
            break;
        case 4:
            launch.launch(255);

            
            break;
        default:
            motor.stopMotors();
            break;
        }
    }
};
