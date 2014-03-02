#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class CityBlocksFlyover {
	vector<int> _horizontal;
	vector<int> _vertical;
	void __initVector(vector<int>*, string);
	int __crossedBlocksBetween(int, int);
	double __hPosAt(int);

public:
	CityBlocksFlyover(string);
	int solve();
};

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			CityBlocksFlyover cbf(line);
			cout << cbf.solve() << endl;
		}
	}

	return 0;
}

CityBlocksFlyover::CityBlocksFlyover(string input) {
	size_t p = input.find(' ');
	__initVector(&_vertical, input.substr(0, p));
	__initVector(&_horizontal, input.substr(p + 1, input.size() - p - 1));
}

void CityBlocksFlyover::__initVector(vector<int>* v, string str) {
	// erase the opening and closing parentheses
	str.erase(0, 1);
	str.erase(str.size() - 1, 1);

	// process the rest of the string composed by comma separated integers
	size_t p = str.find(',');
	while (p != string::npos) {
		(*v).push_back(atoi(str.substr(0, p).c_str()));
		str.erase(0, p + 1);
		p = str.find(',');
	}
	(*v).push_back(atoi(str.c_str()));
}

int CityBlocksFlyover::__crossedBlocksBetween(int x1, int x2) {
	// considering the map a 2D space where x1 and x2 are consecutive points in the x-axis 
	// (streets), we must calculate the helicopter position on the y-axis at points x1 and x2 in
	// order to find out how many blocks will be crossed between x1 and x2.
	double y1 = __hPosAt(x1);
	double y2 = __hPosAt(x2);

	// there's always at least one block crossed between two consecutive streets
	int blocksCrossed = 1;
	
	int i = 0;
	while (_horizontal[i] < y2) {
		if (_horizontal[i] > y1) blocksCrossed++;
		i++;
	}

	return blocksCrossed;
}

int CityBlocksFlyover::solve() {
	int blocks = 0;

	for (int i = 1; i < _vertical.size(); i++)
		// calculate crossed blocks between two consecutive streets
		blocks += __crossedBlocksBetween(_vertical[i - 1], _vertical[i]);

	return blocks;
}

double CityBlocksFlyover::__hPosAt(int x) {
	return (double)(_horizontal.back() * x) / _vertical.back();
}