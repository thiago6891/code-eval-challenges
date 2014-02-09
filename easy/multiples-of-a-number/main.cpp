#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void getparams(string line, int* x, int* n) {
	int p = line.find(',');
	(*x) = atoi(line.substr(0, p).c_str());
	line.erase(0, p + 1);
	(*n) = atoi(line.c_str());
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int x, n;
			getparams(line, &x, &n);
			int r = n;
			while (r < x) r += n;
			cout << r << endl;
		}
	}
	return 0;
}