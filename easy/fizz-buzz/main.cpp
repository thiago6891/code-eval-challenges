#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		int f, b, total;
		
		file >> f;
		file >> b;
		file >> total;

		for (int i = 1; i <= total; i++) {
			bool modf = i % f == 0;
			bool modb = i % b == 0;

			if (!modf && !modb) {
				cout << i;
			} else {
				if (modf) cout << 'F';
				if (modb) cout << 'B';
			}

			if (i != total) cout << " ";
		}
		cout << endl;
	}

	return 0;
}