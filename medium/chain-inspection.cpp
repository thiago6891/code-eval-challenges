#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef struct pair {
    string name;
    string to;
} Pair;

vector<Pair> getPairs(string str) {
    vector<Pair> result;
    
    while (!str.empty()) {
        size_t d_pos = str.find('-');
        size_t sc_pos = str.find(';');
        
        Pair p;
        p.name = str.substr(0, d_pos);
        if (sc_pos == string::npos) {
            p.to = str.substr(d_pos + 1, str.size() - 1 - d_pos);
            str.clear();
        } else {
            p.to = str.substr(d_pos + 1, sc_pos - 1 - d_pos);
            str.erase(0, sc_pos + 1);
        }
        
        result.push_back(p);
    }
    
    return result;
}

Pair removePair(string p_name, vector<Pair>* pairs) {
    Pair p;
    
    vector<Pair>::iterator it = (*pairs).begin();
    while (it != (*pairs).end()) {
        if ((*it).name == p_name) {
            p = *it;
            (*pairs).erase(it);
            return p;
        }
        it++;
    }
    
    p.name = "NONE";
    p.to = "NONE";
    return p;
}

bool good_chain(vector<Pair> pairs) {
    Pair p;
    p.to = "BEGIN";
    while (p.to != "END") {
        p = removePair(p.to, &pairs);
        if (p.name == "NONE") return false;
    }
    
    if (!pairs.empty()) return false;
    
    return true;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            vector<Pair> pairs = getPairs(line);
            if (good_chain(pairs)) cout << "GOOD";
            else cout << "BAD";
            cout << endl;
        }
    }
    
    return 0;
}
