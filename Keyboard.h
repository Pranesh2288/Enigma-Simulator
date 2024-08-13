#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
using namespace std;

class Keyboard
{
public:
    string str;
    Keyboard();
    int forward(char letter);
    char backward(int signal);
};

#endif // KEYBOARD_H