#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int c = a%b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	cout << b << "\n";
	return b;
}

void lcm(int a, int b)
{
	cout << (a * b) / gcd(a, b);
	return;
}

int main()
{
	int a, b;
	cin >> a >> b;
	lcm(a, b);

	return 0;
}