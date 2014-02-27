#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        int n;
        file >> n;
        
        if (n == 1) {
            // a sequence of one element is always Jolly, the number should
            // be read in order to be removed from the sequence.
            int disposable;
            file >> disposable;
            cout << "Jolly" << endl;
        } else {
            int last_element;
            int current_element;
            list<int> diffs;
            
            // read the first element in the sequence then iterate from the
            // second until the last element of the sequence, storing the
            // absolute differences of consecutive elements in a list.
            file >> last_element;
            for (int i = 2; i <= n; i++) {
                file >> current_element;
                diffs.push_back(abs(current_element - last_element));
                last_element = current_element;
            }
            
            // order the list and eliminate duplicates
            diffs.sort();
            diffs.unique();
            
            // for the sequence to be considered jolly, the list of absolute
            // differences should contain n - 1 elements, its first element
            // should be 1 and the last element should be n - 1.
            if (diffs.size() == n - 1 &&
                diffs.front() == 1 && 
                diffs.back() == n - 1) cout << "Jolly" << endl;
            else cout << "Not jolly" << endl;
        }
    }
}
