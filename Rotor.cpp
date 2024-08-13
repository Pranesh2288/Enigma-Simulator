#include "Rotor.h"
#include <iostream>

Rotor::Rotor(const string &name)
{
    left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (name == "I")
    {
        right = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        notch = 'Q';
    }
    else if (name == "II")
    {
        right = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        notch = 'E';
    }
    else if (name == "III")
    {
        right = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        notch = 'V';
    }

    else if (name == "IV")
    {
        right = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        notch = 'J';
    }
    else if ("V")
    {
        right = "VZBRGITYUPSDNHLXAWMJQOFECK";
        notch = 'Z';
    }
    else
    {
        right = left;
        notch = 'A';
    }
}

int Rotor::forward(int signal)
{
    char letter = right[signal];
    signal = left.find(letter);
    return signal;
}

int Rotor::backward(int signal)
{
    char letter = left[signal];
    signal = right.find(letter);
    return signal;
}

void Rotor::show()
{
    cout << "L: " << left << endl;
    cout << "R: " << right << endl;
    cout << endl;
}

void Rotor::rotate(int n, bool forward)
{
    if (forward)
    {
        for (int i = 0; i < n; i++)
        {
            left = left.substr(1, 26) + left[0];
            right = right.substr(1, 26) + right[0];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            left = left[25] + left.substr(0, 25);
            right = right[25] + right.substr(0, 25);
        }
    }
}

void Rotor::rotate_to_letter(char letter)
{
    int n = left.find(letter);
    rotate(n);
}

void Rotor::set_ring(int n)
{
    rotate(n - 1, false);
    int n_notch = left.find(notch);
    if ((n_notch - n) % 26 >= 0)
        notch = left[(n_notch - n) % 26];
    notch = left[((n_notch - n) % 26 + 26) % 26];
}
