int A = 12;
int B = 11;
int C = 10;
int D = 9;
int E = 8;
int F = 7;
int G = 6;

void setup() {
  for (int i=6; i < 13; i++ ){ // inicializa cada pino do 6 ao 13, usando for para encurtar codigo
      pinMode(i, OUTPUT);
    }
}

void loop() {
apagado(); // Numero 0
 digitalWrite(A ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(C ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(E ,HIGH);
 digitalWrite(G ,HIGH);
 delay(1000);

apagado();  // Numero 1
 digitalWrite(B ,HIGH);
 digitalWrite(C ,HIGH);
 delay(1000);

apagado();  // Numero 2
 digitalWrite(A ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(E ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(F ,HIGH);
 delay(1000);

apagado(); // Numero 3
 digitalWrite(A ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(C ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(F ,HIGH);
 delay(1000);

apagado(); // Numero 4
 digitalWrite(G ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(F ,HIGH);
 digitalWrite(C ,HIGH);
 delay(1000); 

apagado();  // Numero 5
 digitalWrite(A ,HIGH);
 digitalWrite(G ,HIGH);
 digitalWrite(C ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(F ,HIGH);
 delay(1000);

apagado(); // Numero 6
 digitalWrite(A ,HIGH);
 digitalWrite(G ,HIGH);
 digitalWrite(C ,HIGH);
 digitalWrite(E ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(F ,HIGH);
 delay(1000);

apagado(); // Numero 7
 digitalWrite(A ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(C ,HIGH);
 delay(1000);

apagado(); // Numero 8
 digitalWrite(A ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(C ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(E ,HIGH);
 digitalWrite(F ,HIGH);
 digitalWrite(G ,HIGH);
 delay(1000);

apagado(); // Numero 9
 digitalWrite(A ,HIGH);
 digitalWrite(B ,HIGH);
 digitalWrite(C ,HIGH);
 digitalWrite(D ,HIGH);
 digitalWrite(F ,HIGH);
 digitalWrite(G ,HIGH);
 delay(1000);

}
void apagado(){ // função que faz display resentar antes de printar outro numero
  digitalWrite(A ,LOW);
  digitalWrite(B ,LOW);
  digitalWrite(C ,LOW);
  digitalWrite(D ,LOW);
  digitalWrite(E ,LOW);
  digitalWrite(F ,LOW);
  digitalWrite(G ,LOW);
}
