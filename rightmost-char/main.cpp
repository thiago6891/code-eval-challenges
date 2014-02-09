#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			char t = line[line.size() - 1];
			line.erase(line.size() - 1, 1);
			int pos = line.rfind(t);
			cout << pos << endl;
		}
	}
	return 0;
}