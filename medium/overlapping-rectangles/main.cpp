#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Rectangle {
    int _top;
    int _bottom;
    int _left;
    int _right;
    
public:
    void setPoints(int left, int top, int right, int bottom) {
        _left = left;
        _top = top; 
        _right = right; 
        _bottom = bottom;
    }
    
    int getRight() { return this->_right; }
    int getLeft() { return this->_left; }
    int getBottom() { return this->_bottom; }
    int getTop() { return this->_top; }
    
    bool intersects(Rectangle other) {
        if (this->getLeft() > other.getRight() ||
            this->getRight() < other.getLeft() ||
            this->getTop() < other.getBottom() ||
            this->getBottom() > other.getTop()) {
                return false;
        } else return true;
    }
};

vector<int> splitStr(string str) {
    vector<int> result;
    
    while (!str.empty()) {
        size_t p = str.find(',');
        
        string sub;
        if (p == string::npos) {
            sub = str;
            str.clear();
        } else {
            sub = str.substr(0, p);
            str.erase(0, p + 1);
        }
        
        int n = atoi(sub.c_str());
        result.push_back(n);
    }
    
    return result;
}

void createRectangles(string str, Rectangle* a, Rectangle* b) {
    vector<int> numbers = splitStr(str);
    
    (*a).setPoints(
        numbers[0],
        numbers[1],
        numbers[2],
        numbers[3]);
    
    (*b).setPoints(
        numbers[4],
        numbers[5],
        numbers[6],
        numbers[7]);
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while(!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            Rectangle a, b;
            createRectangles(line, &a, &b);
            if (a.intersects(b)) cout << "True";
            else cout << "False";
            cout << endl;
        }
    }
    
    return 0;
}