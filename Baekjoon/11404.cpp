#include<iostream>
using namespace std;

#define INF (1<<30)
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
			if (i == j) { dist[i][j] = 0; }
			else { dist[i][j] = INF; }
		}
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, distance;
		cin >> from >> to >> distance;
		if(dist[from][to] > distance) { dist[from][to] = distance; }
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (dist[k][i] == INF || dist[i][j] == INF) { continue; }
				if (dist[k][j] > dist[k][i] + dist[i][j])
				{
					dist[k][j] = dist[k][i] + dist[i][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF) { cout << "0 "; }
			else { cout << dist[i][j] << " "; }
		}
		cout << "\n";
	}

	return 0;
}