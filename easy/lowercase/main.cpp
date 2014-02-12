#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#define DIFF 'A' - 'a'

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			string::iterator it = line.begin();
			while (it != line.end()) {
				if ('A' <= (char)(*it) && (char)(*it) <= 'Z')
					(*it) -= DIFF;
				cout << *it;
				it++;
			}
			cout << endl;
		}
	}
	return 0;
}