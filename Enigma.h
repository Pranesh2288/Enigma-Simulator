#ifndef ENIGMA_H
#define ENIGMA_H

#include "Keyboard.h"
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
#include <vector>
using namespace std;

class Enigma : public Keyboard, public Plugboard, public Rotor, public Reflector
{
public:
    Reflector re;
    Rotor r1, r2, r3;
    Plugboard pb;
    Keyboard kb;

    Enigma(char reflector, vector<string> rotors, vector<char> key, vector<int> rings, vector<pair<char, char>> plugboard);
    void setKey(vector<char> key);
    void setRings(vector<int> key);
    char encipher(char letter);
    string encipher(string message);
    void showSettings();
};

#endif