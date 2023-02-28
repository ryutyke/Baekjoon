#include<iostream>
using namespace std;

int Ary[100000][2];
int Result[100000][2];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int TestCase;
	cin >> TestCase;

	for (; TestCase--;)
	{
		int Col;
		cin >> Col;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				cin >> Ary[j][i];
			}
		}
		Result[0][0] = Ary[0][0];
		Result[0][1] = Ary[0][1];
		Result[1][0] = Ary[0][1] + Ary[1][0];
		Result[1][1] = Ary[0][0] + Ary[1][1];

		for (int i = 2; i < Col; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int ReverseJ = (j + 1) % 2;
				if (Result[i - 2][ReverseJ] > Result[i - 1][ReverseJ])
				{
					Result[i][j] = Ary[i][j] + Result[i - 2][ReverseJ];
				}
				else
				{
					Result[i][j] = Ary[i][j] + Result[i - 1][ReverseJ];
				}
			}
		}
		if (Result[Col-1][0] < Result[Col-1][1])
		{
			cout << Result[Col-1][1] << "\n";
		}
		else
		{
			cout << Result[Col-1][0] << "\n";
		}
	}

	return 0;
}