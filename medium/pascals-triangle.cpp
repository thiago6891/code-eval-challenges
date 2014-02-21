#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        int depth;
        file >> depth;
        
        // bidimensional array will hold computed values
        int** triangle;
        triangle = new int*[depth];
        for (int i = 0; i < depth; i++)
            triangle[i] = new int[depth];
        
        stringstream ss;
        
        // setting first value of the triangle
        triangle[0][0] = 1;
        ss << triangle[0][0] << " ";
        
        for (int i = 1; i < depth; i++) {
            // setting first value of the i-th row
            triangle[i][0] = 1;
            ss << triangle[i][0] << " ";
            
            // settings values in between
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
                ss << triangle[i][j] << " ";
            }
            
            // setting last value of the i-th row
            triangle[i][i] = 1;
            ss << triangle[i][i] << " ";
        }
        
        string result = ss.str();
        if (!result.empty()) {
            // erasing last ' ' character
            result.erase(result.size() - 1, 1);
            cout << result << endl;
        }
    }
    
    return 0;
}
