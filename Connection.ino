#include "Connection.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

Connection::Connection(const char *SSID, const char *PASSWORD, const char *MQTTSERVER, int MQTTPORT, char *MQTTUSER, char *MQTTPASSWORD, WiFiClient *wifiClient, PubSubClient *subClient)
{
  _SSID = SSID;
  _PASSWORD = PASSWORD;
  _MQTTSERVER = MQTTSERVER;
  _MQTTPORT = MQTTPORT;
  _MQTTUSER = MQTTUSER;
  _MQTTPASSWORD = MQTTPASSWORD;
  _wifiClient = wifiClient;
  _subClient = subClient;
}

// Function to connect to wifi access point.
void Connection::connectToWifi()
{
  Serial.print("Trying to connect to network: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);
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
  if (_subClient->connected())
  {
    return;
  }
  
  String clientId = "Staubfaenger";
  clientId += String(random(0xffff), HEX);
  _subClient->setServer(_MQTTSERVER, _MQTTPORT);
  Serial.println("Connecting to MQTT broker");
  while (!_subClient->connected())
  {
    
    if (_subClient->connect(clientId.c_str(), MQTTUSER, MQTTPASSWORD))
    {
      Serial.println(clientId + " is connected");
    } else
    {
      Serial.print("Could not connect. " + _subClient->state());
    }
  }
}
