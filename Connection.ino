#include "Connection.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

Connection::Connection(char const *ssid, char const *password, char const *mqttServer, int mqttPort, char *mqttUser, char const *mqttPassword, WiFiClient &wifiClient, PubSubClient &subClient)
{
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
void Connection::connectToWifi()
{
  Serial.print("Trying to connect to network: ");
  Serial.println(_ssid);
  WiFi.begin(_ssid, _password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(300);
  }
  Serial.print("Connected to: ");
  Serial.println(WiFi.SSID());
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(3000);
}

void Connection::connectToBroker()
{
  if (_subClient.connected())
  {
    return;
  }

  String clientId = "Staubfaenger";
  clientId += String(random(0xffff), HEX);
  _subClient.setServer(_mqttServer, _mqttPort);
  Serial.println("Connecting to MQTT broker");
  while (!_subClient.connected())
  {

    if (_subClient.connect(clientId.c_str(), mqttUser, mqttPassword))
    {
      Serial.println(clientId + " is connected");
    } else
    {
      Serial.print("Could not connect. " + _subClient.state());
    }
  }
}
