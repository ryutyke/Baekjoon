#include<iostream>
using namespace std;

bool check(int n)
{
	if (n == 1) return false;

	for (int i = 2; i < n; i++)
	{
		if (n % i != 0) continue;
		else return false;
	}
	return true;
}

int main()
{
	int a, b, cnt = 0;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cin >> b;
		if (check(b)) cnt++;
	}
	cout << cnt;
	return 0;
}