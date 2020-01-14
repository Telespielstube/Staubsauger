#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
  private:
    // Client credentials
    char const *_ssid;
    char const *_password;
    char const *_mqttServer;
    int _mqttPort;
    char *_mqttUser;
    char const *_mqttPassword;
    WiFiClient *_wifiClient;
    PubSubClient *_subClient;

  public:
    /* Constructor to create a Connection object.
     *  
     *  @param *ssid          network name.
     *  @param *password      network password.
     *  @param *mqttServer    broker ip address. 
     *  @param *mqttPort      port the broker listens on. 
     *  @param *mqttUser      user name.
     *  @param *mqttPassword  user password.
     *  @param *wifiClient    Wifi client object.
     *  @param *pubClient     PubSubClient object.
     */
    Connection(char const *ssid, char const *password, char const *mqttServer, int mqttPort, char *mqttUser, char const *mqttPassword, WiFiClient *wifiClient, PubSubClient *subClient);
    /* Connects publisher to the wifi network.
     */
    void connectToWifi();
     /* Connects publisher to the broker.
     */
    bool connectToBroker();
};
#endif
