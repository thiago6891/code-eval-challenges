#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

char getRomanChar(int n) {
	switch (n) {
	case 1:		return 'I';
	case 5:		return 'V';
	case 10:	return 'X';
	case 50:	return 'L';
	case 100:	return 'C';
	case 500:	return 'D';
	case 1000:	return 'M';
	}
	return ' ';
}

string getRomanNum(int num, int unit) {
	string result;
	int div = (int)(num / 5);
	int mod = num % 5;
	if (mod == 4) {
		result.push_back(getRomanChar(unit));
		result.push_back(getRomanChar((div + 1) * (5 * unit)));
	} else {
		if (div == 1) result.push_back(getRomanChar(5 * unit));
		for (int i = 0; i < mod; i++) result.push_back(getRomanChar(unit));
	}
	return result;
}

string convertToRoman(string num) {
	string result;
	int unit = (int)pow(10, num.size() - 1);
	for (int i = 0; i < num.size(); i++, unit /= 10) {
		char c = num[i];
		result.append(getRomanNum(atoi(&c), unit));
	}
	return result;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (line.length() != 0) {
			cout << convertToRoman(line) << endl;
		}
	}
	file.close();
	return 0;
}