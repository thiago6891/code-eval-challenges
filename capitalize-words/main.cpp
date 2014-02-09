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

		int i = 0;
		while (true) {
			if ('a' <= line[i] && line[i] <= 'z') line[i] += DIFF;
			i = line.find(' ', i);
			if (i == -1) break;
			i++;
		}

		cout << line << endl;
	}
	return 0;
}