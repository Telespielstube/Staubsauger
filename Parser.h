#include <Arduino.h>

#ifndef PARSER_H
#define PARSER_H
class Parser {

  private:   
    byte _payload;
    unsigned int length;

  public:
    void showTemperature(char *token);
    void showHumidity(char *token);
    void showPm10(char *token);
    void showPm25(char *token);
    void showValue1(char *token, char *topic);
    void showValue2(char *token, char *topic);
    //char *byteToCharArray(byte *payload, int messageLength);
    void splitCharArray(char *token, char values[], char *topic);
};
#endif
