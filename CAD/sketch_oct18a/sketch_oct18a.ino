int estadobotao = 0; //declare a variável inteira de leitura do botão

int PORTA_IN = 2;
int LED_AZUL = 3;
int LED_BRANCO_1 = 4;
int LED_BRANCO_2 = 5;
int DELAY = 300;

void setup() {
    Serial.begin(9600);
    // put your setup code here, to run once:
    pinMode(LED_AZUL, OUTPUT);          //diga ao arduino que os pinos das LEDs são de saída: 'OUTPUT'
    pinMode(LED_BRANCO_1, OUTPUT);
    pinMode(LED_BRANCO_2, OUTPUT);
    pinMode(PORTA_IN, INPUT);          //agora para o botão, será de entrada: 'INPUT' para que o arduino faça a leitura do estado do botão
}

void loop() {
    
    // put your main code here, to run repeatedly:
    estadobotao = digitalRead(PORTA_IN); //a variável 'estadobotao' recebe o estado da porta digital 2
    Serial.println(estadobotao);

    // se o botão não estiver pressionado
    if (estadobotao == LOW) { 
        digitalWrite(LED_AZUL, HIGH);  // acende o LED da porta LED_AZUL 

        digitalWrite(LED_BRANCO_1, LOW);   // apaga o LED da porta LED_BRANCO_1 
        digitalWrite(LED_BRANCO_2, LOW);   // apaga o LED da porta LED_BRANCO_2
    }
    // se estiver pressionado
    else  { 
        digitalWrite(LED_AZUL, LOW);   // apaga o LED da porta LED_AZUL 

        digitalWrite(LED_BRANCO_1, LOW);   // apaga o LED da porta LED_BRANCO_1 
        digitalWrite(LED_BRANCO_2, HIGH);  // acende o LED da porta LED_BRANCO_2
        delay(DELAY);             // espera 0.2LED_BRANCO_20 segundos
        
        digitalWrite(LED_BRANCO_1, HIGH);  // acende o led da porta LED_BRANCO_1 
        digitalWrite(LED_BRANCO_2, LOW);   // apaga o led da porta LED_BRANCO_2
        delay(DELAY);             // espera mais 0.2LED_BRANCO_20 segundos
    }

}
