#include<iostream>
using namespace std;

char rgb[100][100];
bool seen[100][100];
bool seen2[100][100];
int n;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y)
{
	int nextx, nexty;
	for (int i = 0; i < 4; i++)
	{
		nextx = x + dx[i];
		nexty = y + dy[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n)
		{
			if ((rgb[nexty][nextx] == rgb[y][x]) && (seen[nexty][nextx] == false))
			{
				seen[nexty][nextx] = true;
				dfs(nextx, nexty);
			}
		}
	}
}

void dfs2(int x, int y)
{
	int nextx, nexty;
	for (int i = 0; i < 4; i++)
	{
		nextx = x + dx[i];
		nexty = y + dy[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n)
		{
			if (seen2[nexty][nextx] == false)
			{
				if (rgb[y][x] == 'R' || rgb[y][x] == 'G')
				{
					if (rgb[nexty][nextx] == 'R' || rgb[nexty][nextx] == 'G')
					{
						seen2[nexty][nextx] = true;
						dfs2(nextx, nexty);
					}
				}
				else
				{
					if (rgb[nexty][nextx] == 'B')
					{
						seen2[nexty][nextx] = true;
						dfs2(nextx, nexty);
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> rgb[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (seen[i][j] == false)
			{
				seen[i][j] = true;
				dfs(j, i);
				cnt++;
			}
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (seen2[i][j] == false)
			{
				seen2[i][j] = true;
				dfs2(j, i);
				cnt2++;
			}
		}
	}

	cout << cnt << " " << cnt2;

	return 0;
}