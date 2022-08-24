#include <iostream>
using namespace std;

void service();
void nQueenCalc(int depth);

int queenOkCount = 0;
int* queen;
int n;

int main() {

	service();

	return 0;
}

void service() {
	cin >> n;
	queen = new int[n];

	nQueenCalc(0);
	cout << queenOkCount << endl;
}

void nQueenCalc(int depth) {
	if (depth == n) {
		queenOkCount++;
		return;
	}

	for (int i = 0; i < n; i++) {

		bool isOkToBeAQueenHere = true;
		for (int j = 0; j < depth; j++) {
			if (queen[j] == i || (queen[j] + depth - j == i) || (queen[j] - depth + j == i)) {
				isOkToBeAQueenHere = false;
				break;
			}
		}
		if (!isOkToBeAQueenHere) continue;

		queen[depth] = i;
		nQueenCalc(depth + 1);
	}
}