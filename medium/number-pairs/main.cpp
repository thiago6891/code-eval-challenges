#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

vector<int> getNums(string str, int* n) {
    vector<int> nums;
    
    while (!str.empty()) {
        size_t p = str.find(',');
        
        string sub;
        if (p == string::npos) {
            p = str.find(';');
            sub = str.substr(0, p);
            str.erase(0, p + 1);
            (*n) = atoi(str.c_str());
            str.clear();
        } else {
            sub = str.substr(0, p);
            str.erase(0, p + 1);
        }
        
        nums.push_back(atoi(sub.c_str()));
    }
    
    return nums;
}

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string line;
        getline(file, line);
        if (!line.empty()) {
            int sum;
            vector<int> nums = getNums(line, &sum);
            
            stringstream ss;
            for (int i = 0; i < nums.size() - 1; i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    int p_sum = nums[i] + nums[j];
                    if (p_sum == sum) 
                        ss << nums[i] << "," << nums[j] << ";";
                    else if (p_sum > sum) break;
                }
            }
            
            string result = ss.str();
            if (result.empty()) cout << "NULL";
            else {
                result.erase(result.size() - 1, 1);
                cout << result;
            }
            cout << endl;
        }
    }
    
    return 0;
}
