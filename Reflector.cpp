#include "Reflector.h"

Reflector::Reflector(const char &name)
{
    left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (name == 'A')
    {
        right = "EJMZALYXVBWFCRQUONTSPIKHGD";
    }
    else if (name == 'B')
    {
        right = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    }
    else if (name == 'C')
    {
        right = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
    }
    else
    {
        right = left;
    }
}

int Reflector::reflect(int signal)
{
    char letter = right[signal];
    signal = left.find(letter);
    return signal;
}
