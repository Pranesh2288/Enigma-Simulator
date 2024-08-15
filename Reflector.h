#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>
using namespace std;
class Reflector
{
public:
    string left;
    string right;
    string name;

    Reflector(const char &name);
    int reflect(int signal);
    string getName();
};

#endif