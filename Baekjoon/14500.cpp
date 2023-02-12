#include<iostream>
using namespace std;

int n, m;

int dx[4] = { 0 , 1, 0 , -1 };
int dy[4] = { 1,  0, -1 , 0 };

int paper[501][501];
int best[501][501];

void dfs(int x, int y, int beforex, int beforey, int cnt, int sum)
{
	if (cnt == 4)
	{
		if (best[y][x] < sum)
		{
			best[y][x] = sum;
		}
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx > 0 && nextx <= n && nexty > 0 && nexty <= m)
			{
				if (nextx != beforex || nexty != beforey)
				{
					dfs(nextx, nexty, x, y, cnt + 1, sum + paper[nexty][nextx]);
				}
			}
		}
	}
}

void mountain(int x, int y)
{
	int top = 0;

	if (x > 1 && x < n && y>0 && y < m)
	{
		int sum = paper[y][x - 1] + paper[y][x] + paper[y][x + 1] + paper[y + 1][x];
		if (top < sum) { top = sum; }
	}
	if (x > 1 && x < n && y>1 && y <= m)
	{
		int sum = paper[y][x - 1] + paper[y][x] + paper[y][x + 1] + paper[y - 1][x];
		if (top < sum) { top = sum; }
	}
	if (x >= 1 && x < n && y>1 && y < m)
	{
		int sum = paper[y-1][x] + paper[y][x] + paper[y+1][x] + paper[y][x+1];
		if (top < sum) { top = sum; }
	}
	if (x > 1 && x <= n && y>1 && y < m)
	{
		int sum = paper[y - 1][x] + paper[y][x] + paper[y + 1][x] + paper[y][x - 1];
		if (top < sum) { top = sum; }
	}

	if (best[y][x] < top) { best[y][x] = top; }
	
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> paper[i][j];
			best[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dfs(j, i, 0, 0, 1, paper[i][j]);
			mountain(j, i);
		}
	}

	int result = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (best[i][j] > result)
			{
				result = best[i][j];
			}
		}
	}

	cout << result;

	return 0;
}