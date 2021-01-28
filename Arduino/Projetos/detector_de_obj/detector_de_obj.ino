
int pinSensor  = A0;
int contador = 0;
int detector = 20;
int ultimoValor;
int botao = 8;

void setup() {
  
  pinMode(pinSensor, INPUT);
  pinMode(botao, INPUT);
  digitalWrite(botao, HIGH); //ativa o resistor pull-up
  Serial.begin(9600);

}

void loop() {
  
  int a = analogRead(pinSensor);
  int estadoBotao = digitalRead(botao);
  Serial.print("Valor recebido = ");
  Serial.print(a);
  Serial.print(" |        Estado do botao = ");
  Serial.print(estadoBotao);

  if(a < detector && ultimoValor > 900){
    Serial.print("|      Objeto detectado. Contador = ");
    contador ++;
    Serial.print(contador);
  }
  if(estadoBotao == 0){
    resetContador();
  }

  ultimoValor = a;
  delay(200);
  Serial.println();

}

void resetContador(){
  contador = 0 ;
  Serial.println(" |       Contador = 0");
  delay(1000);
  }
