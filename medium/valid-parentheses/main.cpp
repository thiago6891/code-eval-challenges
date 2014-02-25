#include <fstream>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool valid(string str) {
    // stores the opening parentheses, brackets and curly braces
    stack<char> openers;
    
    string::iterator it = str.begin();
    while (it != str.end()) {
        char c = *it;
        
        if (c == '(' || c == '{' || c == '[') {
            openers.push(c);
        } else {
            // if there no openers, there's nothing to close
            if (openers.empty()) return false;
            
            // if the closing parentheses, brackets or curly braces
            // don't match, return false
            if ((c == ')' && openers.top() != '(') ||
                (c == '}' && openers.top() != '{') ||
                (c == ']' && openers.top() != '[')) return false;
            
            openers.pop();
        }
        
        it++;
    }
    
    // there should be no openers left to close
    return openers.empty();
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            if (valid(line)) cout << "True";
            else cout << "False";
            cout << endl;
        }
    }
    
    return 0;
}
