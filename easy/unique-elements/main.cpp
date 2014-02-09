#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <climits>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			int last = INT_MIN;
			string result;

			while (!line.empty()) {
				int p = line.find(',');
				
				int n;
				if (p == string::npos) {
					n = atoi(line.c_str());
					line.clear();
				} else {
					n = atoi(line.substr(0, p).c_str());
					line.erase(0, p + 1);
				}

				if (n != last) {
					stringstream ss;
					ss << n;
					result.append(ss.str());
					result.push_back(',');
					last = n;
				}
			}

			result.erase(result.size() - 1, 1);
			cout << result << endl;
		}
	}
	return 0;
}