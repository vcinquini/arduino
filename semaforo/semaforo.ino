const int ledVerdeCarro = 5;
const int ledAmareloCarro = 6;
const int ledVermelhoCarro = 7;
const int ledVerdePedestre = 8;
const int ledVermelhoPedestre = 9;
const int botao = 2;
const int buzz = 3;

void setup() {
    pinMode(ledVerdeCarro, OUTPUT);
    pinMode(ledAmareloCarro, OUTPUT);
    pinMode(ledVermelhoCarro, OUTPUT);
    pinMode(ledVerdePedestre, OUTPUT);
    pinMode(ledVermelhoPedestre, OUTPUT);
    pinMode(buzz, OUTPUT); //Definindo o pino buzzer como de saída.
    pinMode(botao, INPUT_PULLUP);

    // Estado inicial do semáforo
    digitalWrite(ledVerdeCarro, HIGH);
    digitalWrite(ledVermelhoPedestre, HIGH);
}

void loop() {
    if (digitalRead(botao) == LOW) {  // Se o botão for pressionado
        delay(500);  // Debounce do botão
        
        // Muda o semáforo dos carros
        digitalWrite(ledVerdeCarro, LOW);
        digitalWrite(ledAmareloCarro, HIGH);
        delay(2000);  // Amarelo por 2 segundos
        
        digitalWrite(ledAmareloCarro, LOW);
        digitalWrite(ledVermelhoCarro, HIGH);
        
        // Libera a passagem dos pedestres
        digitalWrite(ledVermelhoPedestre, LOW);
        digitalWrite(ledVerdePedestre, HIGH);
        digitalWrite(buzz, HIGH);
        delay(5000);  // Pedestres atravessam por 5 segundos
        
        // Volta ao estado inicial
        digitalWrite(ledVerdePedestre, LOW);
        digitalWrite(ledVermelhoPedestre, HIGH);
        digitalWrite(buzz, LOW);
        delay(1000);
        
        digitalWrite(ledVermelhoCarro, LOW);
        digitalWrite(ledVerdeCarro, HIGH);
    }
}
