// definição dos pinos para os leds, buzzer e joystick
#define pinoLed1 8
#define pinoLed2 9
#define pinoLed3 6
#define pinoLed4 5
#define pinoBuzzer 7
#define pinVRx A2
#define pinVRy A1
#define pinSW  2

void setup() {

  pinMode(pinVRx, INPUT); // variavel eixo x
  pinMode(pinVRy, INPUT); // variavel eixo y
  pinMode(pinSW,  INPUT_PULLUP);  // variavel botão
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed3, OUTPUT);
  pinMode(pinoLed4, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);

  Serial.begin(9600); // inicia a comunicação serial
}

void loop() {

  int valorVRx = analogRead(pinVRx);
  int valorVRy = analogRead(pinVRy);
  bool statusSW = digitalRead(pinSW);

  // variaveis auxiliares para conversão dos valores do joystick
  int aux1 = map(valorVRy, 0, 1023, 180, 0);
  int aux2 = map(valorVRx, 0, 1023, 180, 0);

  Serial.println("Valor VRx: ");
  Serial.println(map(valorVRx, 0, 1023, 180, 0)); // converte o valor "passado" pelo joystick para graus de 0 ate 180(eixo x)

  Serial.println("  Valor VRy: ");
  Serial.println(map(valorVRy, 0, 1023, 0, 180)); // converte o valor "passado" pelo joystick para graus de 0 ate 180 (eixo y)

  if (statusSW) {  // verifica o botão apertado ou não
    Serial.println("  Botao: [Solto] ");
  } else {
    Serial.println("  Botao: [Apertado] ");
    buzzer();
  }

  // ---------------  eixo y -----------------------

  if (aux1 > 150 || !statusSW) {
    digitalWrite(pinoLed1, HIGH);
  }
  else {
    digitalWrite(pinoLed1, LOW);
  }

  if (aux1 < 50 || !statusSW) {
    digitalWrite(pinoLed2, HIGH);
  }
  else {
    digitalWrite(pinoLed2, LOW);
  }

  // --------------  eixo x ------------------------

  if (aux2 > 150 || !statusSW) {
    digitalWrite(pinoLed3, HIGH);
  }
  else {
    digitalWrite(pinoLed3, LOW);
  }

  if (aux2 < 50 || !statusSW) {
    digitalWrite(pinoLed4, HIGH);
  }
  else {
    digitalWrite(pinoLed4, LOW);
  }
}
void buzzer() { // função para ligar os leds e colocar o delay 
  digitalWrite(pinoLed1, HIGH);
  digitalWrite(pinoLed2, HIGH);
  digitalWrite(pinoLed3, HIGH);
  digitalWrite(pinoLed4, HIGH);
  digitalWrite(pinoBuzzer, HIGH);
  delay(50);
  digitalWrite(pinoBuzzer, LOW);
  digitalWrite(pinoLed1, LOW);
  digitalWrite(pinoLed2, LOW);
  digitalWrite(pinoLed3, LOW);
  digitalWrite(pinoLed4, LOW);
  delay(250);
};
