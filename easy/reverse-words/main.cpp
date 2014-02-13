#include <fstream>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

stack<string> splitWords(string str) {
	stack<string> s;

	while (!str.empty()) {
		size_t p = str.find(' ');

		string sub;
		if (p == string::npos) {
			sub = str;
			str.clear();
		} else {
			sub = str.substr(0, p);
			str.erase(0, p + 1);
		}

		s.push(sub);
	}

	return s;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			stack<string> words = splitWords(line);
			while (words.size() > 1) {
				cout << words.top() << " ";
				words.pop();
			}
			cout << words.top() << endl;
		}
	}
	return 0;
}