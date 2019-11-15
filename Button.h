#include <Arduino.h>

#ifndef BUTTON_H
#define BUTTON_H
class Button
{
    private:
        const int _BUTTONPIN;
        int _previousState;
        int _currentState;
        unsigned long _firstTimestamp;
        unsigned long _secondTimestamp;

    public:
        Button(const int BUTTONPIN);
        read();
        pressed();
};

#endif