#include <Arduino.h>

#ifndef PARSER_H
#define PARSER_H
class Parser {

  private:   
    //
    
  public:
    /** Breaks the char values array into tokens and copies the tokens to new pointer variables. 
     *  
     *  @param **value1 Value for first line on display.
     *  @param **value2 Value for second line on display.
     */
    void readValues(char values[], char **value1, char **value2);
    /** Breaks the char values array into tokens and copies the tokens to new pointer variables. 
     *  
     *  @param **error  Error message from broker.
     */
    void readError(char values[], char **error);
};
#endif
