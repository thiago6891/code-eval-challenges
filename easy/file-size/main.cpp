#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1], ios::binary | ios::ate);
	cout << file.tellg();
	return 0;
}