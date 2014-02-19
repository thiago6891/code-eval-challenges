#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string str) {
    vector<string> result;
    
    size_t comma_pos = str.find(',');
    result.push_back(str.substr(0, comma_pos));
    result.push_back(str.substr(comma_pos + 1, str.size() - 1 - comma_pos));
    
    return result;
}

void rotate(string* word) {
    char c = (*word)[0];
    (*word).erase(0, 1);
    (*word).push_back(c);
}

bool rotated(vector<string> words) {
    int fword_size = words[0].size();
    
    for (int i = 0; i < fword_size - 1; i++) {
        rotate(&(words[0]));
        if (words[0] == words[1]) return true;
    }
    
    return false;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            vector<string> words = split(line);
            if (rotated(words)) cout << "True";
            else cout << "False";
            cout << endl;
        }
    }
    
    return 0;
}
