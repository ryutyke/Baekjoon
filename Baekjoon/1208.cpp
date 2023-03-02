#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, S;
vector<int> V;
map<int, int> SumCnt;
long long Result = 0;

void DfsLeft(int Index, int Sum)
{
	if (Index == (N / 2))
	{
		SumCnt[Sum]++;
		return;
	}
	DfsLeft(Index + 1, Sum);
	DfsLeft(Index + 1, Sum + V[Index]);
}

void DfsRight(int Index, int Sum)
{
	if (Index == N)
	{
		Result += SumCnt[S - Sum];
		return;
	}
	DfsRight(Index + 1, Sum);
	DfsRight(Index + 1, Sum + V[Index]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		V.push_back(temp);
	}

	DfsLeft(0, 0);
	DfsRight(N / 2, 0);

	if (S == 0)
	{
		Result--;
	}
	cout << Result;

	return 0;
}