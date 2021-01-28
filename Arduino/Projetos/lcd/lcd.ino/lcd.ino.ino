#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,6,7,8,9,10,11,12,13);
byte coracao[8] = {
  B01010,
  B10101,
  B10101,
  B10001,
  B01010,
  B01010,
  B00100,
};
void setup() {
  lcd.begin(16, 2, LCD_5x10DOTS);
  lcd.createChar(0, coracao);
}

void loop() {
  lcd.print("TESTANDO");
  delay(5000);
  lcd.clear();
  lcd.print("Outro Teste");
  delay(5000);
  lcd.clear();
  lcd.write(byte(0));
  delay(5000);
  lcd.clear();
}
