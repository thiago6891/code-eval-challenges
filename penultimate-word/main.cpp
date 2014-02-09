#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			string::iterator it = line.end() - 1;
			while (*it != ' ') it--;
			it--;
			string word;
			string::iterator b_it = line.begin();
			while (*it != ' ') {
				word.insert(0, 1, *it);
				if (it == b_it) break;
				it--;
			}
			cout << word << endl;
		}
	}
	file.close();
	return 0;
}