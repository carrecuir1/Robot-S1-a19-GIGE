#include <Arduino.h>
#include <../lib/LibRobUS/src/LibRobus.h>

float pid(int consigne,int feedbackPresent,  int feedbackPasse); // consigne = v mit, feedback = v réel
float iPresent = 0;  // pas touche
int feedbackPasse = 0;

#pragma region PID
float pid(int consigne)
{
    const float ki = 1, kd = 1, kp = 1;
    float iPasse;
    int feedbackPresent = ENCODER_ReadReset(0);
    int erreur = consigne - feedbackPresent;
    float p = kp * erreur ;
    iPasse = iPresent;
    iPresent = (ki *  erreur ) + iPasse;
    float d = kd * ( feedbackPresent - feedbackPasse);
    float commande = p +iPresent - d ;

    return commande;  
}
#pragma endregion
