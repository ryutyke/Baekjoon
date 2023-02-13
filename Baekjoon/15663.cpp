#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int visit[9];
vector<vector<int>> vv;
vector<int> v;
int* ary;

void BackTracking()
{
	if (v.size() == m)
	{
		vv.push_back(v);
		return;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				v.push_back(ary[i]);
				BackTracking();
				visit[i] = false;
				v.pop_back();
			}
		}
	}

}

int main()
{
	cin >> n >> m;

	ary = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}

	BackTracking();

	sort(vv.begin(), vv.end());
	
	vector<vector<int>> result;
	result.push_back(vv[0]);
	size_t vs = vv.size();
	for (int i = 1; i < vs; i++)
	{
		if (vv[i] != vv[i - 1])
		{
			result.push_back(vv[i]);
		}
	}

	for (vector<int> elem : result)
	{
		for (int e : elem)
		{
			cout << e << " ";
		}
		cout << "\n";
	}


	return 0;
}