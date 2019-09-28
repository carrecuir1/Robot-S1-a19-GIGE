#include <Arduino.h>
#include <../lib/LibRobUS/src/LibRobus.h>

float pid(int consigne, int encodeur,int DELAY); // consigne = v mit, feedback = v réel
float iPresent = 0;  // pas touche

int feedbackPresent= 0;
#pragma region PID
float pid(int consigne, int encodeur, int DELAY)
{
    
    const float ki = 0, kd = 0, kp = 1;
    float iPasse;
    int feedbackPasse = feedbackPresent;
    feedbackPresent = ENCODER_ReadReset(encodeur);
    int erreur = consigne - feedbackPresent;
    float p = kp * erreur ;
    iPasse = iPresent;
    iPresent = (ki *  erreur ) + iPasse;
    float d = kd * ( feedbackPresent - feedbackPasse);
    float commande = p +iPresent - d ;
    commande = map(commande, 0, 12*DELAY, 0.0, 1.0);  //conversion pulse

    return commande;  
}
#pragma endregion