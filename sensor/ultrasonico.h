#define echo          3
#define triger        2
class Ultrasonic{
  private:
  long timeU;
  int distancia;
  public:
  int distance(){
    digitalWrite(triger,LOW);
    delay(2);
    digitalWrite(triger,HIGH);
    delay(10);
    digitalWrite(triger,LOW);
    timeU = pulseIn(echo,HIGH);
    distancia = (timeU/2)/29;
    return distancia;
  }

};
