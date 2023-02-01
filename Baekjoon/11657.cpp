#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<int, int>> edges[501];
long long min_dist[501];

int main()
{
	ios::sync_with_stdio(false); cin.tie();
	for (int i = 1; i < 501; i++)
	{
		min_dist[i] = (1 << 30);
	}

	min_dist[1] = 0;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, dist;
		cin >> from >> to >> dist;
		pair<int, int> p = { to, dist };
		edges[from].push_back(p);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (size_t k = 0; k < edges[j].size(); k++)
			{
				int pos_now = j;
				int pos_next = edges[j][k].first;
				int dist = edges[j][k].second;
				if (min_dist[pos_now] != (1 << 30))
				{
					if (min_dist[pos_next] > min_dist[pos_now] + dist)
					{
						min_dist[pos_next] = min_dist[pos_now] + dist;
						if (i == (n - 1))
						{
							cout << -1;
							return 0;
						}
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (min_dist[i] == (1 << 30)) { cout << "-1\n"; }
		else { cout << min_dist[i] << "\n"; }
	}

	return 0;
}