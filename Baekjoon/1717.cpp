#include<iostream>
using namespace std;

int ary[1000001];

int getParent(int a)
{
	if (ary[a] == a) { return a; }
	else { return ary[a] = getParent(ary[a]); }
}

void unionParent(int a, int b)
{
	int parent_a = getParent(a);
	int parent_b = getParent(b);
	parent_a < parent_b ? ary[parent_b] = ary[a] : ary[parent_a] = ary[b];
}

bool checkSame(int a, int b)
{
	return (getParent(a) == getParent(b));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		ary[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 0) { unionParent(a, b); }
		else 
		{
			if (checkSame(a, b)) { cout << "YES\n"; }
			else { cout << "NO\n"; }
		}
	}


	return 0;
}