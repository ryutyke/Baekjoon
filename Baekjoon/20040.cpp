#include<iostream>
using namespace std;

int parent[500000];
int result = 0;

int getParent(int n)
{
	if (parent[n] == n) { return n; }
	return parent[n] = getParent(parent[n]);
}

bool unionParent(int a, int b)
{
	int parent_a = getParent(a);
	int parent_b = getParent(b);
	if (parent_a == parent_b) { cout << result; return true; }
	else if (parent_a < parent_b) { parent[parent_b] = parent_a; return false; }
	else if (parent_a > parent_b) { parent[parent_a] = parent_b; return false; }
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		result++;
		int a, b;
		cin >> a >> b;
		if (unionParent(a, b)) { return 0; }
	}
	cout << 0;

	return 0;
}