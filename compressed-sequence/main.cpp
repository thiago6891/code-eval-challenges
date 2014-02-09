#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		stringstream ss;
		ss << line;

		int count = 1;
		string last;
		string curr;

		ss >> curr;
		if (ss.eof()) cout << count << " " << curr;
		else {
			last = curr;
			while (!ss.eof()) {
				ss >> curr;
				if (curr == last) count++;
				else {
					cout << count << " " << last << " ";
					count = 1;
					last = curr;
				}
			}
			cout << count << " " << last;
		}

		cout << endl;
	}
	return 0;
}