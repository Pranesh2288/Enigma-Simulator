#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>
using namespace std;
class Reflector
{
public:
    string left;
    string right;

    Reflector(const char &name);
    int reflect(int signal);
};

#endif