// Exemplo 7 - Sensor Ótico Reflexivo TCRT5000
// Apostila Eletrogate - KIT INICIANTE V2

int leituraSensor;        // variavel de leitura do sensor
int led = 8;              // led indicador              = D8 do Arduino
int fotoTransistor = 7;   // coletor do fototransistor  = D7 do Arduino

void setup()
{
    Serial.begin(9600); 
    pinMode(led, OUTPUT); // pino do led indicador = saida
    pinMode(fotoTransistor, INPUT); // pino do coletor do fototransistor = entrada
}

void loop()
{
    leituraSensor = digitalRead(fotoTransistor); // leitura do sensor TCRT5000
    
    Serial.print("EStado do Sensor: ");
    Serial.print(leituraSensor);
    Serial.print("; ");

    if (leituraSensor == 0 ) // se o led refletir a luz
    {
        digitalWrite(led, HIGH); // acende LED indicador
        Serial.println("LED Aceso");
    }
    else // senão
    {
        digitalWrite(led, LOW); // apaga LED indicador
        Serial.println("LED Apagado");
    }
    delay(500); // atraso de 0,5 segundos
}