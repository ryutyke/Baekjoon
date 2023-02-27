#include<iostream>
using namespace std;

int n;
int result = 0;

void dfs(bool** ary, int cnt, int x, int y)
{
	if (cnt == n) { result++; }
	else
	{
		bool** CantPut = new bool* [n];
		for (int i = 0; i < n; i++)
		{
			CantPut[i] = new bool[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				CantPut[i][j] = ary[i][j];
			}
		}

		CantPut[y][x] = true;
		for (int i = 0; i < n; i++)
		{
			CantPut[y][i] = true;
			CantPut[i][x] = true;
		}

		int TempX = x;
		int TempY = y;
		while (true)
		{
			TempX = TempX - 1;
			TempY = TempY - 1;
			if (TempX >= 0 && TempY >= 0)
			{
				CantPut[TempY][TempX] = true;
			}
			else
			{
				break;
			}
		}
		TempX = x;
		TempY = y;
		while (true)
		{
			TempX = TempX + 1;
			TempY = TempY - 1;
			if (TempX < n && TempY >= 0)
			{
				CantPut[TempY][TempX] = true;
			}
			else
			{
				break;
			}
		}
		TempX = x;
		TempY = y;
		while (true)
		{
			TempX = TempX - 1;
			TempY = TempY + 1;
			if (TempX >= 0 && TempY < n)
			{
				CantPut[TempY][TempX] = true;
			}
			else
			{
				break;
			}
		}
		TempX = x;
		TempY = y;
		while (true)
		{
			TempX = TempX + 1;
			TempY = TempY + 1;
			if (TempX < n && TempY < n)
			{
				CantPut[TempY][TempX] = true;
			}
			else
			{
				break;
			}
		}


		for (int i = y; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (CantPut[i][j] == false)
				{
					dfs(CantPut, cnt+1, j, i);
					CantPut[i][j] = true;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			delete[] CantPut[i];
		}
		delete[] CantPut;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	bool** CantPut = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		CantPut[i] = new bool[n];
		for (int j = 0; j < n; j++)
		{
			CantPut[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(CantPut, 1, j, i);
			CantPut[i][j] = true;
		}
	}
	
	cout << result;

	return 0;
}