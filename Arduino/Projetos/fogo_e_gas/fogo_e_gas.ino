
#define Fumaca A5
#define Fogo 7

#define vermelho 8
#define verde 9
#define azul 10

int controleFum = 200;

void setup() {

  pinMode(Fumaca, INPUT);
  pinMode(Fogo, INPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

}

void loop() {

  int analogFum = analogRead(Fumaca);
  int digitalFogo = digitalRead(Fogo);

  Serial.print("Fumaça: ");
  Serial.println(analogFum);

  Serial.print("Fogo: ");
  Serial.println(analogFum);

  if (analogFum <= controleFum && digitalFogo == LOW) { // quando não detecta gás nem fogo
    digitalWrite(verde, HIGH);
    digitalWrite(vermelho, LOW);
    digitalWrite(azul, LOW);
  }

  if (analogFum > controleFum && digitalFogo == LOW) { // caso detectar apenas gás
    digitalWrite(verde, HIGH);
    digitalWrite(vermelho, LOW);
    digitalWrite(azul, HIGH);
  }

  if (analogFum <= controleFum && digitalFogo == HIGH) { // caso detectar apenas fogo
    digitalWrite(verde, HIGH);
    digitalWrite(vermelho, HIGH);
    digitalWrite(azul, HIGH);
  }

  if (analogFum > controleFum && digitalFogo == HIGH) { // caso detecte fogo e gás
    digitalWrite(verde, HIGH);
    delay(100);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, HIGH);
    delay(100);
    digitalWrite(vermelho, LOW);
    digitalWrite(azul, HIGH);
    delay(100);
    digitalWrite(azul, LOW);
  }

}
