#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int* array, int first, int last, short num, int n)
{
	int mid, sum, best = 0;

	while (first <= last)
	{
		sum = 0;
		if (last > 1000000) 
			first = (last / 1000000) - 1;
		
		mid = (first + last) / 2;

		for (int i = 0; i < num; i++)
		{
			sum += (array[i] / mid);
		}
		if (sum >= n)
		{
			best = mid;
			first = mid + 1;
		}
		else
			last = mid - 1;
	}

	return best;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	short k;
	int n;
	cin >> k >> n;
	int* array = new int[k];

	for (int i = 0; i < k; i++)
		cin >> array[i];

	sort(array, array + k);

	cout << BinarySearch(array, 1, array[k - 1], k, n);

	return 0;
}