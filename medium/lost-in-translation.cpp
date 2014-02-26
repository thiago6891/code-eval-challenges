#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, char> code;

void initCode() {
    code['a'] = 'y';
    code['b'] = 'h';
    code['c'] = 'e';
    code['d'] = 's';
    code['e'] = 'o';
    code['f'] = 'c';
    code['g'] = 'v';
    code['h'] = 'x';
    code['i'] = 'd';
    code['j'] = 'u';
    code['k'] = 'i';
    code['l'] = 'g';
    code['m'] = 'l';
    code['n'] = 'b';
    code['o'] = 'k';
    code['p'] = 'r';
    code['q'] = 'z';
    code['r'] = 't';
    code['s'] = 'n';
    code['t'] = 'w';
    code['u'] = 'j';
    code['v'] = 'p';
    code['w'] = 'f';
    code['x'] = 'm';
    code['y'] = 'a';
    code['z'] = 'q';
    code[' '] = ' ';
}

int main(int argc, char** argv) {
    initCode();
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            for (int i = 0; i < line.size(); i++)
                cout << code[line[i]];
            cout << endl;
        }
    }
    
    return 0;
}
