
int Led1 = 5;
int Led2 = 6;
int buzzer = 7;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 200;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    tone(buzzer, 3000, 300);
  }
  else
  {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
