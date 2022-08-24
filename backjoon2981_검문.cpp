#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getGcd(int a, int b);

int main() {

	int n;
	cin >> n;
	int* inputedValues = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> inputedValues[i];
	}
	sort(inputedValues, inputedValues + n);

	int gcd = inputedValues[1] - inputedValues[0];
	for (int i = 2; i < n; i++) {
		gcd = getGcd(gcd, inputedValues[i] - inputedValues[i - 1]);
	}

	vector<int> result;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0) {
			result.push_back(i);
			result.push_back(gcd / i);
		}
	}

	result.push_back(gcd);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}

int getGcd(int a, int b) {
	if (a % b == 0) return b;
	return getGcd(b, a % b);
}

