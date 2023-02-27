#include <iostream>
using namespace std;

int N;
int* ChessBoard;

int Result = 0;

bool Check(int y)
{
	for (int PastY = 0; PastY < y; PastY++)
	{
		if (ChessBoard[y] == ChessBoard[PastY])
		{
			return false;
		}
		if (y - PastY == abs(ChessBoard[y] - ChessBoard[PastY]))
		{
			return false;
		}
	}
	return true;
}

void PutQueen(int y)
{
	if (y == N)
	{
		Result++;
		return;
	}

	for (int x = 0; x < N; x++)
	{
		ChessBoard[y] = x;

		if (Check(y))
			PutQueen(y + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> N;
	ChessBoard = new int[N];

	PutQueen(0);

	cout << Result;

	return 0;
}