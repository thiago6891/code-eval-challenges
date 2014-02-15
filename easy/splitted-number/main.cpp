#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int operate(string a, string b, string op) {
	int na = atoi(a.c_str());
	int nb = atoi(b.c_str());

	if (op == "+") return na + nb;
	else return na - nb;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			size_t spos = line.find(' ');
			string num = line.substr(0, spos);
			string pattern = line.substr(spos + 1, line.size() - spos - 1);

			// get first operand
			string operand_a;
			string::iterator it = pattern.begin();
			while (*it != '+' && *it != '-') {
				operand_a.push_back(num[*it - 'a']);
				it++;
			}

			string operation;
			operation.push_back(*it);
			it++;

			// get second operand
			string operand_b;
			while (it != pattern.end()) {
				operand_b.push_back(num[*it - 'a']);
				it++;
			}

			int n = operate(operand_a, operand_b, operation);
			cout << n << endl;
		}
	}

	return 0;
}