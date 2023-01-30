#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int cnt = 0;
vector<int> graph[100001];
vector<bool> seen(100001, false);
vector<int> result(100001, 0);
queue<int> q;

void bfs(int r)
{
	if (seen[r] == true) { return; }

	seen[r] = true;
	cnt++;
	result[r] = cnt;

	for (int adjacent : graph[r]) { q.push(adjacent); }

	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) { sort(graph[i].begin(), graph[i].end()); }

	q.push(r);
	while (!(q.empty()))
	{
		bfs(q.front());
		q.pop();
	}
	for (int i = 1; i <= n; i++) { cout << result[i] << "\n"; }

	return 0;
}