#include <iostream>
using namespace std;

int temp[1000001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		temp[i] += i;
		k = i;
		while (k != 0)
		{
			temp[i] += k % 10;
			k /= 10;
		}
	}

	int result = 0;
	for (int i = n; 0 < i; i--)
	{
		if (temp[i] == n) result = i;
	}

	cout << result;

	return 0;
}