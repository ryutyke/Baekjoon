#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k, sum;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		k = i;
		sum = i;

		while (k != 0)
		{
			sum += k % 10;
			k /= 10;
		}
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << "0";

	return 0;
}