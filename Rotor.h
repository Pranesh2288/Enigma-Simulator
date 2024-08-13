#ifndef ROTOR_H
#define ROTOR_H

#include <string>
using namespace std;

class Rotor
{
public:
    string left;
    string right;
    char notch;

    Rotor(const string &name);
    int forward(int signal);
    int backward(int signal);
    void show();
    void rotate(int n = 1, bool forward = true);
    void rotate_to_letter(char letter);
    void set_ring(int n);
};
#endif