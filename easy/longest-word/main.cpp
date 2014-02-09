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
			string result;
			string word;
			string::iterator it = line.begin();
			while (it <= line.end()) {
				if (it != line.end() && *it != ' ') {
					word.push_back(*it);
				} else {
					if (word.size() > result.size()) result = word;
					word.clear();
				}
				if (it == line.end()) break;
				it++;
			}
			cout << result << endl;
		}
	}
	return 0;
}