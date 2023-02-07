#include<iostream>
using namespace std;

int ary[64][64];

bool check(int x, int y, int size)
{
	int first = ary[y][x];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (ary[y+i][x+j] != first)
			{
				return false;
			}
		}
	}
	return true;
}

void result(int x, int y, int size)
{
	int first = ary[y][x];
	if (check(x, y, size))
	{
		cout << first;
	}
	else
	{
		int half = size / 2;
		cout << "(";
		result(x, y, half);
		result(x + half, y, half);
		result(x, y + half, half);
		result(x + half, y + half, half);
		cout << ")";
	}	
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			char temp;
			cin >> temp;
			ary[y][x] = temp - '0';
		}
	}

	result(0, 0, n);

	return 0;
}