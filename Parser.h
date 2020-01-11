#include <Arduino.h>

#ifndef PARSER_H
#define PARSER_H
class Parser {

  private:   
    //
    
  public:
    void splitCharArray(char *token, char values[], char *topic);
    void readValues(char values[], char **value1, char **value2);
};
#endif
