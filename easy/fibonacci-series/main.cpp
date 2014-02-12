#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int nthfib(int n) {
	if (n == 0 || n == 1) return n;
	return nthfib(n - 1) + nthfib(n - 2);
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int n = atoi(line.c_str());
			cout << nthfib(n) << endl;
		}
	}
	return 0;
}