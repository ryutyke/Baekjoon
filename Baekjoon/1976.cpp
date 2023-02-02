#include<iostream>
#include<vector>
using namespace std;

bool seen[201];
vector<int> edges[201];

void dfs(int city)
{
	size_t s = edges[city].size();
	for (int i = 0; i < s; i++)
	{
		int next = edges[city][i];
		if (seen[next] == 0)
		{
			seen[next] = 1;
			dfs(next);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			if (temp) { edges[i].push_back(j); edges[j].push_back(i); }
		}
	}
	int first;
	cin >> first;
	seen[first] = true;
	dfs(first);

	for (int i = 1; i < m; i++)
	{
		int dest;
		cin >> dest;
		if (seen[dest] == 0) { cout << "NO"; return 0; }
	}
	cout << "YES";

	return 0;
}
