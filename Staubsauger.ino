/** Implements subscriber client of an MQTT infrastructure.
*/
#include "Connection.h"
#include "Button.h"
#include "Parser.h"
#include "Display.h"
#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int buttonPin = D0;
char const *ssid = "iPhone";
char const *password = "mqttProject";
char const *mqttServer = "broker.hivemq.com";
int mqttPort = 1883;
char *mqttUser = "telespielstube";
char const *mqttPassword = "12345";
char const *allTopics = "/home/backyard/#";
char *temperature = "0.0";
char *humidity = "0.0";
char *PM10 = "0.0";
char *PM25 = "0.0";
int buttonState = HIGH;

WiFiClient wifiClient;
PubSubClient subClient(wifiClient);
//LiquidCrystal lcd(D5, D6, D1, D2, D3, D4);
LiquidCrystal lcd(14, 12, 5, 4, 0, 2);
Connection connection(ssid, password, mqttServer, mqttPort, mqttUser, mqttPassword, &wifiClient, &subClient);
Button button(buttonPin);
Parser parser;
Display display;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
  connection.connectToWifi();
  if (connection.connectToBroker()) {
      subClient.subscribe(allTopics);
  }
  subClient.setCallback(callback);
}

// Function to fetch messges from broker.
void callback(char *topic, byte *payload, int const messageLength) {
  lcd.clear();
  char values[9];
  char *token;
  for (int i = 0; i < messageLength; ++i) {
    values[i] = payload[i];
  }
  if ((!strcmp(topic, "/home/backyard/sds11") == 0) && (!strcmp(topic, "/home/backyard/dht11") == 0)){
      return;
  }
  if (strcmp(topic, "/home/backyard/sds11") == 0) {
      parser.readValues(token, values, topic, &PM10, &PM25);
      if (buttonState == HIGH)
          return;
  }
  if (strcmp(topic, "/home/backyard/dht11") == 0) {
      parser.readValues(token, values, topic, &temperature, &humidity);
      if (buttonState == LOW)
          return;          
  }    
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connection.connectToWifi();
  } else if (!subClient.connected()) {
    if (connection.connectToBroker())
    {
        subClient.subscribe(allTopics);
    }
  }
  subClient.loop();
  int oldButtonState = buttonState;
  buttonState = button.read();
    if (buttonState == HIGH) {
        display.showFineDust(PM10, PM25);
    } else {
        display.showTemperature(temperature, humidity);
    }
}
