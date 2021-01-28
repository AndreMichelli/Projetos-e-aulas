/**
 * #######################################################################
 * Software Arduino Sonar Monitor
 *
 * alterado por Rodrigues <https://rodriguesfas.github.io>
 * by Dejan Nedelkovski <www.HowToMechatronics.com>  
 *########################################################################
 */

 /*Inclue bibliotecas*/

 #include <NewPing.h>

 #define TRIGGER_PIN  5    /* Arduino pino trigger (envia onda)*/
 #define ECHO_PIN     6    /* Arduino pino echo (recebe onda) */
 #define MAX_distancia 60  /* Distancia máxima do ping em centimetro. */ 

 NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_distancia); /* NewPing configuração de pinos e distancia máxima. */

 int distancia;


/**
 * setup -
 */
 void setup() {
  Serial.begin(9600); /* Config serial monitor (valor taxa de transmição). */

}


/**
 * loop - 
 */
 void loop() {
calcularPING();

}
 int calcularPING(){ 
  unsigned int uS = sonar.ping();  /* Envia ping, retorna ping tempo em microseconds (uS). */
  distancia = uS / US_ROUNDTRIP_CM; /* Converte oing tempo para distancia em cm e retorana resultado. */
  return distancia; 
}
