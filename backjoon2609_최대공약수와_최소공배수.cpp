#include<iostream>
using namespace std;

void swap(int& a, int& b);
int getGcd(int a, int b);

int main() {

	int gcd, lcm = 0; // Greatest Common Divisor GCD // Lowest Common Multiple LCM
	int a, b;
	cin >> a >> b;

	gcd = getGcd(a, b);
	lcm = a * b / gcd;

	cout << gcd << "\n" << lcm << endl;

	return 0;
}

int getGcd(int a, int b) {
	if (a < b) swap(a, b);
	int r = a % b;

	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}