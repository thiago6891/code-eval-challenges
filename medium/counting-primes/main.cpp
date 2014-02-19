#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void getNums(string str, int* a, int* b) {
    size_t p = str.find(',');
    (*a) = atoi(str.substr(0, p).c_str());
    (*b) = atoi(str.substr(p + 1, str.size() - 1 - p).c_str());
}

bool is_prime(int n) {
    double nsqrt = sqrt(n);
    for (int i = 2; i <= nsqrt; i++)
        if (n % i == 0) return false;
    return true;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            int a, b;
            getNums(line, &a, &b);
            
            int count = 0;
            for (int i = a; i <= b; i++)
                if (is_prime(i)) count++;
                
            cout << count << endl;
        }
    }
    
    return 0;
}
