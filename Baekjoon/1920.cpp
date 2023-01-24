#include <iostream>
#include <algorithm>
using namespace std;

void BinarySearch(int* sortedAry, int left, int right, int num)
{
	if (left > right)
	{
		cout << "0\n";
		return;
	}

	int mid = (left + right) / 2;

	if (sortedAry[mid] == num)
		cout << "1\n";
	else if (sortedAry[mid] >= num)
		BinarySearch(sortedAry, left, mid - 1, num);
	else
		BinarySearch(sortedAry, mid + 1, right, num);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int size, size2, num;
	cin >> size;

	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> num;
		array[i] = num;
	}

	sort(array, array + size);

	cin >> size2;
	int* array2 = new int[size2];
	
	for (int i = 0; i < size2; i++)
	{
		cin >> num;
		array2[i] = num;
	}

	for (int i = 0; i < size2; i++)
	{
		BinarySearch(array, 0, size-1, array2[i]);
	}
	
	return 0;
}