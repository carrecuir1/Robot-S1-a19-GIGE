#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/capteurIR.h>

#define PinceOuverte 200
#define PinceFermee 155
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
        delay(500);
        SERVO_Disable(ServoPince);
    }

    void catchBall()
    {
        Motor motor;
        capteurIR capteur;
        Serial.println("test\n");
        while(!ROBUS_IsBumper(2))
        {
            Serial.println(capteur.getDistance());
            if(capteur.getDistance() > 20)
            {
                motor.moveDistance(5, 0.3);
            }
        }
        Serial.println("fermeture");
        closePliers();

        SERVO_Disable(ServoPince);
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
};
