#include <Arduino.h>

#ifndef DISPLAY_H
#define DISPLAY_H
class Display {

  private:
    //

  public:
    void showValue1(char *token, char *topic);
    void showValue2(char *token, char *topic);
    void showTemperature(char *temperature, char *humidity);
    void showFineDust(char *PM25, char *PM10);

};
#endif
