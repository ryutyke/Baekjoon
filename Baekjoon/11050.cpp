#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, result = 1;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		result *= n--;
	}
	for (int i = k; i > 0; i--)
	{
		result /= i;
	}

	cout << result;
	return 0;
}