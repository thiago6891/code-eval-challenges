#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

int sqr_sum(int n) {
	stringstream ss;
	ss << n;
	string str = ss.str();
	n = 0;
	string::iterator it = str.begin();
	while (it != str.end()) {
		char c = *it;
		n += (int)pow(atoi(&c), 2);
		it++;
	}
	return n;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			list<int> l;
			int n = atoi(line.c_str());
			do {
				l.push_back(n);
				n = sqr_sum(n);
			} while (n != 1 && l.end() == find(l.begin(), l.end(), n));
			if (n == 1) cout << 1;
			else cout << 0;
			cout << endl;
		}
	}
	return 0;
}