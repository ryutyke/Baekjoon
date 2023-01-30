#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool b_map[25][25];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt;

void bfs(int x, int y, int n)
{
	b_map[y][x] = 0;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (nextx < 0 || nextx > n - 1 || nexty < 0 || nexty > n - 1)
			continue;

		if (b_map[nexty][nextx] == 1)
			bfs(nextx, nexty, n);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			b_map[i][j] = s[j] - '0';
		}
	
	}

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b_map[i][j] == 1)
			{
				cnt = 0;
				bfs(j, i, n);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i : v) { cout << i << "\n"; }


	return 0;
}