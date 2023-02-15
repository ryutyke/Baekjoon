#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool seen[100001];
int parent[100001];
vector<int> vv[100001];
queue<int> q;

void bfs()
{
	while (!q.empty())
	{
		int temp = q.front(); q.pop();
		for (int next : vv[temp])
		{
			if (!seen[next])
			{
				seen[next] = true;
				parent[next] = temp;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		vv[n1].push_back(n2);
		vv[n2].push_back(n1);
	}

	q.push(1);
	seen[1] = true;
	bfs();

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}