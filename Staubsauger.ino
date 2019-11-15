/** Implements subscriber client of an MQTT infrastructure.
 *  
 */
#include "Connection.h"
//#include "Button.h"
#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//const int BUTTONPIN = D0;
const char *SSID = "Telespielstube_2.0";
const char *PASSWORD = "8757420130565695";
const char *MQTTSERVER = "broker.hivemq.com";
int MQTTPORT = 1883;
char *MQTTUSER = "telespielstube";
char *MQTTPASSWORD = "12345";
char *topicToSubscribe = "/home/backyard/#";

WiFiClient wifiClient;
PubSubClient subClient(wifiClient);
LiquidCrystal lcd(D5, D6, D1, D2, D3, D4);
//LiquidCrystal lcd(D5, D6, D1, D2, D3, D4);
Connection connection(SSID, PASSWORD, MQTTSERVER, MQTTPORT, MQTTUSER, MQTTPASSWORD, &wifiClient, &subClient);
//Button button(BUTTONPIN);

void setup() 
{
    randomSeed(micros());
    lcd.begin(16, 2);
    Serial.begin(115200); 
    lcd.println("Hello from screen");
    connection.connectToWifi();
    connection.connectToBroker();
    
    subClient.setCallback(callback);
}

// Function to get the message and print it on screen.
void callback(char *topic, byte *payload, unsigned int length)
{
 // Serial.println("Message arrived.");
  Serial.println(topic);
  for (int i=0; i < length; i++)
  {
    Serial.print((char)payload[i]);

  }
  Serial.println();
}

void loop()
{
  if (!subClient.connected())
  {
    connection.connectToBroker();
  } 
  subClient.loop();
  subClient.subscribe(topicToSubscribe);
}
