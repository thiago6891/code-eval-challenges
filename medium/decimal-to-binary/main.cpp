#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        int n;
        file >> n;
        
        string result;
        
        if (n == 0) result = "0";
        else
            while (n != 0) {
                stringstream ss;
                ss << n % 2;
                result.insert(0, ss.str());
                n /= 2;
            }
        
        cout << result << endl;
    }
    
    return 0;
}