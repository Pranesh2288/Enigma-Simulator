#include "Reflector.h"

Reflector::Reflector(const char &N)
{
    name = N;
    left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (N == 'A')
    {
        right = "EJMZALYXVBWFCRQUONTSPIKHGD";
    }
    else if (N == 'B')
    {
        right = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    }
    else if (N == 'C')
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

string Reflector::getName()
{
    return name;
}