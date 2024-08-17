#include "Enigma.h"
#include <iostream>

Enigma::Enigma(char reflector, vector<string> rotors, vector<int> rings, vector<char> key, vector<pair<char, char>> plugboard)
    : Reflector(reflector), // Initialize base class Reflector
      Rotor(rotors[0]),     // Initialize base class Rotor
      Plugboard(plugboard), // Initialize base class Plugboard
      Keyboard(),           // Initialize base class Keyboard
      re(reflector),        // Initialize member re
      r1(rotors[0]),        // Initialize member r1
      r2(rotors[1]),        // Initialize member r2
      r3(rotors[2]),        // Initialize member r3
      pb(plugboard),        // Initialize member pb
      kb()                  // Initialize member kb
{
    setKey(key);
    setRings(rings);
}

void Enigma::setKey(vector<char> key)
{
    r1.set_key(key[0]);
    r2.set_key(key[1]);
    r3.set_key(key[2]);
}

void Enigma::setRings(vector<int> key)
{
    r1.set_ring(key[0]);
    r2.set_ring(key[1]);
    r3.set_ring(key[2]);
}

char Enigma::encipher(char letter)
{
    if ((r2.left[25] == r2.notch) && (r3.left[25] == r3.notch))
    {
        r1.rotate();
        r2.rotate();
        r3.rotate();
    }
    else if (r2.left[25] == r2.notch)
    {
        r1.rotate();
        r2.rotate();
        r3.rotate();
    }
    else if (r3.left[25] == r3.notch)
    {
        r2.rotate();
        r3.rotate();
    }
    else
    {
        r3.rotate();
    }

    int signal = kb.forward(letter);
    signal = pb.forward(signal);
    signal = r3.forward(signal);
    signal = r2.forward(signal);
    signal = r1.forward(signal);
    signal = re.reflect(signal);
    signal = r1.backward(signal);
    signal = r2.backward(signal);
    signal = r3.backward(signal);
    signal = pb.backward(signal);
    letter = kb.backward(signal);

    return letter;
}

string Enigma::encipher(string message)
{
    string cipher_text = "";
    for (char letter : message)
    {
        if (letter >= 'a' && letter <= 'z')
        {
            letter = toupper(letter);
            cipher_text += encipher(letter);
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            cipher_text += encipher(letter);
        }
        else
        {
            cipher_text += letter;
        }
    }
    return cipher_text;
}

void Enigma::showSettings()
{
    cout << "Reflector: " << re.getName() << endl;
    cout << "Rotors (from left to right): " << r1.getName() << " " << r2.getName() << " " << r3.getName() << endl;
    cout << "Key: " << r1.getKey() << " " << r2.getKey() << " " << r3.getKey() << endl;
    cout << "Ring: " << r1.getRing() << " " << r2.getRing() << " " << r3.getRing() << endl;
    vector<pair<char, char>> p = pb.getPair();
    cout << "Plugs: ";
    if (p[0].first == 'A' && p[0].second == 'A')
        cout << endl;
    else

    {
        for (pair<char, char> pair : p)
        {
            cout << pair.first << pair.second << ", ";
        }
        cout << "\b\b " << endl;
    }
}