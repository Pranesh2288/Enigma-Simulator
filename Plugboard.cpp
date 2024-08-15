#include "Plugboard.h"

Plugboard::Plugboard(vector<pair<char, char>> pairs)
{
    p = pairs;
    left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    right = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (pairs.size() == 0)
        return;

    for (auto pair : pairs)
    {
        char A = pair.first;
        char B = pair.second;
        int pos_A = left.find(A);
        int pos_B = left.find(B);
        left = left.substr(0, pos_A) + B + left.substr(pos_A + 1, size(left));
        left = left.substr(0, pos_B) + A + left.substr(pos_B + 1, size(left));
    }
}

int Plugboard::forward(int signal)
{
    char letter = right[signal];
    signal = left.find(letter);
    return signal;
}

int Plugboard::backward(int signal)
{
    char letter = left[signal];
    signal = right.find(letter);
    return signal;
}

vector<pair<char, char>> Plugboard::getPair()
{
    return p;
}