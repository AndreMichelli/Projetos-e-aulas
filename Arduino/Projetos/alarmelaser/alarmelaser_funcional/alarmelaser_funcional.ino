
int var;

void setup() {
  
  pinMode(A0,INPUT); // ldr
  pinMode(7,OUTPUT); // buzzer
  Serial.begin(9600); // inicia o monitor serial

}

void loop() {

  var = analogRead(A0); // Da o valor da intensidade do laser para a variavel var
  if(var < 500){ // verifica, pela intensidade do laser se deve apitar ou não
    Serial.println("Estavel"); 
    Serial.println(var); 
    digitalWrite(7,LOW);
    delay(500);
} else{
    Serial.println("ALARME!");
    Serial.println(var);
    digitalWrite(7,HIGH);
    delay(500);
}

}
