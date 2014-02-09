#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define DIFF 'A' - 'a'

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			string::iterator it = line.begin();
			string result;
			while (it != line.end()) {
				if ('a' <= (char)(*it) && (char)(*it) <= 'z') *it += DIFF;
				else if ('A' <= (char)(*it) && (char)(*it) <= 'Z') *it -= DIFF;
				result.push_back(*it);
				it++;
			}
			cout << result << endl;
		}
	}
	int i;
	return 0;
}