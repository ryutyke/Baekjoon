#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		a = a * a;
		b = b * b;
		c = c * c;
		if (a >= b && a >= c) (a == b + c ? cout << "right\n" : cout << "wrong\n");
		else if (b >= a && b >= c) (b == a + c ? cout << "right\n" : cout << "wrong\n");
		else (c == a + b ? cout << "right\n" : cout << "wrong\n");
	}

	return 0;
}