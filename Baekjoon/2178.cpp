#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

bool maze[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = { 1, 0, -1, 0 };


int bfs(int target_x, int target_y)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	maze[1][1] = 0;
	pair<int, int> temp;
	temp.first = 1; temp.second = 1;
	q.push(temp);

	while (!q.empty())
	{	
		size_t q_size = q.size();
		for (int n = 0; n < q_size; n++)
		{
			temp = q.front();
			q.pop();

			if (temp.first == target_x && temp.second == target_y) { return cnt; }
			int f = temp.first; int s = temp.second;
			for (int i = 0; i < 4; i++)
			{
				int move_x = f + dx[i];
				int move_y = s + dy[i];

				if (!(move_x < 1 || move_x > 100 || move_y < 1 || move_y > 100))
				{
					if (maze[move_y][move_x])
					{
						maze[move_y][move_x] = 0;
						
						temp.first = move_x;
						temp.second = move_y;
						q.push(temp);
					}
				}
			}
		}
		cnt++;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int x, y;
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

	cout << bfs(x, y);


	return 0;
}