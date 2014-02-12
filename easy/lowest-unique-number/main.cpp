#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

list<int> strtoilist(string str) {
	list<int> result;
	while (!str.empty()) {
		size_t p = str.find(' ');

		string sub;
		if (p == string::npos) {
			sub = str.substr(0, str.size());
			str.clear();
		} else {
			sub = str.substr(0, p);
			str.erase(0, p + 1);
		}

		int i = atoi(sub.c_str());
		result.push_back(i);
	}
	return result;
}

int findLowestUnique(list<int> l) {
	l.sort();

	while (l.size() > 1) {
		list<int>::iterator it = l.begin();
		int first = *it;
		it++;
		int second = *it;
		if (first == second) {
			l.remove(first);
		} else {
			return first;
		}
	}

	if (l.empty()) return 0;
	else return l.front();
}

int findIndex(int n, list<int> l) {
	list<int>::iterator it = l.begin();
	int index = 0;
	bool found = false;
	while (!found) {
		if (*it == n) found = true;
		index++;
		it++;
	}
	return index;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			list<int> numlist = strtoilist(line);
			int lowestNum = findLowestUnique(numlist);
			int index;
			if (lowestNum != 0) 
				index = findIndex(lowestNum, numlist);
			else index = 0;
			cout << index << endl;
		}
	}
	return 0;
}