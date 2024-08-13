#include "Enigma.h"

Enigma::Enigma(char reflector, vector<string> rotors, vector<pair<char, char>> plugboard, vector<char> key, vector<int> rings)
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
    r1.rotate_to_letter(key[0]);
    r2.rotate_to_letter(key[1]);
    r3.rotate_to_letter(key[2]);
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
        cipher_text += encipher(letter);
    return cipher_text;
}
