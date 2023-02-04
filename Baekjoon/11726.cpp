#include<iostream>
using namespace std;

int result[1001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	result[1] = 1;
	result[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		result[i] = (result[i - 1] + result[i - 2]) % 10007;
	}

	cout << result[n] % 10007;

	return 0;
}