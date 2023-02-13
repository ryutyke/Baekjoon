#include <iostream>
using namespace std;

int N, M;
int* val;

void Backtracking(int cnt, int num)
{
	//M개의 개수
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << val[i] << " ";
		cout << '\n';

		return;
	}

	for (int i = num; i < N; i++)
	{
		//수열 값 저장
		val[cnt] = i + 1;

		//재귀 함수
		Backtracking(cnt + 1, i + 1);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	val = new int[N]();

	Backtracking(0, 0);

	return 0;
}