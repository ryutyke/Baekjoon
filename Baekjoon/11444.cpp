#include <iostream>
#include <map>
#define DIV 1000000007
using namespace std;

long long fib(long long n);
map<long long, long long> m;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long n;
	cin >> n;
	m.insert(make_pair(0, 0));
	m.insert(make_pair(1, 1));
	cout << fib(n) << '\n';
	return 0;
}

long long fib(long long n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	long long temp1, temp2;
	long long result = 0;
	if (n % 2 == 0) {
		if (m.find(n / 2) == m.end()) temp1 = fib(n / 2);
		else temp1 = m[n / 2];
		if (m.find(n / 2 - 1) == m.end()) temp2 = fib(n / 2 - 1);
		else temp2 = m[n / 2 - 1];
		result = ((2 * temp2 + temp1) % DIV * (temp1 % DIV)) % DIV;
	}
	else {
		if (m.find(n / 2 + 1) == m.end()) temp1 = fib(n / 2 + 1);
		else temp1 = m[n / 2 + 1];
		if (m.find(n / 2) == m.end()) temp2 = fib(n / 2);
		else temp2 = m[n / 2];
		result = (((temp1 * temp1) % DIV) + ((temp2 * temp2) % DIV)) % DIV;
	}
	m.insert(make_pair(n, result));

	return result;
}