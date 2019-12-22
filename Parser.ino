#include "Parser.h"

void Parser::showValue1(char *token, char *topic)
{
  if (strcmp(topic, "/home/backyard/sds11") == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("PM10: ");
    lcd.print(token);
    lcd.print("um");
  } else if (strcmp(topic, "/home/backyard/dht11") == 0) 
  {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(token);
    lcd.print("C");
  }
}

void Parser::showValue2(char *token, char *topic)
{
  if (strcmp(topic, "/home/backyard/sds11") == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("PM2.5: ");
    lcd.print(token);
    lcd.print("um");
  } else if (strcmp(topic, "/home/backyard/dht11") == 0) 
  {
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(token);
    lcd.print("%");
  }
}

void Parser::splitCharArray(char *token, char values[], char *topic)
{
    token = strtok(values, ",");
    showValue1(token, topic);
    token = strtok(NULL, ",");
    if (token != NULL)
    {
      showValue2(token, topic);
    }
}
