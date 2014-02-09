#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int charCount(string str, int n) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (atoi(&c) == n) count++;
	}
	return count;
}

bool numSelfDescribing(string num) {
	for (int i = 0; i < num.size(); i++) {
		char c = num[i];
		int times = atoi(&c);
		if (times != charCount(num, i)) return false;
	}
	return true;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			if (numSelfDescribing(line)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	file.close();
	return 0;
}