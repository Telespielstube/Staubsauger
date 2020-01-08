#include "Connection.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

Connection::Connection(char const *ssid, char const *password, char const *mqttServer, int mqttPort, char *mqttUser, char const *mqttPassword, WiFiClient *wifiClient, PubSubClient *subClient) {
  _ssid = ssid;
  _password = password;
  _mqttServer = mqttServer;
  _mqttPort = mqttPort;
  _mqttUser = mqttUser;
  _mqttPassword = mqttPassword;
  _wifiClient = wifiClient;
  _subClient = subClient;
}

// Function to connect to wifi access point.
void Connection::connectToWifi() {
  Serial.print("Trying to connect to network: " + String(_ssid));
  randomSeed(micros());
  WiFi.begin(_ssid, _password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(300);
  }
  Serial.println("Connected to: " + WiFi.SSID());
  Serial.println("IP address: " + WiFi.localIP());
  delay(3000);
}

bool Connection::connectToBroker() {
  if (_subClient->connected()) {
    return true;
  }
  _subClient->setServer(_mqttServer, _mqttPort);
  Serial.println("Connecting to MQTT broker");
  while (!_subClient->connected()) {
    String clientId = "Staubfaenger";
    clientId += String(random(0xffff), HEX);
    if (_subClient->connect(clientId.c_str(), _mqttUser, _mqttPassword)) {
      Serial.println(clientId + " is connected");
      return true;
    } else {
      Serial.print("Could not connect. " + _subClient->state());
    }
  }
  return false;
}
