#include<iostream>
using namespace std;

int tile[1001];

int main()
{
	tile[1] = 1;
	tile[2] = 3;

	for (int i = 3; i <= 1000; i++)
	{
		tile[i] = (tile[i - 1] + tile[i - 2] * 2) % 10007;
	}

	int n;
	cin >> n;
	cout << tile[n];

	return 0;
}