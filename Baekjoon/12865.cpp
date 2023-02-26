#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first > p2.first;
}

map<int, int> m;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		
		vector<pair<int, int>> pv;
		
		for (pair<int,int> elem : m)
		{
			pv.push_back(elem);
		}
		sort(pv.begin(), pv.end(), compare);

		for (pair<int, int> elem : pv)
		{
			if (elem.first + w <= k)
			{
				if (m[elem.first + w] < elem.second + v)
				{
					m[elem.first + w] = elem.second + v;
				}
			}
		}

		if (w <= k)
		{
			if (m[w] < v)
			{
				m[w] = v;
			}
		}
	}

	int best = 0;
	for (pair<int, int> elem : m)
	{
		if (elem.second > best)
		{
			best = elem.second;
		}
	}

	cout << best;

	return 0;
}