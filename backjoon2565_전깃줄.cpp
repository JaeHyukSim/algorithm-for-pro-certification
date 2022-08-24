#include<iostream>
#include<set>
using namespace std;

int max(int a, int b);

int main() {

	int n;
	cin >> n;
	int** inputArr = new int* [n];
	set<int>* indexSet = new set<int>[n];
	int deletedLineCount = 0;

	for (int i = 0; i < n; i++) {
		inputArr[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		cin >> inputArr[i][0] >> inputArr[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ((inputArr[i][0] < inputArr[j][0] && inputArr[i][1] > inputArr[j][1]) || (inputArr[i][0] > inputArr[j][0] && inputArr[i][1] < inputArr[j][1])) {
				indexSet[i].insert(j);
			}
		}
	}

	while (true) {
		int maxSetSize = 0;
		int maxIndex = 0;
		for (int i = 0; i < n; i++) {
			if (maxSetSize < indexSet[i].size()) {
				maxSetSize = max(maxSetSize, indexSet[i].size());
				maxIndex = i;
			}
		}
		if (maxSetSize == 0) {
			cout << deletedLineCount << endl;
			return 0;
		}

		indexSet[maxIndex].clear();
		for (int i = 0; i < n; i++) {
			indexSet[i].erase(maxIndex);
		}
		deletedLineCount++;
	}

	return 0;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}