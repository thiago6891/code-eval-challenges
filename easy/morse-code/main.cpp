#include <fstream>
#include <string>
#include <iostream>
using namespace std;

string getMorse(string* str) {
	size_t p = (*str).find(' ');

	string sub;
	if (p == string::npos) {
		sub = (*str);
		(*str).clear();
	} else {
		if (p == 0) sub = " ";
		else sub = (*str).substr(0, p);
		(*str).erase(0, p + 1);
	}

	return sub;
}

char getChar(string morse) {
	if (morse == ".-") return 'A';
	else if (morse == "-...") return 'B';
	else if (morse == "-.-.") return 'C';
	else if (morse == "-..") return 'D';
	else if (morse == ".") return 'E';
	else if (morse == "..-.") return 'F';
	else if (morse == "--.") return 'G';
	else if (morse == "....") return 'H';
	else if (morse == "..") return 'I';
	else if (morse == ".---") return 'J';
	else if (morse == "-.-") return 'K';
	else if (morse == ".-..") return 'L';
	else if (morse == "--") return 'M';
	else if (morse == "-.") return 'N';
	else if (morse == "---") return 'O';
	else if (morse == ".--.") return 'P';
	else if (morse == "--.-") return 'Q';
	else if (morse == ".-.") return 'R';
	else if (morse == "...") return 'S';
	else if (morse == "-") return 'T';
	else if (morse == "..-") return 'U';
	else if (morse == "...-") return 'V';
	else if (morse == ".--") return 'W';
	else if (morse == "-..-") return 'X';
	else if (morse == "-.--") return 'Y';
	else if (morse == "--..") return 'Z';
	else if (morse == ".----") return '1';
	else if (morse == "..---") return '2';
	else if (morse == "...--") return '3';
	else if (morse == "....-") return '4';
	else if (morse == ".....") return '5';
	else if (morse == "-....") return '6';
	else if (morse == "--...") return '7';
	else if (morse == "---..") return '8';
	else if (morse == "----.") return '9';
	else if (morse == "-----") return '0';
	else if (morse == " ") return ' ';
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		while (!line.empty()) {
			string morse = getMorse(&line);
			cout << getChar(morse);
		}
		cout << endl;
	}
	return 0;
}