#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, block;
	cin >> n >> m >> block;

	int highestfloor = 0;
	long long besttime = 100000000000;
	int result = 0;
	int* ground = new int[n * m];
	for (int i = 0; i < n * m; i++)
	{
		cin >> ground[i];
		if (ground[i] > highestfloor) highestfloor = ground[i];
	}
	
	for (int i = 0; i <= highestfloor; i++)
	{
		int temp = block;
		long long time = 0;
		for (int j = 0; j < n * m; j++)
		{
			if (ground[j] < i)
			{
				temp -= (i - ground[j]);
				time += (i - ground[j]);
			}
			else
			{
				temp += (ground[j] - i);
				time += (2 * (ground[j] - i));
			}
		}
		if (temp >= 0)
		{
			if (time <= besttime)
			{
				besttime = time;
				result = i;
			}
		}
	}
	cout << besttime << " " << result;

	return 0;
}