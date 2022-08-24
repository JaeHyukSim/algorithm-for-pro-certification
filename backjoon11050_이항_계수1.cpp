#include<iostream>
using namespace std;

int getFactorial(int num);

int main() {

	int n, k;
	cin >> n >> k;

	cout << (getFactorial(n) / getFactorial(k) ) / getFactorial(n - k);

	return 0;
}

int getFactorial(int num) {
	if (num == 0) return 1;
	return num * getFactorial(num - 1);
}