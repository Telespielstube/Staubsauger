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
char const *topicSds11 = "/home/backyard/#";
int buttonState = HIGH;

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
void callback(char *topic, byte *payload, int const messageLength)
{
  lcd.clear();
  if (!((strcmp(topic, "/home/backyard/sds11") == 0 && buttonState == LOW) ||
        (strcmp(topic, "/home/backyard/dht11") == 0 && buttonState == HIGH))){
      return;
  }
  if (strcmp(topic, "/home/backyard/sds11") == 0 && buttonState == HIGH)
  {
      return;
  }
  if (strcmp(topic, "/home/backyard/dht11") == 0 && buttonState == LOW)
  {
      return;
  }    
  char values[9];
  for (int i = 0; i < messageLength; ++i)
  {
    values[i] = payload[i];
  }
  char *token;
  parser.splitCharArray(token, values, topic);
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
  buttonState = button.read();
  subClient.subscribe(topicSds11);
}
