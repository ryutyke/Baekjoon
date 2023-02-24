#include<iostream>
#include<algorithm>
using namespace std;

int ary[1000];
int result[1000];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
		result[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		int best = 0;
		for (int j = 0; j < i; j++)
		{
			if (ary[i] > ary[j])
			{
				if (result[j] > best)
				{
					best = result[j];
				}
			}
		}
		result[i] = best + 1;
	}

	sort(result, result + n);
	cout << result[n - 1];

	return 0;
}