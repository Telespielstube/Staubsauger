#include "Button.h"

Button::Button(int buttonPin)
{
  _buttonPin = buttonPin;
  _previousState = LOW;
  pinMode(_buttonPin, INPUT);
  read();
}

int Button::read()
{
  _currentState = digitalRead(_buttonPin);

  if (_currentState != _previousState && _currentState == HIGH)
  {  
    if (_lcdState == HIGH) 
    {
      _lcdState = LOW;
    } else {
      _lcdState = HIGH;
    }
  }
    _previousState = _currentState;

  return _lcdState;
}
