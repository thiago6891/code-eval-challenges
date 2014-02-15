#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Point {
	double _x;
	double _y;

public:
	void setX(double x) { this->_x = x; }
	double getX() { return this->_x; }
	void setY(double y) { this->_y = y; }
	double getY() { return this->_y; }
	double distanceTo(Point);

	Point operator - (const Point &p) {
		Point r;
		r.setX(_x - p._x);
		r.setY(_y - p._y);
		return r;
	}
};

double Point::distanceTo(Point p) {
	Point vec = (*this) - p;
	return sqrt(pow(vec.getX(), 2) + pow(vec.getY(), 2));
}

class Circle {
	Point _center;
	double _radius;

public:
	void setCenter(Point center) { this->_center = center; }
	void setRadius(double radius) { this->_radius = radius; }
	bool containsPoint(Point p) {
		if (this->_center.distanceTo(p) <= this->_radius)
			return true;
		else return false;
	}
};

void getPoint(string str, string pointName, Point* p) {
	size_t begin, mid, end;
	begin = str.find('(', str.find(pointName));
	mid = str.find(',', begin);
	end = str.find(')', mid);

	string subx, suby;
	subx = str.substr(begin + 1, mid - begin + 1);
	suby = str.substr(mid + 1, end - mid + 1);

	(*p).setX(atof(subx.c_str()));
	(*p).setY(atof(suby.c_str()));
}

void getNum(string str, string numName, double* n) {
	size_t begin, end;
	begin = str.find(':', str.find(numName)) + 2;
	end = str.find(';', begin);

	string sub;
	sub = str.substr(begin, end - begin);

	(*n) = atof(sub.c_str());
}

void getCircle(string str, Circle* c) {
	Point center;
	getPoint(str, "Center", &center);
	(*c).setCenter(center);

	double radius;
	getNum(str, "Radius", &radius);
	(*c).setRadius(radius);
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			Circle c;
			Point p;
			getCircle(line, &c);
			getPoint(line, "Point", &p);
			if (c.containsPoint(p)) cout << "true";
			else cout << "false";
			cout << endl;
		}
	}

	return 0;
}