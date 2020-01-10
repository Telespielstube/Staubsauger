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
    /* Constructor
     *  
     * @param buttonPin   Which pin the button is connected to.
     */
    Button(const int buttonPin);
    /* Reads the state of the button.
     */
    int read();
};

#endif
