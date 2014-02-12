#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int sum = 0;
			string::iterator it = line.begin();
			while (it != line.end()) {
				char c = *it;
				sum += atoi(&c);
				it++;
			}
			cout << sum << endl;
		}
	}
	return 0;
}