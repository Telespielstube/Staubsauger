#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
private:
    // Client credentials
    const char *_SSID;
    const char *_PASSWORD;
    const char *_MQTTSERVER;
    int _MQTTPORT;
    char *_MQTTUSER;
    char *_MQTTPASSWORD;
    WiFiClient *_wifiClient;
    PubSubClient *_subClient;

public:
    Connection(const char *SSID, const char *PASSWORD, const char *MQTTSERVER, int MQTTPORT, char *MQTTUSER, char *MQTTPASSWORD, WiFiClient *wifiClient, PubSubClient *subClient);
    void connectToWifi();
    void connectToBroker();
};
#endif