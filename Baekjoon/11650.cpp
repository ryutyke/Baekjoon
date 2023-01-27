#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	else
		return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	pair<int, int>* p = new pair<int, int>[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n, compare);
	
	for (int i = 0; i < n; i++)
	{
		cout << p[i].first << " " << p[i].second << "\n";
	}

	return 0;
}