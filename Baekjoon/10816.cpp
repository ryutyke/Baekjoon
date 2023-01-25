#include<iostream>
#include<algorithm>
using namespace std;

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
	{
		cout << upper_bound(array, array+n, array2[i]) - lower_bound(array, array + n, array2[i]) << " ";
	}

	return 0;
}