#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			vector<int> nums;
			while (line[0] != ':') {
				int p = line.find(' ');
				string str = line.substr(0, p);
				int n = atoi(str.c_str());
				nums.push_back(n);
				line.erase(0, p + 1);
			}

			line.erase(0, 2);
			while (!line.empty()) {
				int p = line.find('-');
				string str = line.substr(0, p);
				int p1 = atoi(str.c_str());
				line.erase(0, p + 1);

				p = line.find(',');
				int p2;
				if (p == string::npos) {
					p2 = atoi(line.c_str());
					line.clear();
				} else {
					str = line.substr(0, p);
					p2 = atoi(str.c_str());
					line.erase(0, p + 2);
				}

				int swap = nums[p1];
				nums[p1] = nums[p2];
				nums[p2] = swap;
			}

			cout << nums[0];
			for (int i = 1; i < nums.size(); i++) {
				cout << " " << nums[i];
			}
			cout << endl;
		}
	}
	return 0;
}