// 그냥 시작지점에서 다익스트라 돌린거 d, point1에서 다익스트라 돌린거 d,  point2에서 다익스트라 돌린거 d2 해서
// min_dist 3개 저장해서    d[p1] + d1[p2] + d2[target]   ,    d[p2] + d2[p1] + d1[target]  이렇게 거리 더하기로 풀어도 될듯 

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int min_dist[2001];

class Node
{
public:
	int pos;
	int distance;
	Node(int _pos, int _distance) :pos(_pos), distance(_distance) {}

	bool operator<(const Node& node) const
	{
		return distance > node.distance;
	}
};
vector<pair<int, int>> edges[2001];
priority_queue<Node, vector<Node>> pq;

void reset_min()
{
	for (int i = 1; i < 2001; i++) { min_dist[i] = (1 << 30); }
}

void dijkstra()
{
	while (!pq.empty())
	{
		Node node = pq.top(); pq.pop();
		for (size_t i = 0; i < edges[node.pos].size(); i++)
		{
			int nextpos = edges[node.pos][i].first;
			int nextdist = node.distance + edges[node.pos][i].second;
			if (min_dist[nextpos] > nextdist)
			{
				min_dist[nextpos] = nextdist;
				Node next(nextpos, nextdist);
				pq.push(next);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int u = 0; u < testcase; u++)
	{
		for (int i = 0; i < 2001; i++)
		{
			edges[i].clear();
		}

		int n, m, t;
		cin >> n >> m >> t;

		int start_pos, point1, point2;
		cin >> start_pos >> point1 >> point2;

		for (int i = 0; i < m; i++)
		{
			int from, to, dist;
			cin >> from >> to >> dist;
			pair<int, int> temp;
			temp.first = to; temp.second = dist;
			edges[from].push_back(temp);
			temp.first = from;
			edges[to].push_back(temp);
		}

		reset_min();
		min_dist[start_pos] = 0;
		Node start(start_pos, 0);
		pq.push(start);
		dijkstra();

		vector<int> target;
		for (int i = 0; i < t; i++)
		{
			int pos; cin >> pos;
			target.push_back(pos);
		}
		vector<int> target_best;
		for (int i : target)
		{
			target_best.push_back(min_dist[i]);
		}

		int point1_min = min_dist[point1];
		int point2_min = min_dist[point2];
		
		reset_min();
		Node p1(point1, point1_min);
		min_dist[point1] = point1_min;
		pq.push(p1);
		dijkstra();

		int p2_min = min_dist[point2];
		reset_min();
		Node p2(point2, p2_min);
		min_dist[point2] = p2_min;
		pq.push(p2);
		dijkstra();

		vector<int> result;
		for (int i = 0; i < t; i++)
		{
			if (min_dist[target[i]] != (1 << 30))
			{
				if (min_dist[target[i]] <= target_best[i]) { result.push_back(target[i]); }
			}
		}

		reset_min();
		p2.pos = point2;
		p2.distance = point2_min;
		min_dist[point2] = point2_min;
		pq.push(p2);
		dijkstra();

		int p1_min = min_dist[point1];
		reset_min();
		p1.pos = point1;
		p1.distance = p1_min;
		min_dist[point1] = p1_min;
		pq.push(p1);
		dijkstra();

		for (int i = 0; i < t; i++)
		{
			if (min_dist[target[i]] != (1 << 30))
			{
				if (min_dist[target[i]] <= target_best[i]) { result.push_back(target[i]); }
			}
		}

		sort(result.begin(), result.end());
		if (result.size() > 0) { cout << result[0] << " "; }
		for (size_t i = 1; i < result.size(); i++)
		{
			if (result[i] != result[i - 1]) { cout << result[i] << " "; }
		}
		cout << "\n";

	}

	return 0;
}