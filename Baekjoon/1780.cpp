#include<iostream>
using namespace std;

int ary[2188][2188];

int cnt1 = 0; // -1
int cnt2 = 0; // 0
int cnt3 = 0; // 1

void paper(int x, int y, int size)
{
	int third = size / 3;
	int first = ary[y][x];
	if (size == 1)
	{
		if (first == -1) { cnt1++; }
		else if (first == 0) { cnt2++; }
		else if (first == 1) { cnt3++; }
	}
	else
	{
		for(int i = 0; i <size; i++)
			for (int j = 0; j < size; j++)
			{
				if (ary[y+i][x+j] != first) 
				{
					for(int n = 0; n != size; n += third)
						for (int m = 0; m != size; m += third)
						{
							paper(x + m, y + n, third);
						}
					return;
				}
			}
		if (first == -1) { cnt1++; }
		else if (first == 0) { cnt2++; }
		else if (first == 1) { cnt3++; }
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ary[i][j];
		}
	}
	
	paper(1, 1, n);

	cout << cnt1 << "\n" << cnt2 << "\n" << cnt3;

	return 0;
}