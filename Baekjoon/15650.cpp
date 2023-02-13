#include <iostream>
using namespace std;

int N, M;
int* val;

void Backtracking(int cnt, int num)
{
	//M���� ����
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << val[i] << " ";
		cout << '\n';

		return;
	}

	for (int i = num; i < N; i++)
	{
		//���� �� ����
		val[cnt] = i + 1;

		//��� �Լ�
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