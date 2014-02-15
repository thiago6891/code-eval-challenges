#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		int n;
		file >> n;

		int total = 0;
		for (int i = 5; i >= 1; i -= 2) {
			total += n / i;
			n %= i;
		}

		cout << total << endl;
	}

	return 0;
}