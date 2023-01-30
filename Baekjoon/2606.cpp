#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class Graph
{
public:
	void add_edge(int from, int to)
	{
		m_edges[from].push_back(to);
	}
	void bfs(int node)
	{
		queue<int> q;
		
		m_visited[node] = true;
		q.push(node);
		
		

		while (!q.empty())
		{
			node = q.front();
			q.pop();

			for (const auto& adj : m_edges[node])
			{
				if (!m_visited[adj])
				{
					m_visited[adj] = true;
					q.push(adj);
				}
			}
		}
	}
	size_t count_visited()
	{
		return m_visited.size();
	}

private:
	map<int, vector<int>> m_edges;
	map<int, bool> m_visited;
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, edges;
	cin >> n >> edges;

	Graph g;

	for (int i = 0; i < edges; i++)
	{
		int from, to;
		cin >> from >> to;
		g.add_edge(from, to);
		g.add_edge(to, from);
	}

	g.bfs(1);

	cout << g.count_visited() - 1;

	return 0;
}