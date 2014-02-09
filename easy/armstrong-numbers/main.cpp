#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		int sum = 0;
		for (int i = 0; i < line.size(); i++) {
			int digit = line[i] - '0';
			sum += pow(digit, line.size());
		}
		if (sum == atoi(line.c_str())) cout << "True";
		else cout << "False";
		cout << endl;
	}
	return 0;
}