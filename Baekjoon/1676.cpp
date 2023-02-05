#include<iostream>
using namespace std;

int main()
{
	int cnt = 0;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (true)
		{
			if (temp % 5 == 0)
			{
				cnt++;
				temp /= 5;
			}
			else { break; }
		}
	}

	cout << cnt;

	return 0;
}