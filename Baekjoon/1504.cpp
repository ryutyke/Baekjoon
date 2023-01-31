#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int min_dist[801];
vector<pair<int, int>> edges[801];

class Node
{
public:
	int cnt;
	int num;

	Node(int _cnt, int _num) :cnt(_cnt), num(_num) {}

	bool operator<(const Node& node) const
	{
		return cnt > node.cnt;
	}
};

priority_queue<Node, vector<Node>> pq;

void resetMinDist()
{
	for (int i = 1; i < 801; i++) { min_dist[i] = (1 << 30); }
}

void makeMinDist()
{
	while (!pq.empty())
	{
		Node current = pq.top(); pq.pop();
		for (size_t i = 0; i < edges[current.num].size(); i++)
		{
			int next_num = edges[current.num][i].first;
			int next_weight = current.cnt + edges[current.num][i].second;
			if (min_dist[next_num] > next_weight)
			{
				min_dist[next_num] = next_weight;
				Node next_node(next_weight, next_num);
				pq.push(next_node);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pair<int, int> temp;
		temp.first = b; temp.second = c;
		edges[a].push_back(temp);
		temp.first = a;
		edges[b].push_back(temp);
	}
	int point1, point2;
	cin >> point1 >> point2;

	int best_result;

	Node start(0, 1);
	pq.push(start);
	
	resetMinDist();
	min_dist[1] = 0;
	makeMinDist();
	int point1_min = min_dist[point1];
	int point2_min = min_dist[point2];
	int last_min = min_dist[n];
	if (point1_min == (1 << 30) || point2_min == (1 << 30) || last_min == (1 << 30)) 
	{ 
		cout << -1;
		return 0;
	}
	
	resetMinDist();
	start.cnt = point1_min;
	start.num = point1;
	min_dist[point1] = point1_min;
	pq.push(start);
	makeMinDist();
	int p2_min = min_dist[point2];

	resetMinDist();
	start.cnt = p2_min;
	start.num = point2;
	pq.push(start);
	min_dist[point2] = p2_min;
	makeMinDist();
	best_result = min_dist[n];

	resetMinDist();
	start.cnt = point2_min;
	start.num = point2;
	pq.push(start);
	min_dist[point2] = point2_min;
	makeMinDist();
	int p1_min = min_dist[point1];

	resetMinDist();
	start.cnt = p1_min;
	start.num = point1;
	pq.push(start);
	min_dist[point1] = p1_min;
	makeMinDist();
	if (best_result > min_dist[n]) { best_result = min_dist[n]; }

	cout << best_result;

	return 0;
}