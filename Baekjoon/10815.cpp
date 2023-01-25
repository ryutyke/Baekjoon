#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int* array, int start, int end, int val)
{	
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (array[mid] == val)
			return 1;
		else if (array[mid] < val)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
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
	
	for (int i = 0; i < m; i++)
		cout << BinarySearch(array, 0, n - 1, array2[i]) << " ";
	
	return 0;
}