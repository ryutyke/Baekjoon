#include<iostream>
using namespace std;

int white = 0;
int blue = 0;
int n;

void divide(int** ary, int row, int col, int size)
{
	if (size == 1) 
	{ 
		if (ary[row][col] == 0) { white++; }
		else { blue++; }
		return;
	}
	int half = size / 2;
	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (ary[row][col] != ary[i][j])
			{
				divide(ary, row, col, half);
				divide(ary, row, col + half, half);
				divide(ary, row + half, col, half);
				divide(ary, row + half, col + half, half);
				return;
			}
		}
	}
	if (ary[row][col] == 0) { white++; }
	else { blue++; }
	return;
}

int main()
{
	cin >> n;
	int** ary = new int* [n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ary[i][j];
		}
	}

	divide(ary, 0, 0, n);

	cout << white << "\n";
	cout << blue;

	for (int i = 0; i < n; i++) { delete[] ary[i]; }
	delete[] ary;

	return 0;
}