#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int level = 2;
int eat = 0;
int timeCnt = 0;
int result = 0;

bool seen[20][20];
int sea[20][20];

int dx[4] = { 0,-1,1, 0 };
int dy[4] = { -1,0,0, 1 };

queue<pair<int, int>> q;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return (a.first < b.first);
	}
	else
	{
		return a.second < b.second;
	}
}

void bfs()
{
	bool ate = false;
	vector<pair<int, int>> v;
	while (!q.empty())
	{
		ate = false;
		int q_size = (int)q.size();
		for (int u = 0; u < q_size; u++)
		{
			pair<int, int> pos = q.front(); q.pop();
			
			if (sea[pos.second][pos.first] >= 1 && sea[pos.second][pos.first] < level)
			{
				/*cout << "time " << timeCnt << "\n";
				cout << "pos " << pos.first << " " << pos.second << "\n";*/
				eat++;
				ate = true;
				if (level == eat)
				{
					level++;
					eat = 0;
				}
				sea[pos.second][pos.first] = 0;
				result = timeCnt;

				while (!q.empty())
				{
					q.pop();
				}
				memset(seen, 0, sizeof(seen));
				seen[pos.second][pos.first] = true;
				v.clear();
			}

			for (int i = 0; i < 4; i++)
			{
				int nextx = pos.first + dx[i];
				int nexty = pos.second + dy[i];
				if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n)
				{
					if (sea[nexty][nextx] <= level && seen[nexty][nextx] == false)
					{
						seen[nexty][nextx] = true;
						v.push_back(make_pair(nextx, nexty));
					}
				}
			}
			if (ate)
			{
				break; 
			}
		}
		sort(v.begin(), v.end(), compare);
		for (auto& elem : v)
		{
			q.push(elem);
		}
		v.clear();
		timeCnt++;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int startx, starty;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp; cin >> temp;
			sea[i][j] = temp;
			if (temp == 9)
			{
				sea[i][j] = 0;
				startx = j;
				starty = i;
			}
		}
	}
	q.push(make_pair(startx, starty));
	seen[starty][startx] = true;
	
	bfs();

	cout << result;

	return 0;
}