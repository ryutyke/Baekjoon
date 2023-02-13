#include<iostream>
#include<vector>
using namespace std;


int n, m;
vector<vector<int>> vv;

void dfs(vector<int> v, int num, int cnt)
{
	v.push_back(num);
	if (v.size() == m)
	{
		vv.push_back(v);
		return;
	}
	else
	{
		if (num + 1 > n)
		{
			return;
		}
	}
	
	for (int i = num+1; i <= n; i++)
	{
		dfs(v, i, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	vector<int> v1;
	for (int i = 1; i <= n; i++)
	{
		dfs(v1, i, 0);
	}

	for (vector<int> elem : vv)
	{
		for (int i = 0; i < m; i++)
		{
			cout << elem[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}