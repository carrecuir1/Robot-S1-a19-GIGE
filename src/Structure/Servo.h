#include <Arduino.h>
#include <LibRobus.h>

#ifndef CAPTEURIR_H
#include <Structure/capteurIR.h>
#endif

#define PinceOuverte 150
#define PinceFermee 90
#define ServoPince 0

struct Servo {
    void openPliers()
    {
        SERVO_Enable(ServoPince);
        SERVO_SetAngle(ServoPince, PinceOuverte);
        delay(500);
        SERVO_Disable(ServoPince);
    }

    void closePliers()
    {
        SERVO_Enable(ServoPince);
        SERVO_SetAngle(ServoPince, PinceFermee);
        /*delay(500);
        SERVO_Disable(ServoPince);*/
    }

    void catchBall()
    {
        Motor motor;
        capteurIR capteur;
        
        openPliers();

        motor.moveWithPID(0.2);
        //Serial.println(capteur.getDistance());
        while(capteur.getDistance() > 23)
        {
            Serial.println(capteur.getDistance());
            motor.checkPID();
            delay(50);
        }

        //Serial.println("fermeture");
        closePliers();
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
};
