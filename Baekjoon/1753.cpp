#include<iostream>
#include<queue>
#include<utility>
using namespace std;

constexpr int INF = 1 << 30;

class Node
{
public:
	int cnt;
	int n;

	Node(int _cnt, int _n) : cnt(_cnt), n(_n) {}

	bool operator<(const Node& node) const
	{
		return cnt > node.cnt;
	}
};

priority_queue<Node, vector<Node>> pq;
vector<pair<int, int>> edges[20001];
int min_dist[20001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 1; i <= v; i++) { min_dist[i] = INF; }

	for (int i = 0; i < e; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		pair<int, int> edge;
		edge.first = to;
		edge.second = weight;
		edges[from].push_back(edge);
	}

	Node start(0, k);
	pq.push(start);
	min_dist[k] = 0;

	while (!pq.empty())
	{
		Node current = pq.top(); pq.pop();

		for (size_t i = 0; i < edges[current.n].size(); i++)
		{
			int next_node = edges[current.n][i].first;
			int next_weight = current.cnt + edges[current.n][i].second;
			if (min_dist[next_node] > next_weight)
			{
				min_dist[next_node] = next_weight;
				Node node(next_weight, next_node);
				pq.push(node);
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (min_dist[i] == INF) { cout << "INF\n"; }
		else { cout << min_dist[i] << "\n"; }
	}


	return 0;
}