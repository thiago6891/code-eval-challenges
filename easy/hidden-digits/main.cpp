#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			string result;
			string::iterator it = line.begin();
			while (it != line.end()) {
				if ('0' <= (char)(*it) && (char)(*it) <= '9') result.push_back(*it);
				else if ('a' <= (char)(*it) && (char)(*it) <= 'j') {
					stringstream ss;
					ss << *it - 'a';
					result.append(ss.str());
				}
				it++;
			}
			if (result.size() == 0) result.append("NONE");
			cout << result << endl;
		}
	}
	return 0;
}