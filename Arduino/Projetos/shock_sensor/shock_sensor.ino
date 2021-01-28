
int pinLed = 8;
int pinSensor  = 2; 
boolean dormindo;
int contadorLoop = 0;
long inicioTimer = 0;
long tempoEntre = 2000;
long acordado = 0;


void setup() {
 
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);
  attachInterrupt(0,shakeInterrupt, FALLING);
  pinMode(pinLed, OUTPUT);
  }

void loop() {

    if(dormindo){   
      contadorLoop++;
      if(contadorLoop == 10){               
      Serial.println("o sensor esta dormindo");
      contadorLoop = 0;
      digitalWrite(pinLed, LOW);
  }

  
  } else if(dormindo == false){
        contadorLoop++;
        if(contadorLoop == 10){
           Serial.println("acordado, detectou vibracao");
           contadorLoop = 0;
           digitalWrite(pinLed, HIGH);
    }
        acordado = millis() - inicioTimer;
        if(acordado > tempoEntre){
        dormindo = true;
        Serial.println("indo dormir");
    }
  }
}

  void shakeInterrupt(){
    dormindo = false;
    inicioTimer = millis();
  }
