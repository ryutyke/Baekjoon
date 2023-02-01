#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int day = -1;
int tomato[1000][1000];
int x, y;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
queue<pair<int, int>> pq;

void bfs()
{
	while (!pq.empty())
	{
		day++;
		size_t pq_size = pq.size();
		for (size_t i = 0; i < pq_size; i++)
		{
			pair<int, int> toma = pq.front(); pq.pop();
			for (int j = 0; j < 4; j++)
			{
				int next_x = toma.first + dx[j];
				int next_y = toma.second + dy[j];
				if (next_x > -1 && next_x < x && next_y > -1 && next_y < y)
				{
					if (tomato[next_y][next_x] == 0)
					{
						tomato[next_y][next_x] = 1;
						pair<int, int> tomat = { next_x, next_y };
						pq.push(tomat);
					}
				}
			}
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (tomato[i][j] == 0)
			{
				cout << -1;
				return;
			}
		}
	}
	cout << day;
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> x >> y;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			int n;
			cin >> n;
			tomato[i][j] = n;
			if (n == 1)
			{
				pair<int, int> temp = { j, i };
				pq.push(temp);
			}
		}
	}
	if (pq.size() == 0) { cout << -1; }
	else { bfs(); }

	return 0;
}