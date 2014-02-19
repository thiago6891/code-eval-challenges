#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void getStrings(string str, string* a, string* b) {
    size_t p = str.find(',');
    (*a) = str.substr(0, p);
    (*b) = str.substr(p + 1, str.size() - 1 - p);
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            string a, b;
            getStrings(line, &a, &b);
            
            size_t p = a.find(b);
            if (p == string::npos || p != a.size() - b.size())
                cout << 0;
            else cout << 1;
            cout << endl;
        }
    }
    
    return 0;
}
