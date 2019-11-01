#include <Arduino.h>
#include <LibRobus.h>

#define PinceOuverte = 90
#define PinceFermee = 0
#define ServoPince = 0

struct Servo {
    void ouvrirPince(void)
    {
        void SERVO_Enable(ServoPince);
        void SERVO_SetAngle(ServoPince, PinceOuverte);
        void SERVO_Disable(ServoPince);
    }

    void fermerPince(void)
    {
        void SERVO_Enable(ServoPince);
        void SERVO_SetAngle(ServoPince, PinceFermee);
        void SERVO_Disable(ServoPince);
    }
}
