#include<iostream>
using namespace std;

void check(bool** b, int xmax, int ymax, int x, int y)
{
	b[y][x] = 0;
	if (x < xmax - 1 && b[y][x+1] == 1) { check(b, xmax, ymax, x + 1, y); }
	if (x > 0 && b[y][x-1] == 1) { check(b, xmax, ymax, x - 1, y); }
	if (y < ymax - 1 && b[y+1][x] == 1) { check(b, xmax, ymax, x, y + 1); }
	if (y > 0 && b[y-1][x] == 1) { check(b, xmax, ymax, x, y-1); }
	
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int worm = 0;
		int x, y;
		cin >> x >> y;
		bool** b = new bool*[y];
		for (int j = 0; j < y; j++)
		{
			b[j] = new bool[x];
		}

		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				b[j][k] = 0;

		int cab; cin >> cab;
		int cab_x, cab_y;
		for (int j = 0; j < cab; j++)
		{
			cin >> cab_x >> cab_y;
			b[cab_y][cab_x] = 1;
		}

		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
			{
				if (b[j][k] == 1)
				{
					worm++;
					check(b, x, y, k, j);
				}
			}
		for (int j = 0; j < y; j++)
			delete[] b[j];
		delete[] b;

		cout << worm << "\n";
	}

	return 0;
}