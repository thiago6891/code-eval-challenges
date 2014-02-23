#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> getNums(string str) {
	vector<int> nums;
	size_t comma_pos;

	comma_pos = str.find(',');
	while (comma_pos != string::npos) {
		string sub = str.substr(0, comma_pos);
		nums.push_back(atoi(sub.c_str()));
		str.erase(0, comma_pos + 1);
		comma_pos = str.find(',');
	}
	nums.push_back(atoi(str.c_str()));

	return nums;
}

bool nextCombo(int size, int* x, int* y, int* z, int* w) {
	(*w)++;
	if ((*w) == size) {
		(*z)++;
		if ((*z) == size - 1) {
			(*y)++;
			if ((*y) == size - 2) {
				(*x)++;
				if ((*x) == size - 3) {
					return false;
				} else {
					(*y) = (*x) + 1;
					(*z) = (*y) + 1;
					(*w) = (*z) + 1;
				}
			} else {
				(*z) = (*y) + 1;
				(*w) = (*z) + 1;
			}
		} else {
			(*w) = (*z) + 1;
		}
	}
	return true;
}

int solve(vector<int> nums) {
	if (nums.size() < 4) return 0;

	int x = 0;
	int y = 1;
	int z = 2;
	int w = 3;

	int count = 0;

	do {
		if (nums[x] + nums[y] + nums[z] + nums[w] == 0) count++;
	} while (nextCombo(nums.size(), &x, &y, &z, &w));

	return count;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			vector<int> nums = getNums(line);
			int answer = solve(nums);
			cout << answer << endl;
		}
	}

	return 0;
}