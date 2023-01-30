#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

bool line[200000];

int bfs(int subin, int bro)
{
	int cnt = 0;
	queue<int> q;
	line[subin] = 0;
	q.push(subin);

	while (!q.empty())
	{
		size_t q_size = q.size();
		for (int n = 0; n < q_size; n++)
		{
			int subin_pos = q.front();
			q.pop();

			if (subin_pos == bro) { return cnt; }
			int now_x = subin_pos;
			int move_x;

			move_x = now_x + 1;
			if (move_x >= 0 && move_x <= 200000)
			{
				if (line[move_x])
				{
					line[move_x] = 0;
					q.push(move_x);
				}
			}
			move_x = now_x - 1;
			if (move_x >= 0 && move_x <= 200000)
			{
				if (line[move_x])
				{
					line[move_x] = 0;
					q.push(move_x);
				}
			}
			move_x = now_x  * 2;
			if (move_x >= 0 && move_x <= 200000)
			{
				if (line[move_x])
				{
					line[move_x] = 0;
					q.push(move_x);
				}
			}
		}
		cnt++;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int subin, bro;
	cin >> subin >> bro;
	
	for (int i = 0; i < 200000; i++)
		line[i] = 1;
	
	cout << bfs(subin, bro);

	return 0;
}