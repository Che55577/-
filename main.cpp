#include <iostream>
#include <string>
using namespace std;

struct Rotor 
{
    string mapping;
    int position;
};

const string ROTORS[] = 
{
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",  
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",  
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ"   
};
const string REFLECTOR = "YRUHQSLDPXNGOKMIEBFZCWVJAT";  

char process_char(char c, const Rotor rotors[], bool reverse) 
{
    if (!reverse) 
    {
        for (int i = 0; i < 3; i++) 
        {
            int index = (c - 'A' + rotors[i].position) % 26;
            c = rotors[i].mapping[index];
        }
    } 
    else 
    {
       
        for (int i = 2; i >= 0; i--) 
        {
            size_t index = rotors[i].mapping.find(c);
            if (index == string::npos) 
            {
                return '?';  
            }
            c = (index - rotors[i].position + 26) % 26 + 'A';
        }
    }
    return c;
}
char enigma_encrypt(char c, Rotor rotors[]) 
{
    if (c == ' ') return 'Z';
    
    if (c < 'A' || c > 'Z') return c;

    c = process_char(c, rotors, false);
    c = REFLECTOR[c - 'A'];
    c = process_char(c, rotors, true);

    rotors[2].position = (rotors[2].position + 1) % 26;  

    return c;
}

int main() {
   
    Rotor rotors[3] = 
    {
        {ROTORS[0], 0},  
        {ROTORS[1], 0},  
        {ROTORS[2], 0}  
    };
    
    string input;
    cout << "請輸入想加密的文字：";
    getline(cin, input);

    
    for (char c : input)
    {
         if ((c < 'A' || c > 'Z') && c != ' ')  
        {
            cout << "只能輸入大寫英文字母" << endl;
            return 0;  
        }
    }

    cout << "加密結果: ";
    for (char c : input) 
    {
        cout << enigma_encrypt(c, rotors);
    }
    cout << endl;

    return 0;
}