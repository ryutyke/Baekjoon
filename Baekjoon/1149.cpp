#include<iostream>
#include<algorithm>
using namespace std;

int ary[1001][3];
int dp[1001][3];
int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> ary[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		dp[1][i] = ary[1][i];
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + ary[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + ary[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + ary[i][2];
	}

	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

	

	return 0;
}