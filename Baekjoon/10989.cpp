#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[10001] = { 0 };
	
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a[temp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while (a[i] != 0)
		{
			cout << i << "\n";
			a[i]--;
		}
	}

	return 0;
}