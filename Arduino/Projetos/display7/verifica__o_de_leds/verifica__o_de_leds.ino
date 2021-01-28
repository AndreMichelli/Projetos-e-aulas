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
  apagado();
  digitalWrite(A, HIGH);
  delay(300);
  digitalWrite(B, HIGH);
  delay(300);
  digitalWrite(C, HIGH);
  delay(300);
  digitalWrite(D, HIGH);
  delay(300);
  digitalWrite(E, HIGH);
  delay(300);
  digitalWrite(F, HIGH);
  delay(300);
  digitalWrite(G, HIGH);
  delay(300);
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
