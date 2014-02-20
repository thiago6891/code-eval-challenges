#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <cmath>
using namespace std;

void fill(int*** grid, int* n, string str) {
    (*n) = str[0] - '0';
    
    (*grid) = new int*[*n];
    for (int i = 0; i < *n; i++)
        (*grid)[i] = new int[*n];
    
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            (*grid)[i][j] = str[2 + (2 * (*n) * i) + (2 * j)] - '0';
}

bool validRows(int** grid, int n) {
    for (int i = 0; i < n; i++) {
        list<int> l;
        for (int j = 0; j < n; j++) {
            l.push_back(grid[i][j]);
        }
        l.unique();
        if (l.size() < n) return false;
    }
    return true;
}

bool validCols(int** grid, int n) {
    for (int j = 0; j < n; j++) {
        list<int> l;
        for (int i = 0; i < n; i++) {
            l.push_back(grid[i][j]);
        }
        l.unique();
        if (l.size() < n) return false;
    }
    return true;
}

bool validRegions(int** grid, int n) {
    int nsqrt = sqrt(n);
    for (int i = 0; i < n; i += nsqrt) {
        for (int j = 0; j < n; j += nsqrt) {
            list<int> l;
            for (int x = 0; x < nsqrt; x++) {
                for (int y = 0; y < nsqrt; y++) {
                    l.push_back(grid[i + x][j + y]);
                }
            }
            l.unique();
            if (l.size() < n) return false;
        }
    }
    return true;
}

bool valid(int** grid, int n) {
    return 
        validRows(grid, n) && 
        validCols(grid, n) && 
        validRegions(grid, n);
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            int** grid;
            int n;
            fill(&grid, &n, line);
            
            if (valid(grid, n)) cout << "True";
            else cout << "False";
            cout << endl;
            
            for (int i = 0; i < n; i++)
                delete grid[i];
            delete grid;
        }
    }
    
    return 0;
}
