#include<iostream>
using namespace std;

int getGcd(int a, int b);

int main() {

	int n;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 1; i < n; i++) {
		int gcd = getGcd(input[0], input[i]);
		cout << input[0] / gcd << "/" << input[i] / gcd << endl;
	}

	return 0;
}

int getGcd(int a, int b) {
	if (a % b == 0) return b;
	return getGcd(b, a % b);
}