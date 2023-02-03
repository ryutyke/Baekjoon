#include<iostream>
#include<cmath>
using namespace std;

int n, r, c;
int answer;
int cnt = -1;

void divide(int row, int col, int size)
{
	if (size == 1)
	{
		cnt++;
		if (row == r && col == c) answer = cnt;
		return;
	}

	int half = size / 2;
	if (r >= row && r < row + size && c >= col && c < col + size)
	{
		divide(row, col, half);
		divide(row, col + half, half);
		divide(row + half, col, half);
		divide(row + half, col + half, half);
	}
	else
	{
		cnt += size * size;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> r >> c;
	int size = pow(2, n);
	divide(0, 0, size);
	cout << answer;
	

	return 0;
}