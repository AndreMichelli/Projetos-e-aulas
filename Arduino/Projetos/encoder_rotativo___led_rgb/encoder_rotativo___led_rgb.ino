#define pinoCLK 3
#define pinoDT 4  
#define pinoSW 5 
#define ledAzul 8
#define ledVerm 10
#define ledVerde 9 

int contadorPos = 0;
int ultPosicao; 
int leituraCLK; 
boolean bCW; 

void setup() {
  Serial.begin (9600); //INICIALIZA A SERIAL

  pinMode (pinoCLK, INPUT); //DEFINE O PINO COMO ENTRADA

  pinMode (pinoDT, INPUT); //DEFINE O PINO COMO ENTRADA

  pinMode (pinoSW, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO

  pinMode (ledAzul, OUTPUT); 
  
  pinMode (ledVerm, OUTPUT);

  pinMode (ledVerde, OUTPUT);

  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)

  ultPosicao = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK
}

void loop() {

  leituraCLK = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK

  if (leituraCLK != ultPosicao) { //SE VALOR DA VARIÁVEL FOR DIFERENTE DO VALOR DE "ultPosicao", FAZ

    if (digitalRead(pinoDT) != leituraCLK) { //SE LEITURA DO PINO FOR DIFERENTE DA LEITURA DE "leituraCLK",
      //SIGNIFICA QUE O EIXO ESTÁ SENDO GIRADO NO SENTIDO HORÁRIO
      contadorPos ++; //INCREMENTA CONTAGEM DA VARIÁVEL EM +1
      bCW = true; //VARIÁVEL BOOLEANA RECEBE VERDADEIRO (SENTIDO HORÁRIO)
    }

    else { //SENÃO, SIGNIFICA QUE O EIXO ESTÁ SENDO GIRADO NO SENTIDO ANTI-HORÁRIO E FAZ
      bCW = false; //VARIÁVEL BOOLEANA RECEBE FALSO (SENTIDO ANTI-HORÁRIO)
      contadorPos--; //DECREMENTA CONTAGEM DA VARIÁVEL EM -1
    }
    Serial.print("Giro no "); //IMPRIME O TEXTO NA SERIAL

    if (bCW) { //SE VARIÁVEL FOR IGUAL A VERDADEIRO, FAZ
      Serial.print("sentido anti-horário"); //IMPRIME O TEXTO NA SERIAL
    }

    else { //SENÃO, FAZ
      Serial.print("sentido horário"); //IMPRIME O TEXTO NA SERIAL
    }
    Serial.print(" / Posição do encoder: "); //IMPRIME O TEXTO NA SERIAL
    Serial.println(contadorPos); //IMPRIME NO MONITOR SERIAL A POSIÇÃO ATUAL DO ENCODER
  }

  if (digitalRead(pinoSW) == LOW) { //SE LEITURA DO PINO FOR IGUAL A LOW, FAZ
    Serial.println ("Botão pressionado"); //IMPRIME O TEXTO NA SERIAL
    pisca();
    delay(200); //INTERVALO DE 200 MILISSEGUNDOS
  }

  leds();
  
  ultPosicao = leituraCLK; //VARIÁVEL RECEBE O VALOR DE "leituraCLK"
}

void leds(){

  if (contadorPos <= 0){
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledVerde, LOW);
  }
  
  if (contadorPos < 20 && contadorPos > 0){
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledVerde, LOW);
  }

  if (contadorPos > 20 && contadorPos < 40){
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledVerde, LOW);
  }
  
  if (contadorPos > 40 && contadorPos < 60){
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledVerde, HIGH);
  }

  if (contadorPos > 60){
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledVerde, HIGH);
  }
};

void pisca(){
    digitalWrite(ledAzul, HIGH);
    delay(100);
    digitalWrite(ledAzul, LOW);
    delay(10);
    digitalWrite(ledVerm, HIGH);
    delay(100);
    digitalWrite(ledVerm, LOW);
    delay(10);
    digitalWrite(ledVerde, HIGH);
    delay(100);
    digitalWrite(ledVerde, LOW);
    delay(10);
};
