#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct node Node;
struct node {
	int n;
	Node* next;
};

Node* createChain(int);

int main(int argc, char** argv) {
	ifstream file(argv[1]);
	while (!file.eof()) {
		string line;
		getline(file, line);
		if (!line.empty()) {
			size_t p = line.find(',');
			int totalPeople = atoi(line.substr(0, p).c_str());
			int nextExecution = atoi(line.substr(p + 1, line.size() - p - 1).c_str());

			// in order to solve this problem, a very simple implementation of a circular list was used,
			// we just have to iterate through this list eliminating every m'th node.
			Node* curr = createChain(totalPeople);
			Node* last = curr;
			for (int i = 0; i < totalPeople - 1; i++)
				last = last->next;

			while (last != curr) {
				for (int i = 0; i < nextExecution - 1; i++) {
					curr = curr->next;
					last = last->next;
				}

				cout << curr->n << " ";
				last->next = curr->next;
				Node* tmp = curr;
				curr = curr->next;
				delete tmp;
			}
			cout << curr->n << endl;
			delete curr;
		}
	}

	return 0;
}

// this function creates a circular list of n integers and returns a pointer to its first element
Node* createChain(int n) {
	Node* first = new Node;
	first->n = 0;

	Node* last = first;
	for (int i = 1; i < n; i++) {
		Node* curr = new Node;
		curr->n = i;
		last->next = curr;
		last = curr;
	}

	last->next = first;
	return first;
}