#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int mod(int n, int m) {
	int tmp = (int)(n / m);
	return n - (tmp * m);
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			string::iterator it = line.begin();
			string n;
			string m;
			while (it != line.end()) {
				if (*it == ',') {
					n = m;
					m.clear();
				} else {
					m.push_back(*it);
				}
				it++;
			}
			cout << mod(atoi(n.c_str()), atoi(m.c_str())) << endl;
		}
	}
	return 0;
}