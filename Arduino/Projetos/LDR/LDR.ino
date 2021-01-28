

void setup() {
  pinMode(A1, INPUT); // entrada analogica que recebe a luminosidade
  Serial.begin(9600); // inicia o monitor serial
}

void loop() {
  int valorLDR = analogRead(A1); // variavel que recebe o valor de luminosidade
  Serial.print(valorLDR); // printa o valor
  if (valorLDR > 1000){ // valor menor que 100?
    Serial.print("\n Pouca luz! \n");
    }
  else{ // se nao:
    Serial.print("\n luz boa! \n"); 
    }
}
