#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int min_time[100001];

class Node
{
public:
	int time;
	int pos;
	Node(int _time, int _pos) :time(_time), pos(_pos) {}

	bool operator<(const Node& node) const
	{
		return time > node.time;
	}
};

priority_queue<Node, vector<Node>> pq;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	for (int i = 0; i < 100001; i++)
	{
		min_time[i] = (1 << 30);
	}

	int subin, bro;
	cin >> subin >> bro;

	Node first(0, subin);
	pq.push(first);
	min_time[subin] = 0;
	while (!pq.empty())
	{
		Node next = pq.top(); pq.pop();
		int next_pos[3] = { next.pos -1, next.pos + 1, next.pos*2 };
		int next_time[3] = { next.time +1 , next.time+1, next.time };
		for (int i = 0; i < 3; i++)
		{
			if (next_pos[i] < 0 || next_pos[i] > 100000) { continue; }
			if (min_time[next_pos[i]] > next_time[i])
			{
				min_time[next_pos[i]] = next_time[i];
				Node temp(next_time[i], next_pos[i]);
				pq.push(temp);
			}
		}
	}

	cout << min_time[bro];

	return 0;
}