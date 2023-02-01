#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool chessboard[300][300];

int delta_x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int delta_y[8] = {2, 1, -1, -2, -2, -1, 1, 2};


void reset(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			chessboard[i][j] = false;
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
		int size;
		cin >> size;
		reset(size);
		int pos_x, pos_y, target_x, target_y;
		cin >> pos_x >> pos_y >> target_x >> target_y;

		chessboard[pos_y][pos_x] = true;
		queue<pair<int, int>> q;
		pair<int, int> pos = { pos_x, pos_y };
		q.push(pos);

		int cnt = 0;
		while (!q.empty())
		{
			size_t q_size = q.size();
			for (size_t i = 0; i < q_size; i++)
			{
				pair<int, int> p;
				p = q.front();
				q.pop();
				if(p.first == target_x && p.second == target_y) 
				{
					cout << cnt << "\n";
					for (int j = 0; j < q.size(); j++) { q.pop(); }
					break;
				}
				for (int j = 0; j < 8; j++)
				{
					int next_x = p.first + delta_x[j];
					int next_y = p.second + delta_y[j];
					if (next_x < size && next_x > -1 && next_y < size && next_y > -1) {
						if (chessboard[next_y][next_x] == false)
						{
							chessboard[next_y][next_x] = true;
							pair<int, int> p2;
							p2.first = next_x; p2.second = next_y;
							q.push(p2);
						}
					}
				}
			}
			cnt++;
		}
	}


	return 0;
}