
#include <NewPing.h>

#define TRIGGER_PIN  12  // Pino do trigger
#define ECHO_PIN     11  // Pino do echo
#define MAX_DISTANCE 400 // Distancia maxima
#define Buzzer 8 // Pino do Buzzer

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // abre o monitor serial em uma velocidade maior
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  if( sonar.ping_cm() == 0){
    digitalWrite(Buzzer, LOW);
  }

  if (sonar.ping_cm() > 50) {
    nivel1();
  }

  if (sonar.ping_cm() < 50 && sonar.ping_cm() > 10) {
    nivel2();
  }

  if (sonar.ping_cm() <= 10 && sonar.ping_cm() != 0) {
    nivel3();
  }
}

void nivel1() {
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(1000);
};

void nivel2() {
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(500);
};

void nivel3() {
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);
};
