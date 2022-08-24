#include<iostream>

using namespace std;

int max(int a, int b);

int main() {

	int n;
	cin >> n;
	int* inputArr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> inputArr[i];
	}

	int* lst = new int[n];
	lst[0] = 1;
	for (int i = 1; i < n; i++) {
		int maxValue = 1;
		for (int j = 0; j < i; j++) {
			if (inputArr[i] > inputArr[j]) {
				maxValue = max(lst[j] + 1, maxValue);
			}
		}
		lst[i] = maxValue;
	}

	int maxValue = -1;
	for (int i = 0; i < n; i++) {
		maxValue = max(maxValue, lst[i]);
	}
	cout << maxValue << endl;

	return 0;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}