#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b);
void print();

int n, k;
vector<pair<int, int>> bags;
pair<int, int>* items;

int main() {

	cin >> n >> k;
	items = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> items[i].first >> items[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bags.size(); j++) {
			if (bags[j].first >= items[i].first) {
				bags.push_back({ bags[j].first - items[i].first, bags[j].second + items[i].second });
			}
		}
		if (k >= items[i].first) {
			bags.push_back({ k - items[i].first, items[i].second });
		}
		//print();
	}

	int maxValue = 0;
	for (int i = 0; i < bags.size(); i++) {
		maxValue = max(maxValue, bags[i].second);
	}
	cout << maxValue << endl;
}

int max(int a, int b) {
	if (a > b)	return a;
	return b;
}

void print() {
	for (int i = 0; i < bags.size(); i++) {
		cout << bags[i].first << ", " << bags[i].second << endl;
	}
	cout << "----------" << endl;
}