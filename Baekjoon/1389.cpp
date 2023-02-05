#include<iostream>
#include<vector>
using namespace std;

vector<int> edges[101];
int dist[101][101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
		dist[from][to] = 1;
		dist[to][from] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{	
				if (x == y) { continue; }

				if (dist[x][i] != 0 && dist[i][y] != 0)
				{
					if (dist[x][y] == 0 || dist[x][y] > dist[x][i] + dist[i][y])
						dist[x][y] = dist[x][i] + dist[i][y];
				}
			}
		}
	}

	int best = 100000;
	int result;
	for (int i = 1; i <= n; i++)
	{
		int friends = 0;
		for (int j = 1; j <= n; j++)
		{
			friends += dist[i][j];
		}
		if (best > friends)
		{
			best = friends;
			result = i;
		}
	}
	cout << result;

	return 0;
}