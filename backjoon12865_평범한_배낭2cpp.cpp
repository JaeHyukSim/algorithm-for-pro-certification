#include<iostream>

using namespace std;

int max(int a, int b);

int n, k;
pair<int, int>* components;
int bags[101][100001];

int main() {

	cin >> n >> k;
	components = new pair<int, int>[n];

	for (int i = 1; i <= n; i++) {
		cin >> components[i].first >> components[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= components[i].first) bags[i][j] = max(bags[i - 1][j], bags[i - 1][j - components[i].first] + components[i].second);
			else bags[i][j] = bags[i - 1][j];
		}
	}

	cout << bags[n][k] << endl;

	return 0;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}