#include<iostream>
#include<queue>
using namespace std;

int min_cnt[101];
int moveto[101];
queue<int> q;
int cnt = -1;
void bfs()
{
	while (!q.empty())
	{
		cnt++;
		size_t q_size = q.size();
		for (int i = 0; i < q_size; i++)
		{
			int f = q.front(); q.pop();
			if (f == 100) 
			{
				cout << min_cnt[100];
				return;
			}
			for (int j = 1; j <= 6; j++)
			{
				int next = f + j;
				if (next > 100) { continue; }
				if (moveto[next] != 0)
				{
					if (min_cnt[moveto[next]] > cnt + 1)
					{
						min_cnt[moveto[next]] = cnt + 1;
						q.push(moveto[next]);
					}
				}
				else 
				{
					if (min_cnt[next] > cnt + 1)
					{
						min_cnt[next] = cnt + 1;
						q.push(next);
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	for (int i = 2; i < 101; i++) { moveto[i] = 0; min_cnt[i] = 1 << 30; }

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		int from, to;
		cin >> from >> to;
		moveto[from] = to;
	}
	q.push(1);
	min_cnt[1] = 0;

	bfs();

	return 0;
}