#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> vv[10001];
bool seen[10001];
int diameter[10001];
queue<int> q;
int best = 1;

void bfs()
{
	while (!q.empty())
	{
		int temp = q.front(); q.pop();

		for (pair<int, int> p : vv[temp])
		{
			if (!seen[p.first])
			{
				seen[p.first] = true;
				diameter[p.first] = diameter[temp] + p.second;
				if (diameter[best] < diameter[p.first])
				{
					best = p.first;
				}
				q.push(p.first);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		diameter[i] = 0;

		int from, to, dist;
		cin >> from;
		cin >> to;
		cin >> dist;

		vv[from].push_back(make_pair(to, dist));
		vv[to].push_back(make_pair(from, dist));
	}
	diameter[n] = 0;
	q.push(1);
	seen[1] = true;
	bfs();

	diameter[best] = 0;
	q.push(best);
	for (int i = 1; i <= n; i++)
	{
		seen[i] = false;
	}
	seen[best] = true;
	bfs();

	cout << diameter[best];

	return 0;
}