#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int seen[20001];
vector<int> edges[20001];
queue<int> q;
void reset_seen(int vertex)
{
	for (int i = 1; i <= vertex; i++)
	{
		seen[i] = -1;
	}
}

void reset_edges(int vertex)
{
	for (int i = 1; i <= vertex; i++)
	{
		edges[i].clear();
	}
}

bool bfs()
{
	while (!q.empty())
	{
		size_t q_size = q.size();
		for (int i = 0; i < q_size; i++)
		{
			int node = q.front(); q.pop();
			for (size_t j = 0; j < edges[node].size(); j++)
			{
				int next_node = edges[node][j];
				if (seen[node] == seen[next_node]) 
				{ 
					cout << "NO\n";
					size_t q_size1 = q.size();
					for (size_t k = 0; k < q_size1; k++)
					{
						q.pop();
					}
					return false; 
				}
				if (seen[next_node] == -1)
				{
					seen[next_node] = ((seen[node] == 0) ? 1 : 0);
					q.push(next_node);
				}
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int num; cin >> num;
	for (int u = 0; u < num; u++)
	{
		int vertex, edge;
		cin >> vertex >> edge;
		
		reset_seen(vertex);
		reset_edges(vertex);

		for (int i = 0; i < edge; i++)
		{
			int from, to;
			cin >> from >> to;
			edges[from].push_back(to);
			edges[to].push_back(from);
		}
		for (int i = 1; i <= vertex; i++)
		{
			if (seen[i] == -1) 
			{ 
				seen[i] = 0;
				q.push(i);
				if (!bfs()) { break; }
			}
			if (i == vertex) { cout << "YES\n"; }
		}
	}

	return 0;
}