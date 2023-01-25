#include<iostream>
#include<algorithm>
using namespace std;

void Search(int* array, int start, int end, int m)
{
	int mid, temp, cnt = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (array[mid] == m)
		{
			cnt++;
			temp = mid;
			while (--temp >= 0)
			{
				if (array[temp] != m)
					break;
				cnt++;
			}
			temp = mid;
			while (++temp <= end)
			{
				if (array[temp] != m)
					break;
				cnt++;
			}
			cout << cnt;
			return;
		}
		else if (array[mid] < m)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << cnt;
	return;
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
	{
		Search(array, 0, n - 1, array2[i]);
		cout << " ";
	}

	return 0;
}