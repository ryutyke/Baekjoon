#include <iostream>
using namespace std;

#define SWAP(x, y, temp) (temp = x, x = y, y = temp)

int Partition(int* list, int left, int right)
{
	int pivot, temp;
	int first, last;

	pivot = list[left];
	first = left + 1;
	last = right;
	
	while (first <= last)
	{
		while (first <= last && list[first] <= pivot)
			first++;
		while (first <= last && pivot <= list[last])
			last--;
		if (first < last)
			SWAP(list[first], list[last], temp);
	}
	SWAP(list[left], list[last], temp);

	return last;
}

void QuickSort(int* list, int left, int right)
{
	if (left < right)
	{
		int q = Partition(list, left, right);

		QuickSort(list, left, q - 1);
		QuickSort(list, q + 1, right);
	}
}

void FindNum(int* sortedAry, int left, int right, int num)
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
		FindNum(sortedAry, left, mid - 1, num);
	else
		FindNum(sortedAry, mid + 1, right, num);
}

int main()
{
	int size, size2, num;
	cin >> size;

	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> num;
		array[i] = num;
	}

	QuickSort(array, 0, size - 1);

	cin >> size2;
	int* array2 = new int[size2];
	
	for (int i = 0; i < size2; i++)
	{
		cin >> num;
		array2[i] = num;
	}

	for (int i = 0; i < size2; i++)
	{
		FindNum(array, 0, size-1, array2[i]);
	}
	
	return 0;
}