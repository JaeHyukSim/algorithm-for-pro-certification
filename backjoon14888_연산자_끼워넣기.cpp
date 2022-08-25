#include<iostream>
using namespace std;

int min(int a, int b);
int max(int a, int b);
void getOperationResultMaxAndMin(int pos, int val);
int operate(int a, int b, int op);

int maxVal = -1111111111, minVal = 1111111111;
int* operands;
int* operators;
int n;

int main() {

	cin >> n;
	operands = new int[n];
	operators = new int[4];
	for (int i = 0; i < n; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	getOperationResultMaxAndMin(0, operands[0]);

	cout << maxVal << "\n" << minVal << endl;

	return 0;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

void getOperationResultMaxAndMin(int pos, int val) {
	if (pos >= n - 1) {
		maxVal = max(maxVal, val);
		minVal = min(minVal, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] == 0) continue;
		operators[i]--;
		getOperationResultMaxAndMin(pos + 1, operate(val, operands[pos + 1], i));
		operators[i]++;
	}
}

int operate(int a, int b, int op) {
	switch (op) {
	case 0: return a + b;
	case 1: return a - b;
	case 2: return a * b;
	case 3: return a / b;
	}
}