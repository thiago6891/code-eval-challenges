#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			string::iterator it = line.begin() + 1;
			string rep;
			string tmp;
			rep.push_back(line[0]);
			while (it != line.end()) {
				if (*it != rep[0]) {
					rep.push_back(*it);
				} else {
					for (int i = 0; i < rep.size(); i++) {
						if (it == line.end()) {
							rep.append(tmp);
							tmp.clear();
							break;
						}
						tmp.push_back(*it);
						it++;
					}
					if (tmp.size() == 0) break;
					if (rep == tmp) break;
					else rep.append(tmp);
				}
				it++;
			}
			cout << rep.size() << endl;
		}
	}
	return 0;
}