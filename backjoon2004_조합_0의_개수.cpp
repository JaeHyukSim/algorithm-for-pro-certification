#include<iostream>
using namespace std;

long long getCountOfDivide(long long num, long long divide);
int min(int a, int b);

int main() {

	long long n, m;
	cin >> n >> m;

	long long five = getCountOfDivide(n, 5) - getCountOfDivide(m, 5) - getCountOfDivide(n - m, 5);
	long long two = getCountOfDivide(n, 2) - getCountOfDivide(m, 2) - getCountOfDivide(n - m, 2);

	cout << min(five, two) << endl;

	return 0;
}

long long getCountOfDivide(long long num, long long divide) {
	long long count = 0;
	long long val = divide;
	while (val <= num) {
		count += (num / val);
		val *= divide;
	}
	return count;
}

int min(int a, int b) {
	if (a > b) return b;
	return a;
}