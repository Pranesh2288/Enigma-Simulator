#include <string>
#include <stdio.h>
#include <cctype>
#include <cstdlib> // for system()
#include <bits/stdc++.h>
#include "Enigma.h"
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/MacOS
#endif
}

void manual()
{
    cout << "Commands: " << endl;
    cout << "detail - To get details about working of enigma machine." << endl;
    cout << "init   - To setup the machine with given settings." << endl;
    // cout << "view   - To view the current settings." << endl;
    cout << "crypt  - To encrypt / decrypt message." << endl;
    cout << "change - To change the settings of the machine." << endl;
    cout << "clear  - Clears screen." << endl;
    cout << "man    - Manual" << endl;
    cout << "exit   - Exit the application." << endl;
}

void details()
{
    std::cout << "### Enigma Machine Overview\n\n";

    std::cout << "The Enigma machine was an encryption device used primarily by Nazi Germany during World War II. "
              << "It transformed plaintext into cipher text through a series of rotors, a plugboard, and a reflector, "
              << "creating a polyalphabetic substitution cipher that was nearly impossible to break without knowing the machine's settings.\n\n";

    std::cout << "#### Components:\n";
    std::cout << "1. **Rotors**: Each rotor contains a scrambled alphabet. As the operator types, the rotors rotate, changing "
              << "the encryption pattern with each keystroke.\n";
    std::cout << "2. **Reflector**: This component reflects the electrical signal back through the rotors, creating a reversible "
              << "encryption process, which means that the same`` settings can be used for both encryption and decryption.\n";
    std::cout << "3. **Plugboard**: The plugboard allows for additional letter swaps, adding another layer of complexity to the cipher.\n\n";

    std::cout << "#### How It Works:\n";
    std::cout << "- **Initialization**: The machine is set up with specific rotor types, their order, initial positions, ring settings, and plugboard connections.\n";
    std::cout << "- **Encryption**: Each key press sends an electrical signal through the plugboard, rotors, and reflector, and then back through the rotors and plugboard to light up a corresponding letter on the display.\n";
    std::cout << "- **Decryption**: Using the same initial settings, the cipher text can be decrypted by typing it back into the machine.\n\n";

    std::cout << "#### Historical Significance:\n";
    std::cout << "The Enigma machine's encryption was considered unbreakable until the Polish Cipher Bureau and later British codebreakers, "
              << "including Alan Turing, developed methods to crack it. Their work played a crucial role in the Allied victory during WWII.\n";
}

int main()
{
    clearScreen();
    cout << "███████ ███    ██ ██  ██████  ███    ███  █████  " << endl
         << "██      ████   ██ ██ ██       ████  ████ ██   ██ " << endl
         << "█████   ██ ██  ██ ██ ██   ███ ██ ████ ██ ███████ " << endl
         << "██      ██  ██ ██ ██ ██    ██ ██  ██  ██ ██   ██ " << endl
         << "███████ ██   ████ ██  ██████  ██      ██ ██   ██ " << endl
         << endl;
    manual();
    Enigma ENIGMA = Enigma('B', {"I", "II", "III"}, {'K', 'A', 'R'}, {13, 21, 5}, {{'A', 'A'}}); // Default settings
    // cout << ENIGMA.encipher("test") << endl;
    while (1)
    {
        string command;
        cout << ">";
        getline(cin, command);
        for (char &c : command)
            c = tolower(c);
        if (command == "init" || command == "change")
        {
            cout << "Enter the Settings of the machine in the following order: " << endl;
            cout << "1. First line should contain Reflector name: Choose one from {'A','B','C'}" << endl
                 << "2. Second line should contain Rotor name and order: Choose three from {'I','II','III','IV','V'}" << endl
                 << "3. Third line should contain three Key-characters: (Capital letters)" << endl
                 << "4. Fouth line should contain three Ring-Numbers:(1-26)" << endl
                 << "5. Last line should contain Plugboard characters:" << endl;
            cout << "Example:" << endl
                 << "A" << endl
                 << "I IV V" << endl
                 << "D V G" << endl
                 << "12 5 16" << endl
                 << "DL HK CM" << endl;

            cout << ">" << endl;
            char reflector;
            vector<string> rotors;
            vector<char> key;
            vector<int> ring;
            vector<pair<char, char>> plugs(10, pair<char, char>{'A', 'A'});

            string temp, input;
            for (int i = 1; i <= 5; i++)
            {
                getline(cin, temp);
                input += temp + "\n";
            }

            istringstream iss(input);
            string line;
            getline(iss, line);
            reflector = line[0];

            getline(iss, line);
            istringstream rotorStream(line);
            string rotor;
            while (rotorStream >> rotor)
            {
                rotors.push_back(rotor);
            }

            getline(iss, line);
            istringstream keyStream(line);
            char keyElement;
            while (keyStream >> keyElement)
            {
                key.push_back(keyElement);
            }

            getline(iss, line);
            istringstream ringStream(line);
            int ringElement;
            while (ringStream >> ringElement)
            {
                ring.push_back(ringElement);
            }

            getline(iss, line);
            istringstream plugsStream(line);
            char plug1, plug2;
            while (plugsStream >> plug1 >> plug2)
            {
                plugs.push_back({plug1, plug2});
            }

            plugs.erase(remove(plugs.begin(), plugs.end(), pair<char, char>{'A', 'A'}), plugs.end());
            if (plugs.size() == 0)
                plugs = {{'A', 'A'}};

            ENIGMA = Enigma(reflector, rotors, key, ring, plugs);
        }
        // else if (command == "view")
        // {
        //     ENIGMA.showSettings();
        // }
        else if (command == "crypt")
        {
            string message;
            cout << "Enter message: ";
            getline(cin, message);
            cout << "Crypt message: " << ENIGMA.encipher(message) << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else if (command == "clear")
        {
            clearScreen();
        }
        else if (command == "man")
        {
            manual();
        }
        else if (command == "detail")
        {
            details();
        }

        else
        {
            cout << "Command not recognized. Try again." << endl;
        }
    }
    return 0;
}