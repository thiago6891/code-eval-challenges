#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

bool compare(string a, string b) {
	double na = atof(a.c_str());
	double nb = atof(b.c_str());
	return na < nb;
}

list<string> convertStrToDoubles(string str) {
	list<string> l;

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

		l.push_back(sub);
	}

	return l;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			list<string> numbers = convertStrToDoubles(line);
			numbers.sort(compare);
			list<string>::iterator it = numbers.begin();
			while (it != --numbers.end()) {
				cout << *it << " ";
				it++;
			}
			cout << *it << endl;
		}
	}
	return 0;
}