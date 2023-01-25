#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	sort(array, array+n);

	int start = 0, end = array[n - 1], mid;
	long long sum;
	
	while (start <= end)
	{
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			if (array[i] > mid)
				sum += (array[i] - mid);
		}
		if (sum == m)
		{
			cout << mid;
			return 0;
		}
		else if (sum > m)
			start = mid + 1;
		else
			end = mid - 1;

	}
	cout << end;
	
	return 0;
}