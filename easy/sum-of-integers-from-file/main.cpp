#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	int sum = 0;
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int n = atoi(line.c_str());
			sum += n;
		}
	}
	cout << sum;
	return 0;
}