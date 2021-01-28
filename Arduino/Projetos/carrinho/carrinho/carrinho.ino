#define pinBotaoA 5 // pino do botão de controle do sentido do motor B (lado esquerdo)
#define pinBotaoB 4 // pino do botão de controle do sentido do motor A (lado direito)

#define pinSentido1MotorA 3 // pinos de sentido horario e antihorario do motor A
#define pinSentido2MotorA 2

#define pinSentido1MotorB 7 // pinos de sentido horario e antihorario do motor B
#define pinSentido2MotorB 6

byte estadoA = 0;            // estados do botao que controla o motor A
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA;

byte estadoB = 0;            // estados do botao que controla o motor B
bool estadoBotaoB = true;
bool estadoAntBotaoB = true;
unsigned long delayBotaoB;

void setup() {

  // Definição dos pinos
 
  pinMode(pinBotaoA, INPUT_PULLUP);
  pinMode(pinBotaoB, INPUT_PULLUP);

  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
}

void loop() {

  estadoBotaoA = digitalRead(pinBotaoA);      // controla s quantidade de apertos no botão
  if (!estadoBotaoA && estadoAntBotaoA) {
     if ((millis() - delayBotaoA) > 20) {
        estadoA++;
        if (estadoA > 2) {
           estadoA = 0;
        }
        delayBotaoA = millis();
     }
  } else if (estadoBotaoA != estadoAntBotaoA) {
        delayBotaoA = millis();    
  }
  estadoAntBotaoA = estadoBotaoA;

  estadoBotaoB = digitalRead(pinBotaoB);
  if (!estadoBotaoB && estadoAntBotaoB) {
     if ((millis() - delayBotaoB) > 20) {
        estadoB++;
        if (estadoB > 2) {
           estadoB = 0;
        }
        delayBotaoB = millis();
     }
  } else if (estadoBotaoB != estadoAntBotaoB) {
        delayBotaoB = millis();    
  }
  estadoAntBotaoB = estadoBotaoB;

// inicio do uso da ponte H em si, controlando os motores e os sentidos

  if (estadoA == 0) {
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, LOW);    

  } else {    
     if (estadoA == 1) {
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
        
     } else { //estadoA == 2
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);      
     }
  } 


  if (estadoB == 0) {
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, LOW);

  } else {
     if (estadoB == 1) {
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);
        
     } else { //estadoB == 2
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);      
     }
  } 
  
}

