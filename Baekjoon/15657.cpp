#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
int* ary;
void BackTracking(int index, int cnt)
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

	else
	{
		for (int i = index; i < n; i++)
		{
			ary[cnt] = v[i];
			BackTracking(i, cnt + 1);
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

	BackTracking(0, 0);

	return 0;
}