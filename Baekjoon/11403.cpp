#include<iostream>
using namespace std;

int edges[100][100];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> edges[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (edges[x][i] == 1 && edges[i][y] == 1)
				{
					edges[x][y] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << edges[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}