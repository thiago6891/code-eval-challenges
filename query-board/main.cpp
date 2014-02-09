#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void setRow(int*** board, int i, int x) {
	for (int j = 0; j < 256; j++) 
		(*board)[i][j] = x;
}

void setCol(int*** board, int j, int x) {
	for (int i = 0; i < 256; i++)
		(*board)[i][j] = x;
}

int queryRow(int** board, int i) {
	int sum = 0;
	for (int j = 0; j < 256; j++)
		sum += board[i][j];
	return sum;
}

int queryCol(int** board, int j) {
	int sum = 0;
	for (int i = 0; i < 256; i++)
		sum += board[i][j];
	return sum;
}

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	
	int** board = new int*[256];
	for (int i = 0; i < 256; i++) {
		board[i] = new int[256];
		for (int j = 0; j < 256; j++) {
			board[i][j] = 0;
		}
	}

	while (!file.eof()) {
		string cmd;
		file >> cmd;
		if (cmd == "SetRow") {
			int i, x;
			file >> i;
			file >> x;
			setRow(&board, i, x);
		} else if (cmd == "SetCol") {
			int j, x;
			file >> j;
			file >> x;
			setCol(&board, j, x);
		} else if (cmd == "QueryRow") {
			int i;
			file >> i;
			cout << queryRow(board, i) << endl;
		} else if (cmd == "QueryCol") {
			int j;
			file >> j;
			cout << queryCol(board, j) << endl;
		}
	}
	return 0;
}