#include "Parser.h"

void Parser::showValue1(char *token, char *topic)
{
  if (strcmp(topic, "/home/backyard/sds11") == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("PM10: ");
    lcd.print(token);
  } 
  if (strcmp(topic, "/home/backyard/dht11") == 0) 
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
  } 
  if (strcmp(topic, "/home/backyard/dht11") == 0) 
  {
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(token);
    lcd.print("pc");
  }
}

void Parser::splitCharArray(char *token, char values[], char *topic)
{
    token = strtok(values, ",");
    showValue1(token, topic);
    while (token != NULL)
    {
      token = strtok(NULL, ",");
      showValue2(token, topic);
    }
}



//char *Parser::byteToCharArray(byte *payload, int messageLength)
//{
//  char values[10];
//  for (int i = 0; i < messageLength; ++i)
//  {
//    values[i] = payload[i];
//  }
//  return values;
//}

void Parser::showTemperature(char *token)
{
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(token);
  lcd.print("C");
}

void Parser::showHumidity(char *token)
{
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(token);
  lcd.print("pc");
}

void Parser::showPm10(char *token)
{
  lcd.setCursor(0, 0);
  lcd.print("PM10: ");
  lcd.print(token);
}

void Parser::showPm25(char *token)
{
  lcd.setCursor(0, 1);
  lcd.print("PM2.5: ");
  lcd.print(token);
  lcd.print('%');
  
}
