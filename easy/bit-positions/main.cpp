#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void getParams(string line, int* n, int* p1, int* p2) {
	int p;
	
	p = line.find(',');
	(*n) = atoi(line.substr(0, p).c_str());
	line.erase(0, p + 1);

	p = line.find(',');
	(*p1) = atoi(line.substr(0, p).c_str());
	line.erase(0, p + 1);

	(*p2) = atoi(line.c_str());
}

vector<int> getBinary(int n) {
	vector<int> v;
	while (n != 0) {
		v.push_back(n % 2);
		n /= 2;
	}
	return v;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int n, p1, p2;
			getParams(line, &n, &p1, &p2);
			vector<int> binary = getBinary(n);
			if (binary[p1 - 1] == binary[p2 - 1]) cout << "true";
			else cout << "false";
			cout << endl;
		}
	}
	return 0;
}