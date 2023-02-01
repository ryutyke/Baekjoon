#include<iostream>
#include<queue>
#include<utility>
#include<string>
using namespace std;

bool maze[1001][1001];
bool seen_without[1001][1001];
bool seen_have[1001][1001];
int x, y;
int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0, 1 , 0, -1 };
struct state
{
	int pos_x;
	int pos_y;
	bool havechance;

};
queue<state> pq;
int cnt = 0;

void bfs()
{
	while (!pq.empty())
	{
		cnt++;
		size_t pq_size = pq.size();
		for (int i = 0; i < pq_size; i++)
		{
			state temp = pq.front(); pq.pop();
			if (temp.pos_x == x && temp.pos_y == y) { cout << cnt; return; }
			for (int j = 0; j < 4; j++)
			{
				int next_x = temp.pos_x + dx[j];
				int next_y = temp.pos_y + dy[j];
				if (next_x > 0 && next_x <= x && next_y > 0 && next_y <= y)
				{
					if (temp.havechance)
					{
						if (maze[next_y][next_x] == 1)
						{
							if (seen_have[next_y][next_x] == false)
							{
								seen_have[next_y][next_x] = true;
								state ns = { next_x, next_y, false };
								pq.push(ns);
							}
						}
						else
						{
							if (seen_have[next_y][next_x] == false)
							{
								seen_without[next_y][next_x] = true;
								seen_have[next_y][next_x] = true;
								state ns = { next_x, next_y, true };
								pq.push(ns);
							}
						}
					}
					else
					{
						if (maze[next_y][next_x] == 0)
						{
							if (seen_without[next_y][next_x] == false)
							{
								seen_without[next_y][next_x] = true;
								state ns = { next_x, next_y, false };
								pq.push(ns);
							}
								
						}
					}
				}
			}
		}
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	
	cin >> y >> x;
	for (int i = 1; i <= y; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= x; j++)
		{
			maze[i][j] = s[j-1] - '0';
		}
	}

	state start = state{ 1, 1, true };
	pq.push(start);
	seen_without[1][1] = true;
	seen_have[1][1] = true;
	bfs();

	return 0;
}