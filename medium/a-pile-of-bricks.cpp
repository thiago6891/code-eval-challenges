#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>
#include <vector>
using namespace std;

typedef struct point {
    int x;
    int y;
    int z;
} Point;

class Area {
protected:
    Point _p1;
    Point _p2;
    
public:
    void setPoints(Point p1, Point p2) { _p1 = p1; _p2 = p2; }
    int width() { return abs(_p1.x - _p2.x); }
    int height() { return abs(_p1.y - _p2.y); }
};

class Brick : public Area {
    int _index;
    
public:
    void setIndex(int index) { _index = index; }
    int depth() { return abs(_p1.z - _p2.z); }
    int index() { return _index; }
    bool fits(Area area) {
        vector<int> v;
        v.push_back(width());
        v.push_back(height());
        v.push_back(depth());
        
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j && v[i] <= area.width() && v[j] <= area.height())
                    return true;
                    
        return false;
    }
};

Area getHole(string str) {
    size_t beg1 = str.find('[');
    size_t mid1 = str.find(',', beg1);
    size_t end1 = str.find(']', mid1);
    size_t beg2 = str.find('[', end1);
    size_t mid2 = str.find(',', beg2);
    size_t end2 = str.find(']', mid2);
    
    Point p1;
    Point p2;
    p1.x = atoi(str.substr(beg1 + 1, mid1 - beg1 - 1).c_str());
    p1.y = atoi(str.substr(mid1 + 1, end1 - mid1 - 1).c_str());
    p2.x = atoi(str.substr(beg2 + 1, mid2 - beg2 - 1).c_str());
    p2.y = atoi(str.substr(mid2 + 1, end2 - mid2 - 1).c_str());
    
    Area hole;
    hole.setPoints(p1, p2);
    return hole;
}

Point getPoint(string str, size_t b, size_t e) {
    size_t sep1 = str.find(',', b);
    size_t sep2 = str.find(',', sep1 + 1);
    
    Point p;
    p.x = atoi(str.substr(b + 1, sep1 - b - 1).c_str());
    p.y = atoi(str.substr(sep1 + 1, sep2 - sep1 - 1).c_str());
    p.z = atoi(str.substr(sep2 + 1, e - sep2 - 1).c_str());
    
    return p;
}

list<Brick> getBricks(string str) {
    list<Brick> bricks;
    
    size_t begin = str.find('(');
    while (begin != string::npos) {
        size_t pos;
        Brick b;
        Point p1, p2;
        
        pos = str.find(' ', begin);
        b.setIndex(atoi(str.substr(begin + 1, pos - begin - 1).c_str()));
        pos++;
        
        p1 = getPoint(str, pos, str.find(']', pos));
        pos = str.find('[', pos + 1);
        p2 = getPoint(str, pos, str.find(']', pos));
        
        b.setPoints(p1, p2);
        
        bricks.push_back(b);
        
        begin = str.find('(', pos);
    }
    
    return bricks;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            Area hole = getHole(line);
            list<Brick> bricks = getBricks(line);
            
            list<int> indexes;
            list<Brick>::iterator it = bricks.begin();
            while (it != bricks.end()) {
                if ((*it).fits(hole)) {
                    indexes.push_back((*it).index());
                }
                it++;
            }
            
            if (!indexes.empty()) {
                indexes.sort();
                list<int>::iterator it = indexes.begin();
                cout << *it;
                it++;
                while (it != indexes.end()) {
                    cout << ',' << *it;
                    it++;
                }
            } else {
                cout << '-';
            }
            cout << endl;
        }
    }
    
    return 0;
}
