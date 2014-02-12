#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

list<int> strtolist(string str) {
	list<int> l;

	while (!str.empty()) {
		size_t p = str.find(";");

		string sub = str.substr(0, p);
		str.erase(0, p + 2);

		p = sub.find(",");
		int distance = atoi(sub.substr(p + 1, sub.size() - p - 1).c_str());
		l.push_back(distance);
	}

	return l;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			list<int> distances = strtolist(line);
			distances.sort();

			list<int>::iterator it = distances.begin();
			int lastDistance = 0;
			while (it != --distances.end()) {
				cout << *it - lastDistance << ",";
				lastDistance = *it;
				it++;
			}
			cout << *it - lastDistance << endl;
		}
	}
	return 0;
}