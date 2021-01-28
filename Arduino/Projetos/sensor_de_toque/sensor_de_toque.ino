//------------------------------------------------------------------------------------------------------------------------------------------ 
//led no pino 13
const int pinLed =  13;
//sensor de toque no pino 3
const int pinToque = 3;
 
//armazena o estado anterior do sensor
unsigned long estadoAnt = 0;
//armazena o estado do led
boolean ledOn = false;

//------------------------------------------------------------------------------------------------------------------------------------------ 

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinToque, INPUT);
}

//------------------------------------------------------------------------------------------------------------------------------------------ 
 
void loop(){
  //lê o sensor de toque
  int estadoToque = digitalRead(pinToque);
 
  //caso receba toque
  if (estadoToque == HIGH) {
    
    // da o intervalo de 50ms para o segundo toque ser contabilizado
    if (millis() - estadoAnt > 50) {
    
      //liga o led
      ledOn = !ledOn;
      
      digitalWrite(pinLed, ledOn ? HIGH : LOW);
    }
 
    //lembra quanto ocorreu o estado anterior
    estadoAnt = millis();
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------ 
