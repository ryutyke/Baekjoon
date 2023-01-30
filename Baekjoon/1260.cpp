#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

map<int, vector<int>> edges;
map<int, bool> visited;

void bfs(int node)
{
	visited.clear();
	queue<int> q;
	
	visited[node] = true;
	q.push(node);

	while (!q.empty())
	{
		node = q.front();
		q.pop();
		cout << node << " ";
		sort(edges[node].begin(), edges[node].end());
		for (const auto& adj : edges[node])
		{
			if (visited[adj] == false)
			{
				visited[adj] = true;
				q.push(adj);

			}
		}
	}
	cout << "\n";
}

void dfs(int node)
{
	visited.clear();
	stack<int> s;

	s.push(node);

	while (!s.empty())
	{
		node = s.top();
		s.pop();
		if (visited[node] == true) { continue; }
		visited[node] = true;
		cout << node << " ";
		sort(edges[node].begin(), edges[node].end(), greater<>());
		for (const auto& adj : edges[node])
		{
			if (visited[adj] == false)
			{
				s.push(adj);
			}
		}
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, node;
	cin >> n >> m >> node;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	dfs(node);
	bfs(node);

	return 0;
}