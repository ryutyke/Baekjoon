#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> vv;
bool IsLeft[26];


void dfs1(int root)
{
	cout << char(root + 'A');

	for (int next : vv[root])
	{
		dfs1(next);
	}
}

void dfs2(int root)
{
	int vsize = (int)vv[root].size();
	if (vsize == 0)
	{
		cout << char(root + 'A');
	}
	else if (vsize == 1)
	{
		if (IsLeft[vv[root][0]])
		{
			dfs2(vv[root][0]);
			cout << char(root + 'A');
		}
		else
		{
			cout << char(root + 'A');
			dfs2(vv[root][0]);
		}
	}
	else if (vsize == 2)
	{
		dfs2(vv[root][0]);
		cout << char(root + 'A');
		dfs2(vv[root][1]);
	}
}

void dfs3(int root)
{
	for (int next : vv[root])
	{
		dfs3(next);
	}
	cout << char(root + 'A');
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vv.resize(n);

	for (int i = 0; i < n; i++)
	{
		char from, to1, to2;
		cin >> from >> to1 >> to2;
		if (to1 >= 'A' && to1 <= 'Z')
		{
			IsLeft[to1 - 'A'] = true;
			vv[from - 'A'].push_back(to1 - 'A');
		}
		if (to2 >= 'A' && to2 <= 'Z')
		{
			IsLeft[to2 - 'A'] = false;
			vv[from - 'A'].push_back(to2 - 'A');
		}
	}

	dfs1(0);
	cout << "\n";
	dfs2(0);
	cout << "\n";
	dfs3(0);
	cout << "\n";

	return 0;
}