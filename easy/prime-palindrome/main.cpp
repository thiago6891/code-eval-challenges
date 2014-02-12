#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

bool is_prime(int n) {
	double nsqrt = sqrt(n);
	int i = 2;
	while (i <= nsqrt) {
		if (n % i == 0) return false;
		i++;
	}
	return true;
}

bool is_palindrome(int n) {
	stringstream ss;
	ss << n;
	string s = ss.str();
	string::iterator b_it = s.begin();
	string::iterator e_it = s.end(); e_it--;
	while (b_it < e_it) {
		if (*b_it != *e_it) return false;
		b_it++; e_it--;
	}
	return true;
}

int main() {
	int p = 999;
	while (!is_prime(p) || !is_palindrome(p)) p--;
	cout << p;
	return 0;
}