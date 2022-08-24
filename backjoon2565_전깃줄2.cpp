#include<iostream>
#include<algorithm>
using namespace std;

int getLis();
int max();

int n;
pair<int, int>* inputElectricWires;

int main() {

	cin >> n;
	inputElectricWires = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> inputElectricWires[i].first >> inputElectricWires[i].second;
	}

	sort(inputElectricWires, inputElectricWires + n);

	cout << n - getLis() << endl;

	return 0;
}

int getLis() {
	int* lisList = new int[n];

	for (int i = 0; i < n; i++) {
		int maxCount = 1;
		for (int j = 0; j < i; j++) {
			if (inputElectricWires[i].second > inputElectricWires[j].second) {
				maxCount = max(maxCount, lisList[j] + 1);
			}
		}
		lisList[i] = maxCount;
	}

	int maxCount = 0;
	for (int i = 0; i < n; i++) {
		maxCount = max(maxCount, lisList[i]);
	}
	return maxCount;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}
