#include<iostream>
#include<algorithm>
using namespace std;

int temp[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i];
	}

	sort(temp, temp + n);

	for (int i = 0; i < n; i++)
	{
		cout << temp[i] << "\n";
	}
	return 0;
}