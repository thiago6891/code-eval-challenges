#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;

string itos(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

string hextodec(string h) {
	int dec = 0;
	for (int i = 0; i < h.size(); i++) {
		int tmp;
		if ('a' <= h[i] && h[i] <= 'f')
			tmp = h[i] - 'a' + 10;
		else
			tmp = h[i] - '0';
		dec += tmp * pow(16, h.size() - 1 - i);
	}
	return itos(dec);
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			cout << hextodec(line) << endl;
		}
	}
	return 0;
}