#include<iostream>
using namespace std;

int main() {
	int a = 1, b = 1;
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int c = a + b;
		a = b; b = c;
	}
	printf("%d %d", a, n - 2);
	return 0;
}