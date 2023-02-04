#include<iostream>
#include<vector>
using namespace std;

int n, m;
int seen[1001];
vector<int> edges[1001];
int cnt = 0;
void dfs(int n)
{
	for (size_t i = 0; i < edges[n].size(); i++)
	{
		int next = edges[n][i];
		if (seen[next] == 0)
		{
			seen[next] = 1;
			dfs(next);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		seen[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (seen[i] == 0)
		{
			cnt++;
			seen[i] = 1;
			dfs(i);
		}
	}

	cout << cnt;

	return 0;
}