#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct Point Point;
struct Point {
	int x;
	int y;
};

void getPoints(string line, Point* a, Point* b) {
	int p;
	string str;

	p = line.find(',');
	str = line.substr(1, p - 1);
	(*a).x = atoi(str.c_str());
	line.erase(0, p + 2);

	p = line.find(')');
	str = line.substr(0, p);
	(*a).y = atoi(str.c_str());
	line.erase(0, p + 3);

	p = line.find(',');
	str = line.substr(0, p);
	(*b).x = atoi(str.c_str());
	line.erase(0, p + 2);

	p = line.find(')');
	str = line.substr(0, p);
	(*b).y = atoi(str.c_str());
}

int calculateDistance(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			Point a, b;
			getPoints(line, &a, &b);
			int d = calculateDistance(a, b);
			cout << d << endl;
		}
	}
	return 0;
}