#include<iostream>
#include<algorithm>
using namespace std;

int First_Search(int* array, int start, int end, int m)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		
		if (array[mid] < m)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return start;
}

int Last_Search(int* array, int start, int end, int m)
{
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (array[mid] > m)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;

	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	
	cin >> m;
	int* array2 = new int[m];
	for (int i = 0; i < m; i++)
		cin >> array2[i];

	sort(array, array + n);

	int first, last;

	for (int i = 0; i < m; i++)
	{
		first = First_Search(array, 0, n - 1, array2[i]);
		last = Last_Search(array, 0, n - 1, array2[i]);
		cout << last - first;
		cout << " ";
	}

	return 0;
}