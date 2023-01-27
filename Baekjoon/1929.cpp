#include <iostream>
using namespace std;

bool check(int n)
{
	if (n == 1) return false;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (check(i)) cout << i << "\n";
	}

	return 0;
}