#include<iostream>
#include<vector>
using namespace std;

int n, r, q;
vector<vector<int>> edges;
int result[100001];
bool seen[100001];

int dfs(int root)
{
	for (int next : edges[root])
	{
		if (!seen[next])
		{
			seen[next] = true;
			result[root] = dfs(next)+ result[root];
		}
	}
	return result[root];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> r >> q;

	edges.resize(n + 1);

	for (int i = 1; i < n; i++)
	{
		int from, to;
		cin >> from >> to;

		result[i] = 1;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
	result[n] = 1;

	seen[r] = true;
	dfs(r);

	for (int i = 0; i < q; i++)
	{
		int temp;
		cin >> temp;
		cout << result[temp] << "\n";
	}


	return 0;
}