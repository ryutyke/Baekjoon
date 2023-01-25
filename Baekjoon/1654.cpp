#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{

	int k, n;
	long long cnt, best = 0;
	cin >> k >> n;

	int* array = new int[k];
	for (int i = 0; i < k; i++)
		cin >> array[i];

	sort(array, array + k);

	long long start = 1, end = array[k - 1];

	while (start <= end) 
	{
		long long mid = (start + end) / 2;
		cnt = 0;

		for (int i = 0; i < k; i++) 
			if (array[i] - mid >= 0) 
				cnt += array[i] / mid;

		if (cnt >= n) 
		{
			start = mid + 1;
			best = best > mid ? best : mid;
		}
		else
			end = mid - 1;
	}
	cout << best;

	return 0;
}