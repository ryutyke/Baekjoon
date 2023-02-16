#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
���Ϳ� ���� erase(��ġ)�� ����
����Ʈ����[y-x] ����ϰ� root�� �����ϰ� pop
root�� �������� �ο��� ���� [x, root-1] ������ [root+1, y] ����

�ο��� x == y �� ����Ʈ[0] ��� �ϰ� ����Ʈ[0] pop
*/

vector<int> InOrder;
vector<int> PostOrder;

void PreOrder(int start, int end)
{
	int root;
	if (start == end)
	{
		cout << PostOrder[0] << " ";
		root = PostOrder[0];
		PostOrder.erase(PostOrder.begin());
	}
	else
	{
		int temp = end - start;
		cout << PostOrder[temp] << " ";
		root = PostOrder[temp];
		PostOrder.erase(PostOrder.begin() + temp);
	}
	int middle = find(InOrder.begin(), InOrder.end(), root) - InOrder.begin();

	if (start <= middle - 1)
	{
		PreOrder(start, middle - 1);
	}
	if (end >= middle + 1)
	{
		PreOrder(middle + 1, end);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		InOrder.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		PostOrder.push_back(temp);
	}

	PreOrder(0, n-1);

	return 0;
}