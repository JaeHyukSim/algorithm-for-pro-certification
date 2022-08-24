#include<iostream>
using namespace std;

long getGcd(long a, long b);
void swap(long& a, long& b);

int main() {

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		long a, b;
		cin >> a >> b;
		cout << a * b / getGcd(a, b) << endl;
	}

	return 0;
}

long getGcd(long a, long b) {
	if (a < b) swap(a, b);
	
	long r = a % b;
	while(r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

void swap(long& a, long& b) {
	long tmp = a;
	a = b;
	b = tmp;
}