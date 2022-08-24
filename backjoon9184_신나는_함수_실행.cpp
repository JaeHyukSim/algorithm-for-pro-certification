#include <iostream>
using namespace std;

int getValueOfFunction(int a, int b, int c);

	int a, b, c;
	int valueOfFunction[110][110][110];
	int dimension = 101;

int main() {


	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			for (int k = 0; k < 110; k++) {
				valueOfFunction[i][j][k] = -987654321;
			}
		}
	}

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return 0;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << getValueOfFunction(a, b, c) << endl;
	}
	return 0;
}

int getValueOfFunction(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	} else if (valueOfFunction[a][b][c] != -987654321) {
		return valueOfFunction[a][b][c];
	} else if (a > 20 || b > 20 || c > 20) {
		valueOfFunction[a][b][c] = getValueOfFunction(20, 20, 20);
	} else if (a < b && b < c) {
		valueOfFunction[a][b][c] = getValueOfFunction(a, b, c - 1) + getValueOfFunction(a, b - 1, c - 1) - getValueOfFunction(a, b - 1, c);
	} else {
		valueOfFunction[a][b][c] = getValueOfFunction(a - 1, b, c) + getValueOfFunction(a - 1, b - 1, c) + getValueOfFunction(a - 1, b, c - 1) - getValueOfFunction(a - 1, b - 1, c - 1);
	}
	return valueOfFunction[a][b][c];
}