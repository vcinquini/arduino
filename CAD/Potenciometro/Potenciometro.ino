// Exemplo 1 - usando potenciometro

#define sensorPin A0  // entrada analogica A0

int sensorValue = 0;
float voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         // monitor serial - 9600 bps
  delay(100);                 // wait 100 milisec
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);        // le entrada analogica A0
  voltage = sensorValue * (5.0 / 1024);       // calcula tensão

  Serial.print("Tensao do potenciometro ");
  Serial.print(voltage);
  Serial.print("   Valor: ");
  Serial.println(sensorValue);
  delay(500);
}