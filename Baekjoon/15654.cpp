#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int* ary;
bool seen[9];
vector<int> v;

void BackTracking(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ary[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (!seen[i])
		{
			seen[i] = true;
			ary[cnt] = v[i];
			BackTracking(cnt + 1);
			seen[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	ary = new int[m];
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	BackTracking(0);
}