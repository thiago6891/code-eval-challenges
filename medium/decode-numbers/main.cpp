#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int decode_count(string str) {
    if (str.empty()) return 1;
    
    int count = 0;
    count += decode_count(str.substr(1, str.size() - 1));
    
    if (str.size() > 1) {
        if (str[0] == '1' ||
            (str[0] == '2' && '0' <= str[1] && str[1] <= '6')) {
                count += decode_count(str.substr(2, str.size() - 2));
        }
    }
    
    return count;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            int n = decode_count(line);
            cout << n << endl;
        }
    }
    
    return 0;
}
