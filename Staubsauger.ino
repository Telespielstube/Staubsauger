/** Implements subscriber client of an MQTT infrastructure.

*/
#include "Connection.h"
#include "Button.h"
#include "Parser.h"
#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int buttonPin = D0;
//char const *ssid = "MartaiPhone";
//char const *password = "mqttProject";
char const *ssid = "Telespielstube_2.0";
char const *password = "8757420130565695";
char const *mqttServer = "broker.hivemq.com";
int mqttPort = 1883;
char *mqttUser = "telespielstube";
char const *mqttPassword = "12345";
char const *topicDht11 = "/home/backyard/dht11";
char const *topicSds11 = "/home/backyard/sds11";

WiFiClient wifiClient;
PubSubClient subClient(wifiClient);
//LiquidCrystal lcd(D5, D6, D1, D2, D3, D4);
LiquidCrystal lcd(14, 12, 5, 4, 0, 2);
Connection connection(ssid, password, mqttServer, mqttPort, mqttUser, mqttPassword, wifiClient, subClient);
Button button(buttonPin);
Parser parser;

void setup()
{
  randomSeed(micros());
  lcd.begin(16, 2);
  Serial.begin(115200);

  connection.connectToWifi();
  connection.connectToBroker();
  subClient.setCallback(callback);
}

// Function to get the message and print it on lcd.
char callback(char *topic, byte *payload, int const messageLength)
{
  lcd.clear();
  char values[10];
  for (int i = 0; i < messageLength; ++i)
  {
    values[i] = payload[i];
  }
  char *token;
  if (strcmp(topic, "/home/backyard/dht11") == 0)
  {   
    token = strtok(values, ",");
    parser.showTemperature(token);
    while (token != NULL)
    {
      token = strtok(NULL, ",");
      parser.showHumidity(token);
    }
  }
  if (strcmp(topic, "/home/backyard/sds11") == 0)
  {
    //parser.splitCharArray(token, values, topic);
    token = strtok(values, ",");
    parser.showPm10(token);
    while (token != NULL)
    {
      token = strtok(NULL, ",");
      parser.showPm25(token);
    }
  }
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    connection.connectToWifi();
  } else if (!subClient.connected())
  {
    connection.connectToBroker();
  }
  subClient.loop();
  if (button.read()  == HIGH)
  {
    subClient.subscribe(topicDht11);
  } else
  {
    subClient.subscribe(topicSds11);
  }
}
