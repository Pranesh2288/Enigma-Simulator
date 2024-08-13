#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Keyboard
{
public:
    string str;
    Keyboard()
    {
        str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    int forward(char letter)
    {
        int signal = str.find(letter);
        return signal;
    }

    char backward(int signal)
    {
        char letter = str[signal];
        return letter;
    }
};

class Plugboard
{
public:
    string left;
    string right;

    Plugboard(vector<pair<char, char>> pairs)
    {
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

    int forward(int signal)
    {
        char letter = right[signal];
        signal = left.find(letter);
        return signal;
    }

    int backward(int signal)
    {
        char letter = left[signal];
        signal = right.find(letter);
        return signal;
    }
};

class Rotor
{
public:
    string left;
    string right;
    char notch;

    Rotor(const string &name)
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

    int forward(int signal)
    {
        char letter = right[signal];
        signal = left.find(letter);
        return signal;
    }

    int backward(int signal)
    {
        char letter = left[signal];
        signal = right.find(letter);
        return signal;
    }

    void show()
    {
        cout << "L: " << left << endl;
        cout << "R: " << right << endl;
        cout << endl;
    }

    void rotate(int n = 1, bool forward = true)
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

    void rotate_to_letter(char letter)
    {
        int n = left.find(letter);
        rotate(n);
    }

    void set_ring(int n)
    {
        rotate(n - 1, false);
        int n_notch = left.find(notch);
        if ((n_notch - n) % 26 >= 0)
            notch = left[(n_notch - n) % 26];
        notch = left[((n_notch - n) % 26 + 26) % 26];
    }
};

class Reflector
{
public:
    string left;
    string right;

    Reflector(const char &name)
    {
        left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (name == 'A')
        {
            right = "EJMZALYXVBWFCRQUONTSPIKHGD";
        }
        else if (name == 'B')
        {
            right = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
        }
        else if (name == 'C')
        {
            right = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
        }
        else
        {
            right = left;
        }
    }

    int reflect(int signal)
    {
        char letter = right[signal];
        signal = left.find(letter);
        return signal;
    }
};

class Enigma : public Keyboard, public Plugboard, public Rotor, public Reflector
{
public:
    Reflector re;
    Rotor r1, r2, r3;
    Plugboard pb;
    Keyboard kb;
    Enigma(char reflector, vector<string> rotors, vector<pair<char, char>> plugboard, vector<char> key, vector<int> rings)
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

    void setKey(vector<char> key)
    {
        r1.rotate_to_letter(key[0]);
        r2.rotate_to_letter(key[1]);
        r3.rotate_to_letter(key[2]);
    }

    void setRings(vector<int> key)
    {
        r1.set_ring(key[0]);
        r2.set_ring(key[1]);
        r3.set_ring(key[2]);
    }

    char encipher(char letter)
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

    string encipher(string message)
    {
        string cipher_text = "";
        for (char letter : message)
            cipher_text += encipher(letter);
        return cipher_text;
    }
};

int main()
{
    Enigma ENIGMA = Enigma('A', {"I", "II", "III"}, {{'A', 'A'}}, {'A', 'A', 'A'}, {1, 1, 1});
    cout << ENIGMA.encipher("VCODLLP") << endl;
    return 0;
}