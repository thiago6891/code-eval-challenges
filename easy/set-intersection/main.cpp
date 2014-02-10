#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <list>
#include <sstream>
using namespace std;

void addToList(string str, list<int>* l) {
	int n = atoi(str.c_str());
	(*l).push_back(n);
}

list<int> strtolist(string str) {
	list<int> l;
	
	while (!str.empty()) {
		int p = str.find(',');
		string sub;

		if (p == string::npos) {
			sub = str;
			addToList(sub, &l);
			str.clear();
		} else {
			sub = str.substr(0, p);
			addToList(sub, &l);
			str.erase(0, p + 1);
		}
	}

	return l;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int p = line.find(';');
			string line1 = line.substr(0, p);
			string line2 = line.substr(p + 1, line.size() - p - 1);

			list<int> list1 = strtolist(line1);
			list<int> list2 = strtolist(line2);

			list<int>::iterator it1 = list1.begin();
			list<int>::iterator it2 = list2.begin();

			stringstream ss;
			while (it1 != list1.end() && it2 != list2.end()) {
                if (*it2 < *it1) it2++;
                else if (*it1 < *it2) it1++;
                else {
                    ss << *it1 << ",";
    				it1++; it2++;
                }
			}
            
			string str = ss.str();
            // erase comma
			if (!str.empty()) str.erase(str.size() - 1, 1);
			cout << str << endl;
		}
	}
	return 0;
}
