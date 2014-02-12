#include <iostream>
#include <cmath>
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

int main() {
	int pcount = 0;
	int sum = 0;
	int n = 2;

	while (pcount != 1000) {
		if (is_prime(n)) {
			sum += n;
			pcount++;
		}
		n++;
	}

	cout << sum;

	return 0;
}