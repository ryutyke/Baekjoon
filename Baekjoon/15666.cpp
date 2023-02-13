#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<vector<int>> vv;
vector<int> v;
int* ary;

void BackTracking(int index)
{
	if (v.size() == m)
	{
		vv.push_back(v);
		return;
	}

	else
	{
		for (int i = index; i < n; i++)
		{
			v.push_back(ary[i]);
			BackTracking(i);
			v.pop_back();
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

	sort(ary, ary+n);

	BackTracking(0);

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