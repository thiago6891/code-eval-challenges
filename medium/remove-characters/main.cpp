#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			// get the sentence and the characters to remove
			size_t p = line.find(',');
			string sentence = line.substr(0, p);
			string toRemove = line.substr(p + 2, line.size() - p - 2);

			// iterate through all characters to remove
			string::iterator it = toRemove.begin();
			while (it != toRemove.end()) {
				// remove all the characters from the sentence
				p = sentence.find((char)(*it));
				while (p != string::npos) {
					sentence.erase(p, 1);
					p = sentence.find((char)(*it));
				}
				
				it++;
			}

			cout << sentence << endl;
		}
	}

	return 0;
}