#include<iostream>
using namespace std;

int main() {

	int n, k;
	const int conRest = 10007;

	int** factorialArr = new int* [1001];
	for (int i = 0; i <= 1000; i++) {
		factorialArr[i] = new int[1001];
	}
	cin >> n >> k;

	factorialArr[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (j == 0 || j == i) factorialArr[i][j] = 1;
			else factorialArr[i][j] = (factorialArr[i - 1][j - 1] + factorialArr[i - 1][j]) % conRest;
		}
	}
	cout << factorialArr[n][k];

	return 0;
}