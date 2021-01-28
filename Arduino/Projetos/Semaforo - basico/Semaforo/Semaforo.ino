  int  ledVermelho =  12; 
  int  ledAmarelo = 10;
  int  ledVerde = 8;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledVermelho, HIGH);
  delay(1000);
  digitalWrite(ledVermelho, LOW);
  delay(9);
  
  digitalWrite(ledAmarelo, HIGH);
  delay(500);
  digitalWrite(ledAmarelo, LOW);
  delay(9);
  
  digitalWrite(ledVerde, HIGH);
  delay(1000);
  digitalWrite(ledVerde, LOW);
  delay(9);


}
