#include "Display.h"

void Display::showTemperature(char *temperature, char *humidity) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");
}
void Display::showFineDust(char *PM10, char *PM25) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PM10: ");
  lcd.print(PM10);
  lcd.print(" um");

  lcd.setCursor(0, 1);
  lcd.print("PM25: ");
  lcd.print(PM25);
  lcd.print(" um");  
}
