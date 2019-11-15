#include "Button.h"

Button::Button(const int BUTTONPIN)
{
    _BUTTONPIN = BUTTONPIN;
    _previousState = 0;
    pinMode(BUTTONPIN, INPUT);
}

void Button::read()
{}
}
