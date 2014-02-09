#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			int labelpos = line.find("\"label\"");
			int sum = 0;
			while (labelpos != string::npos) {
				line.erase(labelpos, 7);

				int idpos = line.find("\"id\": ", labelpos - 12);
				if (idpos == string::npos || idpos > labelpos) {
					labelpos = line.find("\"label\"", labelpos);
					continue;
				}

				int npos = idpos + 6;
				int nsize = line.find(",", npos) - npos;
				string numStr;
				for (int i = 0; i < nsize; i++) numStr.push_back(line[npos + i]);
				sum += atoi(numStr.c_str());
				
				labelpos = line.find("\"label\"", labelpos);
			}
			cout << sum << endl;
		}
	}
	return 0;
}