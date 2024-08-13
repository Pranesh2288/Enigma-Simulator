#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
#include "Enigma.h"
using namespace std;

int main()
{
    Enigma ENIGMA = Enigma('A', {"I", "II", "III"}, {{'A', 'A'}}, {'A', 'A', 'A'}, {1, 1, 1});
    cout << ENIGMA.encipher("VCODLLP") << endl;
    return 0;
}