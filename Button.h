#include <Arduino.h>

#ifndef BUTTON_H
#define BUTTON_H

class Button {
  private:
    int _buttonPin;
    int _lcdState = LOW;
    int _previousState;
    int _currentState = HIGH;
    
  public:
    Button(const int buttonPin);
    int read();
};

#endif
