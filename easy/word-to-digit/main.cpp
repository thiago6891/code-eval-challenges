#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string get_digit(string str) {
	if (str == "zero")			return "0";
	else if (str == "one")		return "1";
	else if (str == "two")		return "2";
	else if (str == "three")	return "3";
	else if (str == "four")		return "4";
	else if (str == "five")		return "5";
	else if (str == "six")		return "6";
	else if (str == "seven")	return "7";
	else if (str == "eight")	return "8";
	else if (str == "nine")		return "9";
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		
		line.push_back(';');
		while (!line.empty()) {
			int scpos = line.find(';');
			string nstr = line.substr(0, scpos);
			line.erase(0, scpos + 1);
			cout << get_digit(nstr);
		}
		cout << endl;
	}
	return 0;
}