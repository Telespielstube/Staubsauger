#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
  private:
    // Client credentials
    char const *_ssid;
    char const *_password;
    char const *_mqttServer;
    int _mqttPort;
    char *_mqttUser;
    char const *_mqttPassword;
    WiFiClient _wifiClient;
    PubSubClient _subClient;

  public:
    Connection(char const *ssid, char const *password, char const *mqttServer, int mqttPort, char *mqttUser, char const *mqttPassword, WiFiClient &wifiClient, PubSubClient &subClient);
    void connectToWifi();
    void connectToBroker();
};
#endif
