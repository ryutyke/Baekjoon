#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int cnt; cin >> cnt;
	for (int u = 0; u < cnt; u++)
	{
		int m, n, targetx, targety;
		cin >> m >> n >> targetx >> targety;
		int result = -1;
		int limit = lcm(m, n);

		int x = targetx;
		targety %= n;

		while (x <= limit)
		{
			if (x % n == targety) { result = x; break; }
			x += m;
		}

		cout << result << "\n";
	}

	return 0;
}