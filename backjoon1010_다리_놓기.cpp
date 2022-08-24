#include<iostream>
using namespace std;

int main() {

	int** combination = new int* [31];
	for (int i = 0; i < 31; i++) {
		combination[i] = new int[31];
	}
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) combination[i][j] = 1;
			else combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
		}
	}

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int k, n;
		cin >> k >> n;
		cout << combination[n][k] << endl;
	}

	return 0;
}