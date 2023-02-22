#include<iostream>
#include<algorithm>
using namespace std;

int result[501][501];
int ary[501][501];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> ary[i][j];
			result[i][j] = 0;
		}
	}

	result[1][0] = ary[1][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			result[i + 1][j] = max(result[i][j] + ary[i + 1][j], result[i + 1][j]);
			result[i + 1][j + 1] = max(result[i][j] + ary[i + 1][j + 1], result[i + 1][j + 1]);
			
		}
	}

	int best = 0;
	for (int i = 0; i < n; i++)
	{
		if (result[n][i] > best)
		{
			best = result[n][i];
		}
	}

	cout << best;

	return 0;
}