#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <string>
#include <vector>
using namespace std;

class Plugboard
{
public:
    string left;
    string right;
    vector<pair<char, char>> p;

    Plugboard(vector<pair<char, char>> pairs);
    int forward(int signal);
    int backward(int signal);
    vector<pair<char, char>> getPair();
};

#endif