#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int* array = new int[n];

	for (int i = 0; i < n; i++)
		cin >> array[i];
	sort(array, array + n);

	int mode = array[0];
	int modecnt = -1;
	int best = 1;
	int temp = 1;
	int sum = 0;
	sum += array[0];
	for (int i = 1; i < n; i++)
	{
		sum += array[i];
		if (array[i] == array[i - 1])
			temp++;
		else
		{
			if (best < temp)
			{
				best = temp;
				mode = array[i-1];
				modecnt = 0;
			}
			else if (best == temp)
			{
				if (modecnt <= 0)
				{
					mode = array[i - 1];
					modecnt++;
				}
			}
			temp = 1;
		}
	}
	if (best < temp)
	{
		mode = array[n - 1];
	}
	else if (best == temp)
	{
		if (modecnt <= 0)
		{
			mode = array[n - 1];
		}
	}

	float f = (float)sum / n;
	f = round(f);
	if (f == -0) f = 0;
	cout << f << "\n" << array[(n-1)/2] << "\n" << mode << "\n" << array[n-1] - array[0];

	return 0;
}