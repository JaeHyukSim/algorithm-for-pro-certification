#include<iostream>
using namespace std;

int max(int a, int b);
void reverseArr(int* arr, int n);

int main() {

	int n;
	cin >> n;
	int* inputArr = new int[n];
	int** lisArr = new int* [n];
	for (int i = 0; i < n; i++) {
		lisArr[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		cin >> inputArr[i];
	}

	lisArr[0][0] = 1; lisArr[0][1] = 1;

	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < n; i++) {
			int maxValue = 1;
			for (int j = 0; j < i; j++) {
				if (inputArr[i] > inputArr[j]) {
					maxValue = max(maxValue, lisArr[j][k] + 1);
				}
			}
			lisArr[i][k] = maxValue;
		}
		reverseArr(inputArr, n);
	}

	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		maxValue = max(maxValue, lisArr[i][0] + lisArr[n - i - 1][1] - 1);
	}

	cout << maxValue << endl;

	return 0;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

void reverseArr(int* arr, int n) {
	for (int i = 0; i < n/2; i++) {
		int tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}