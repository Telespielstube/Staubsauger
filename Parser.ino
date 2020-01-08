#include "Parser.h"

void Parser::splitCharArray(char *token, char values[], char *topic) {
    token = strtok(values, ",");
    display.showValue1(token, topic);
    token = strtok(NULL, ",");
    if (token != NULL)
    {
      display.showValue2(token, topic);
    }
}

void Parser::readValues(char *token, char values[], char *topic, char** value1, char** value2) {
    *value1 = strdup(strtok(values, ","));
    *value2 = strdup(strtok(NULL, ","));
}
