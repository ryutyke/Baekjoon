#include<iostream>
using namespace std;

int ary[100001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	ary[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		ary[i] = temp + ary[i - 1];
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << (ary[b] - ary[a - 1]) << "\n";
	}

	return 0;
}