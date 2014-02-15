#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        int n;
        file >> n;
        
        int ones = 0;
        while (n != 0) {
            ones += n % 2;
            n /= 2;
        }
        
        cout << ones << endl;
    }
    
    return 0;
}