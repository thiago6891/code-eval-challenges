#include <iostream>
using namespace std;

int main() {
	union {
		long l;
		char ca[4];
	} un;

	un.l = 1;

	if (un.ca[0] == 1) cout << "LittleEndian";
	else cout << "BigEndian";

	return 0;
}