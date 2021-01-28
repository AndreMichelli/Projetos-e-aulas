void setup() {

  pinMode(7, INPUT); // Sensor de fogo

  pinMode(2, OUTPUT); // Buzzer

}

void loop() {

  if (digitalRead(7) == HIGH) { // Verifica se há fogo sendo detectado pelo sensor

    digitalWrite(2, HIGH); //

    delay(200);           //  Faz o buzzer apitar com intervalos

    digitalWrite(2, LOW); //

    delay(200);           //
  }
  else {

    digitalWrite(2, LOW); // Desliga o buzzer caso não tenha fogo

  }

}
