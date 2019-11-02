#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>

#define voltageNoir 4.5 //Valeur de tension associable à une couleur noire captée par le capteur, un peu arbitraire.
#define voltageCouleur 3 //Valeur située au-dessus du voltage pour le blanc, plus petit voltage entre jaune, rouge, bleu, vert.

struct suiveurLigne{
    //Capteur avant sur port analogique 0, milieu sur 1, arrière sur 2.
    float voltage[3];

    void detection(float voltage[3]){
    
        voltage[0] = analogRead(0)*5.0/1023.0;
        voltage[1] = analogRead(1)*5.0/1023.0;
        voltage[2] = analogRead(2)*5.0/1023.0;
    }

    void suivreLigneDroite()
    {
        while(true)
        {
            float voltage[3];
            float encodeur_droit = 0,encodeur_gauche = 0;
            detection(voltage);
            Motor moteur;
            moteur.resetPIDAndEncoder(0.2);
            Serial.println("-----");
            Serial.println(voltage[0]);
            Serial.println(voltage[1]);
            Serial.println(voltage[2]);
            //Si les trois capteurs voient la ligne noire
            while(voltage[0]>=voltageNoir && voltage[1]>=voltageNoir && voltage[2]>=voltageNoir){
            
                moteur.move(0.2); 
                delay(20);
                detection(voltage);
            }
            moteur.stopMotors();
            //Si le premier capteur détecte un voltage associé à une couleur
            if(voltage[0]>=voltageCouleur && voltage[0]<voltageNoir)
            {
                break; //Quitte la boucle
            }

            //Si le capteur central voit la ligne noire mais qu'un autre capteur non
            if(voltage[1]>=voltageNoir && (voltage[0]<voltageNoir || voltage[2]<voltageNoir)){
            
                ENCODER_Reset(0);
                ENCODER_Reset(1);
                //Tourne à gauche jusqu'à ce qu'il trouve, pour un max de 30 degrés.
                while((voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir) && encodeur_droit <= 90){
                
                    moteur.angleTurn(-3); //Valeurs de ±3 peut-être à revoir, parfaitement arbitraire
                    detection(voltage);
                    encodeur_droit+=ENCODER_Read(1);
                    delay(20);
                }
                encodeur_droit = 0;
                moteur.stopMotors();
                //Après le quart de tour à gauche, si pas trouvé la ligne, refait la même opération vers la droite.
                if(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir){

                    moteur.angleTurn(30);
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                    while((voltage[0]<voltageNoir||voltage[1]<voltageNoir||voltage[2]<voltageNoir) && encodeur_gauche <= 90){ 
                    
                        moteur.angleTurn(3);
                        detection(voltage);
                        encodeur_gauche+=ENCODER_Read(0);
                        delay(20);
                    }
                    encodeur_gauche = 0;
                }
                moteur.stopMotors();

            }
            //Si le capteur de l'avant voit la ligne noire mais que les deux autres capteurs non
            if(voltage[0]>=voltageNoir && voltage[2]<voltageNoir && voltage[1]<voltageNoir){
                moteur.move(0.2); //Avance jusqu'à ce que le capteur central voie la ligne noire.       
                while(voltage[1]<voltageNoir){
                    delay(20);
                    detection(voltage);
                }
                moteur.stopMotors();
            }

            //Si le capteur arrière voit la ligne noire mais que les deux autres capteurs non
            if(voltage[2]>=voltageNoir && voltage[1]<voltageNoir && voltage[0]<voltageNoir){
                moteur.move(0.2); //Recule jusqu'à ce que le capteur central voie la ligne noire.
                while(voltage[1]<voltageNoir){
                    detection(voltage);
                    delay(20);
                }
                moteur.stopMotors();
            }

            //Si aucun capteur ne voit la ligne noire
            if(voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir){

                ENCODER_Reset(0);
                ENCODER_Reset(1);

                while((voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir)||encodeur_droit <= 90){

                    moteur.angleTurn(-3);
                    detection(voltage);
                    encodeur_droit+=ENCODER_Read(1);
                    delay(20);
                }
                encodeur_droit = 0;
                moteur.stopMotors();
                if(voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir){
        
                    moteur.angleTurn(30);
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                    while((voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir)||encodeur_gauche <= 90){

                        moteur.angleTurn(3);
                        detection(voltage);
                        encodeur_gauche+=ENCODER_Read(0);
                        delay(20);
                    }
                    encodeur_gauche = 0;
                }
                if((voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir))
                    break;
            }
        }   
    };
};