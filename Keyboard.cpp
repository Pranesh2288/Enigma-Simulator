#include "Keyboard.h"

Keyboard::Keyboard()
{
    str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

int Keyboard::forward(char letter)
{
    int signal = str.find(letter);
    return signal;
}

char Keyboard::backward(int signal)
{
    char letter = str[signal];
    return letter;
}
