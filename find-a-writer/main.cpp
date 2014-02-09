#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void pushIntoResult(string* result, string line, string num) {
	int pos = atoi(num.c_str()) - 1;
	(*result).push_back(line[pos]);
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			string result;
			string strNum;
			for (int i = line.find('|') + 2; i < line.size(); i++) {
				if (line[i] != ' ') {
					strNum.push_back(line[i]);
				} else {
					pushIntoResult(&result, line, strNum);
					strNum.clear();
				}
			}
			pushIntoResult(&result, line, strNum);
			cout << result << endl;
		}
	}
	return 0;
}