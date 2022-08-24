#include<iostream>
#include<map>
using namespace std;

int main() {

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		map<string, int> cloths;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (cloths.find(b) == cloths.end()) {
				cloths.insert({ b, 2 });
			} else {
				cloths[b] += 1;
			}
		}

		int res = 1;
		map<string, int>::iterator iter;
		for (iter = cloths.begin(); iter != cloths.end(); iter++) {
			res *= iter->second;
		}
		cout << res - 1 << endl;

	}

	return 0;
}