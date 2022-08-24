#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	int* divisors = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> divisors[i];
	}
	sort(divisors, divisors + n);

	if (n == 1) {
		cout << divisors[0] * divisors[0] << endl;
	}
	else {
		cout << divisors[0] * divisors[n - 1] << endl;
	}

	return 0;
}