// Projeto 26
#include <Servo.h>

char buffer[10];
Servo servo1; // Cria um objeto servo
Servo servo2; // Cria um segundo objeto servo

void setup() {
    servo1.attach(5); // Anexa o servo, no pino 5, ao objeto servo1
    servo2.attach(6); // Anexa o servo, no pino 6, ao objeto servo2

    Serial.begin(9600);
    Serial.flush();

    servo1.write(90); // Coloca o servo1 na posição inicial
    servo2.write(90); // Coloca o servo2 na posição inicial
    Serial.println("");
    Serial.println("STARTING...");
}

void loop() {
    if (Serial.available() > 0) {                     // Verifica se dados foram digitados
      int index=0;
      delay(100);                                     // Deixa o buffer encher
      int numChar = Serial.available();               // Encontra o comprimento da string 

      if (numChar > 10) {
          numChar=10;
      }

      while (numChar--) {
        // Preenche o buffer com a string
        buffer[index++] = Serial.read();
      }

      splitString(buffer);                            // Executa a função splitString
    }
}

void splitString(char* data) {
    
    Serial.print("Data entered: ");
    Serial.println(data);

    char* parameter;
    
    parameter = strtok (data, " ,");                  // De string para tokens
    
    while (parameter != NULL) {                       // Se ainda não atingimos o fim da string... 
        setServo(parameter);                          // ...execute a função setServo
        parameter = strtok (NULL, " ,");
    }

    // Limpa o texto e os buffers seriais
    for (int x=0; x<9; x++) {
        buffer[x]='\0';
    }
    Serial.flush();
}

void setServo(char* data) {
    if ((data[0] == 'L') || (data[0] == 'l')) {
      int firstVal = strtol(data+1, NULL, 10); // De string para inteiro longo 
      firstVal = constrain(firstVal,0,180); // Restringe os valores
      servo1.write(firstVal);
      Serial.print("Servo1 is set to: ");
      Serial.println(firstVal);
    }

    if ((data[0] == 'R') || (data[0] == 'r')) {
      int secondVal = strtol(data+1, NULL, 10); // De string para inteiro longo 
      secondVal = constrain(secondVal,0,255); // Restringe os valores 
      servo2.write(secondVal);
      Serial.print("Servo2 is set to: ");
      Serial.println(secondVal);
    }
}