#include<iostream>
using namespace std;
int n, m;
int* ary;

void BackTracking(int num, int cnt)
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

	for (int i = num; i <= n; i++)
	{
		ary[cnt] = i;
		BackTracking(i, cnt + 1);
	}
}

int main()
{
	cin >> n >> m;
	ary = new int[m];

	BackTracking(1, 0);

	delete[] ary;
}