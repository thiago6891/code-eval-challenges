#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int count[26] = { 0 };

			string::iterator it = line.begin();
			while (it != line.end()) {
				char c = tolower(*it);
				int diff = c - 'a';
				if (0 <= diff && diff <= 25) count[diff]++;
				it++;
			}

			vector<int> vcount(count, count + 26);
			sort(vcount.begin(), vcount.end());

			int sum = 0;
			for (int i = 0; i < vcount.size(); i++) {
				sum += vcount[i] * (i + 1);
			}
			cout << sum << endl;
		}
	}
	return 0;
}