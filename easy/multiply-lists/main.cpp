#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> strtovec(string str) {
	vector<int> v;
	size_t p;

	while (!str.empty()) {
		p = str.find(' ');
		
		string tmp;
		if (p == string::npos) {
			tmp = str;
			str.clear();
		} else {
			tmp = str.substr(0, p);
			str.erase(0, p + 1);
		}

		v.push_back(atoi(tmp.c_str()));
	}

	return v;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			size_t p = line.find('|');
			
			string str1 = line.substr(0, p);
			string str2 = line.substr(p + 2, line.size() - p - 1);

			vector<int> list1 = strtovec(str1);
			vector<int> list2 = strtovec(str2);

			stringstream ss;
			for (int i = 0; i < list1.size(); i++) {
				ss << list1[i] * list2[i] << " ";
			}

			string result = ss.str();
			result.erase(result.size() - 1, 1);
			cout << result << endl;
		}
	}
	return 0;
}