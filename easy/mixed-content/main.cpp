#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void fillString(string* str, string line, int* it) {
	while (*it < line.size() && line[*it] != ',') {
		(*str).push_back(line[*it]);
		(*it)++;
	}
	(*str).push_back(',');
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		string words;
		string digits;

		for (int i = 0; i < line.size(); i++) {
			if (line[i] - '0' <= 9)
				fillString(&digits, line, &i);
			else
				fillString(&words, line, &i);
		}

		if (!words.empty()) {
			words.erase(words.size() - 1, 1);
			cout << words;
		}
		if (!digits.empty()) {
			digits.erase(digits.size() - 1, 1);
			if (!words.empty()) cout << "|";
			cout << digits;
		}
		cout << endl;
	}
	return 0;
}