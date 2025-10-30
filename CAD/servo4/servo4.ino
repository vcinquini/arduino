#include <Servo.h>
Servo servo;     // cria o objeto servo
int angulo = 0;  // declara origem do angulo como 0°

void setup() {
  servo.attach(5);  //declara pino digital utilizado
}
void loop() {
  for (angulo = 125; angulo <= 180; angulo++) {
    //manda comando pro servo
    servo.write(angulo);
    //intervalo de execução
    delay(100);
  }

  servo.write(90);  //Ponto de parada
  delay(1000);

  for (angulo = 65; angulo >= 0; angulo--) {
    servo.write(angulo);
    delay(100);
  }
}