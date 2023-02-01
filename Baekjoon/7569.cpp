#include<iostream>
#include<queue>
using namespace std;

int day = -1;
int tomato[100][100][100];
int x, y, z;
int dx[6] = { 0, 1, 0, -1 ,0 ,0 };
int dy[6] = { -1, 0, 1, 0 , 0, 0 };
int dz[6] = { 0, 0, 0, 0 ,1, -1 };
queue<int*> pq;

void bfs()
{
	while (!pq.empty())
	{
		day++;
		size_t pq_size = pq.size();
		for (size_t i = 0; i < pq_size; i++)
		{
			int* toma = pq.front(); pq.pop();
			for (int j = 0; j < 6; j++)
			{
				int next_x = toma[0] + dx[j];
				int next_y = toma[1] + dy[j];
				int next_z = toma[2] + dz[j];
				if (next_x > -1 && next_x < x && next_y > -1 && next_y < y && next_z > -1 && next_z < z)
				{
					if (tomato[next_z][next_y][next_x] == 0)
					{
						tomato[next_z][next_y][next_x] = 1;
						int* tomat = new int[3];
						tomat[0] = next_x;
						tomat[1] = next_y;
						tomat[2] = next_z;
						pq.push(tomat);
					}
				}
			}
		}
	}

	
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < x; k++)
			{
				if (tomato[i][j][k] == 0)
				{
					cout << -1;
					return;
				}
			}
		}
	}
	cout << day;
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> x >> y >> z;
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < x; k++)
			{
				int n;
				cin >> n;
				tomato[i][j][k] = n;
				if (n == 1)
				{
					int* temp = new int[3];
					temp[0] = k;
					temp[1] = j;
					temp[2] = i;
					pq.push(temp);
				}
			}
		}
	}
	
	if (pq.size() == 0) { cout << -1; }
	else { bfs(); }

	return 0;
}