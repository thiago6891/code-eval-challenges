#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			int n = atoi(line.c_str());
			if (n % 2 == 0) cout << '1';
			else cout << '0';
			cout << endl;
		}
	}
	return 0;
}