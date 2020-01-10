#include <Arduino.h>

#ifndef PARSER_H
#define PARSER_H
class Parser {

  private:   
    //
    
  public:
    /* Splits the message payload in two substrings.
     *  
     *  @param values[]   message payload 
     *  @param **value1   pointer to values array to access 
     */
    void readValues(char values[], char **value1, char **value2);
};
#endif
