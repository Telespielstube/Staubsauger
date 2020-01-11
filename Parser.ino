#include "Parser.h"


void Parser::readValues(char values[], char **value1, char **value2) {
    *value1 = strdup(strtok(values, ","));
    *value2 = strdup(strtok(NULL, ","));
}
