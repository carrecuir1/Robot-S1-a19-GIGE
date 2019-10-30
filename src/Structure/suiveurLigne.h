struct suiveurLigne{
    //Capteur avant sur port analogique 0, milieu sur 1, arrière sur 2.
    float sensorValue0, sensorValue1, sensorValue2, voltage[3];
    float voltageNoir; //Valeur de tension associable à une couleur noire captée par le capteur, un peu arbitraire.
    float voltageVert, voltageRouge, voltageBleu, voltageJaune;

    void detection(float sensorValue0, float sensorValue1, float sensorValue2, float voltage[3])
    {
        voltage[0] = sensorValue0*5.0/1023.0;
        voltage[1] = sensorValue1*5.0/1023.0;
        voltage[2] = sensorValue2*5.0/1023.0;
    }

    float decision(float voltage[3])
    {
        while(0)
        {
            while(voltage[0]>=voltageNoir && voltage[1]>=voltageNoir && voltage[2]>=voltageNoir)
            {
                //Avancer
            }
            //Analogue 0 < voltageNoir
            if(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir)
            {
                //Reset des encodeurs, moteurs mis à zéro
                while(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir || condition) //condition = quart de tour à gauche
                {
                    //Tourner à gauche (donc pour un quart de tour)
                }
                //Après le quart de tour à gauche, revérifie si les voltages sont bons, sinon retourne jusqu'à 180 degrés max.
                if(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir)
                {
                    //Reset des encodeurs, moteurs mis à zéro
                    while(voltage[0]<voltageNoir||voltage[1]<voltageNoir||voltage[2]<voltageNoir||condition) //condition = demi-tour à droite
                    {
                        //Tourner à droite (donc pour un demi tour)
                    }
                }


            }   

            
        }
        
    }

};