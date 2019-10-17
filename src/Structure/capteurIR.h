


float getDistance(){
  int nbMesure = 2;
  int Vo = 0;
  float distance = 0;
  for (int i = 0; i < nbMesure; i++)
  {
    delay(40);
    Vo = analogRead(A0);
    distance += 30617.0 * pow(Vo,-1.309);
  }
  return (distance / nbMesure);
}
