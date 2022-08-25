#include<iostream>
using namespace std;

int main() {

	int a = 2; int b = 1;
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		int tmp = (a + b) % 15746;
		b = a;
		a = tmp;
	}

	if (n == 1) a = 1;
	cout << a;

	return 0;
}