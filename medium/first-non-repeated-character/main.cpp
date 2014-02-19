#include <fstream>
#include <string>
#include <iostream>
using namespace std;

char first_unique_char(string str) {
    for (int i = 0; i < str.size(); i++) {
        bool found = true;
        for (int j = 0; j < str.size(); j++) {
            if (i != j && str[i] == str[j]) {
                found = false;
                break;
            }
        }
        if (found) return str[i];
    }
    return ' ';
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            char c = first_unique_char(line);
            cout << c << endl;
        }
    }
    
    return 0;
}
