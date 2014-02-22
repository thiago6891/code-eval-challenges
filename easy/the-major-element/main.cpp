#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

void addNumTo(map<string, int>* elems, string key, int* total) {
    int e = (*elems)[key];
    (*elems)[key] = e + 1;
    (*total)++;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            int L = 0;
            map<string, int> elems;
            
            string::iterator it = line.begin();
            string::iterator end = line.end();
            string num;
            while (it != end) {
                char c = *it;
                if (c != ',') {
                    num.push_back(c);
                } else {
                    addNumTo(&elems, num, &L);
                    num.clear();
                }
                it++;
            }
            addNumTo(&elems, num, &L);
            
            string result;
            if (elems.size() > L/2) {
                result = "None";
            } else {
                map<string, int>::iterator it = elems.begin();
                while (it != elems.end()) {
                    if (it->second > L/2) {
                        result.append(it->first);
                        break;
                    }
                    it++;
                }
            }
            
            if (!result.empty()) cout << result;
            else cout << "None";
            cout << endl;
        }
    }
    
    return 0;
}
